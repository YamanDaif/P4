//
// Created by Yaman Thif on 2020-05-26.
//

#ifndef P4_LISTA_H
#define P4_LISTA_H


struct node {
    char * key[512];
    char * val[512];
    struct node * next;
    struct node * prev;
};
typedef struct node Node;

void insertNode(Node ** padr, Node * tobeadded);
void removeNode(Node ** padr, Node * toberemoved);
void printNode(Node * p);
void printlist(Node * p);
Node * search(Node * p, char * val[512]);

#endif //P4_LISTA_H
