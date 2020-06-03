//
// Created by Yaman Thif on 2020-05-26.
//

#include "hashfunc.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

extern const int HASHVEKSIZE = 1048576;    // 2 upphöjt till 20 (1 miljon)
//const int HASHVEKSIZE = 2097152     // 2 upphöjt till 21
//const int HASHVEKSIZE = 4194304     // 2 upphöjt till 22'

uint32_t tilpro_hash(const char * s) {
    uint32_t hash = 0;
    size_t i = 0;
    while (s[i] != '\0') {
        hash += s[i++];
        hash += hash << 10;
        hash ^= hash >> 6;
    }
    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 13;

    hash = hash & ( HASHVEKSIZE - 1 );
    return hash;
}

char * get(Node ** hashtable, char * key) {

    int hashIndex = 0;
    hashIndex = tilpro_hash(key);

    while (hashtable[hashIndex] != NULL) {//move in array until an empty

        if (hashtable[hashIndex]->key == key) {
            return hashtable[hashIndex]->val;
        }
        ++hashIndex;//go to next cell

    }

    return NULL;

}

void put(Node ** hashtable, char * key, char * value) {

    int hashIndex = 0;

    Node *newnode = malloc(sizeof(Node));
    strcpy(*newnode->key, key);
    strcpy(*newnode->val, value);
    hashIndex = tilpro_hash(key);

    while (hashtable[hashIndex] != NULL) { //if not empty move to the next place  //&& hashtable[hashIndex]->key != -1)

        ++hashIndex;//go to next cell

    }

    hashtable[hashIndex] = newnode;

}

void init(Node **vek) {

    //memset(vek, '\0', HASHVEKSIZE); //det går inte att Nulla minnet med memset???
    //memset(vek, '\0', HASHVEKSIZE);
    int i;
    for (i =0; i<HASHVEKSIZE; i++) {

        vek[i] = '\0';
    }

    return;
}


///////////////////////////////////////////////////////


//char * get(Node ** hashtable, char * key) {

   // hashIndex = hashCode(key);
    //searchnode = hashtable[hashIndex];

  //  while( searchnode != NULL && searchnode->key != NULL && strcmp( key, searchnode->key ) > 0 ) {
       // ++hashIndex;
  //  }

   // if( searchnode == NULL || searchnode->key == NULL || strcmp( key, searchnode->key ) != 0 ) {
    //    return NULL;

    //} else {
  //      return searchnode->val;
   // }

//}

