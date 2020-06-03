//
// Created by Yaman Thif on 2020-05-26.
//
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "hashfunc.h"

int main() {
    Node  * head = NULL; // the pointer node

    //MakeNode (new,'key','value');
    Node  * new1= malloc(sizeof(Node ));
    strcpy(*new1->key, "ad");
    strcpy(*new1->val, "Adamß");//(Strcpy)to make it a string fits in the node structure

    Node  * new2 = malloc(sizeof(Node ));
    strcpy(*new2->key, "al");
    strcpy(*new2->val, "Alexander");

    Node  * new3 = malloc(sizeof(Node ));
    strcpy(*new3->key, "ya");
    strcpy(*new3->val, "Yaman");

    Node  * new4 = malloc(sizeof(Node ));
    strcpy(*new4->key, "li");
    strcpy(*new4->val, "Linus");

    Node  * new5 = malloc(sizeof(Node ));
    strcpy(*new5->key, "la");
    strcpy(*new5->val, "Lara");




    insertNode (&head, new1);//using Ampersand "&" is to link the address of the pointer
    printNode(search(head,"Adamß")); //to show that search works
    removeNode (&head,new1); //test to remove a single element in the list

    insertNode (&head, new2);
    insertNode (&head, new3);
    insertNode (&head, new4);
    insertNode (&head, new5);

    //removeNode ( &head,new5);//to remove the first elemnt in the list
    //removeNode (&head,new3); //to remove the middle element in the list
    //removeNode (&head,new2); //to remove the the rear element in the list

    printlist(head);//to show that printlist works


}