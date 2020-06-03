//
// Created by Yaman Thif on 2020-05-26.
//
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void insertNode(Node  ** padr, Node  * tobeadded){

    tobeadded->next=*padr;
    tobeadded->prev = NULL;

    if(*padr != NULL){
        (*padr)->prev = tobeadded; //this will link back the pointer to the new Node
    }

    *padr = tobeadded;
}

void removeNode (Node  ** padr, Node  * toberemoved){
    if(toberemoved->prev!=NULL && toberemoved->next!=NULL){
        toberemoved->next->prev = toberemoved->prev;
        toberemoved->prev->next = toberemoved->next;
    }

    if(toberemoved->prev==NULL && toberemoved->next!=NULL){
        toberemoved->next->prev = NULL;
        *padr = toberemoved->next;//(toberemoved is the first element in this case and we should link the pointer to the new first element)
    }

    if(toberemoved->prev!=NULL && toberemoved->next==NULL){
        toberemoved->prev->next = toberemoved->next; //((must be linked to null in order to be excuted))
    }

    if(toberemoved->prev==NULL && toberemoved->next==NULL){
        *padr = NULL; //toberemoved is the only element in the list

    }
    free(toberemoved);
}
//no need to take toberemoved->next == NULL (no point of direct NULL to NULL)
//(no need to change the pointer other than "toberemoved" is the first element, then we should link the pointer to the new first element)


void printNode (Node  * p){ //(p is the current node pointer)
    printf("value: %s\nkey: %s\n",  *p->val, *p->key );
}

void printlist (Node  * p){ //(p is the current node)
    printf("-----lista-----\n");

    Node * currentNode = p;
    printNode(currentNode);
    while(currentNode->next!=NULL){
        *currentNode = *currentNode->next;
        printNode(currentNode);
    }
}


Node  * search(Node  * p, char * val[512]){

    Node * currentNode = p; //setting the current node to the head

    while(1){
        if(strcmp(*currentNode->val, *val)==0){
            return currentNode;
        }
        else if(currentNode->next!=NULL){
            currentNode = currentNode->next;
        }
        else{
            return NULL;
        }
    }
}