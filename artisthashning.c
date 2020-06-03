//
// Created by Yaman Thif on 2020-05-26.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashfunc.h"
#include "hashfunc.c"

extern const int HASHVEKSIZE;

struct artist {
    char artistid[20];
    char artistname[400];
    char songtitle[300];
    double length;
    int year;
};

typedef struct artist Artist;
//  Läser artister från filename och lägger dem i artistarray
//  returnerar antalet inlästa artister
int readartists(char * filename, Artist * artistarray) {
    char linebuffer[425];

    FILE * fil = fopen(filename, "r");

    int currentartist = 0;

    while (fgets (linebuffer, 425, fil) != NULL) {

        Artist * artist = artistarray + currentartist;

        int i = 0;
        int j = 0;
        // kolumner är TAB-separerade
        while (linebuffer[i] != '\t')
            i++;

        strncpy(artist -> artistid, linebuffer, j);

        i += 1;
        j = i;
        while (linebuffer[i] != '\t')
            i++;

        strncpy(artist -> artistname, linebuffer + j, i - j);

        i += 1;
        j = i;
        while (linebuffer[i] != '\t')
            i++;

        strncpy(artist -> songtitle, linebuffer + j, i - j);

        i += 1;
        // atof - array to float
        artist -> length = atof(linebuffer + i);

        while (linebuffer[i] != '\t')
            i++;

        i += 1;
        // atoi - array to integer
        artist -> year = atoi(linebuffer + i);

        currentartist += 1;
    }
    return currentartist;
}


int main() {

    Artist * artister = malloc(sizeof(Artist) * 1000000);
    Node ** myhashvek = malloc(sizeof(Node *) * HASHVEKSIZE);
    //init(myhashvek);

    // calloc är ett alternativ till malloc som initierar vektorn till noll
    //   Artist * artister = calloc(1000000, sizeof(Artist));

    int antalartister = readartists("sang-artist-data.txt", artister);

    int i = 0;
    for(int i = 0; i < antalartister; i += 1) {
        put(myhashvek, artister[i].artistname, artister[i].songtitle);

        //printf("artist: %s\n  songtitle: %s\n  length: %f\n",
              // artister[i].artistname, artister[i].songtitle, artister[i].length, artister[i].year);
    }

    free(artister);
    return 0;
}
