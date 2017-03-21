
//  slime_list_nodes.c
//  Slime ADT x
//  [16/03/2017]

#include <stdio.h>
#include <stdlib.h>
#include "slime_list_nodes_access.h"

struct ll_node_ {
    void *data;
    struct ll_node_ *next;
};

ll_node *ll_nodeCreate(void) {
    ll_node *newNode = (ll_node *)malloc(sizeof(ll_node));
    if (newNode == NULL) {
        printf("Error! Failed to create a new ll_node!\n");
        exit(EXIT_FAILURE); }
    ll_nodeSetData(newNode, NULL);
    ll_nodeSetNext(newNode, NULL);
    return newNode;
}

void ll_nodeDestroy(ll_node *node) {
    if (node == NULL) {
        printf("Error! ll_node has already been freed?\n");
        exit(EXIT_FAILURE); }
    free(node);
    node = NULL;
}

void *ll_nodeGetData(ll_node *node) {
    if (node == NULL) {
        printf("Error! Tried to get data from a NULL ll_node!\n");
        exit(EXIT_FAILURE);
    } else {
        return node->data;
    }
}

void ll_nodeSetData(ll_node *node, void *data) {
    if (node == NULL) {
        printf("Error! Tried to set data of a NULL ll_node!\n");
        exit(EXIT_FAILURE); }
    node->data = data;
}

ll_node *ll_nodeGetNext(ll_node *node) {
    if (node == NULL) {
        printf("Error! Tried to get the node succeding a NULL ll_node!\n");
        exit(EXIT_FAILURE); }
    return node->next;
}

void ll_nodeSetNext(ll_node *node, ll_node *next) {
    if (node == NULL) {
        printf("Error! Tried to set the node succeding a NULL ll_node!\n");
        exit(EXIT_FAILURE); }
    node->next = next;
}
