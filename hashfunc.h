
#ifndef tproHASHFUNC_H
#define tproHASHFUNC_H

#include <stdint.h>
#include "lista.h"    // en headerfil för en modifierad dubbellänkad lista p3

uint32_t tilpro_hash(const char * s) ;

void put(Node ** hashtable, char * key, char * value);

char * get(Node ** hashtable, char * key);

void init(Node ** vek);

#endif