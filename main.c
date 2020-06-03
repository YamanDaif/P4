#include <stdio.h>
#include "hashfunc.h"
#include <stdlib.h>

extern const int HASHVEKSIZE;

int main() {
    Node ** myhashvek = malloc(sizeof(Node *) * HASHVEKSIZE);
    init(myhashvek);

    put(myhashvek, "Adam", "123321");
    char * s = get(myhashvek, "Adam");
    printf("Adam -> value = %s expecting Adam\n", s);

}
