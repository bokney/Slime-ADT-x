
//  slime_list_nodes.c
//  Slime ADT x
//  [16/03/2017]

#include <stdio.h>
#include <stdlib.h>
#include "slime_list_nodes.h"

struct llnode_ {
    void *data;
    struct llnode_ *next;
};

llnode *llnodeCreate(void) {
    llnode *newNode = (llnode *)malloc(sizeof(llnode));
    if (newNode == NULL) {
        printf("Error! Failed to create a new llnode!\n");
        exit(EXIT_FAILURE); }
    llnodeSetData(newNode, NULL);
    llnodeSetNext(newNode, NULL);
    return newNode;
}

void llnodeDestroy(llnode *node) {
    if (node == NULL) {
        printf("Error! llnode has already been freed?\n");
        exit(EXIT_FAILURE); }
    free(node);
    node = NULL;
}

void *llnodeGetData(llnode *node) {
    if (node == NULL) {
        printf("Error! Tried to get data from a NULL llnode!\n");
        exit(EXIT_FAILURE);
    } else {
        return node->data;
    }
}

void llnodeSetData(llnode *node, void *data) {
    if (node == NULL) {
        printf("Error! Tried to set data of a NULL llnode!\n");
        exit(EXIT_FAILURE); }
    node->data = data;
}

llnode *llnodeGetNext(llnode *node) {
    if (node == NULL) {
        printf("Error! Tried to get the node succeding a NULL llnode!\n");
        exit(EXIT_FAILURE); }
    return node->next;
}

void llnodeSetNext(llnode *node, llnode *next) {
    if (node == NULL) {
        printf("Error! Tried to set the node succeding a NULL llnode!\n");
        exit(EXIT_FAILURE); }
    node->next = next;
}
