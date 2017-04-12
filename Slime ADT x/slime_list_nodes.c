
//  slime_list_nodes.c
//  Slime ADT x
//  [16/03/2017]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slime_list_nodes_access.h"
#include "slime_errors.h"

#define LL_CREATE_FAILURE       "Failed to allocate memory for new ll_node!"
#define LL_DESTROY_FAILURE      "Failed to destroy an ll_node! It's NULL!"

ll_node *spare = NULL;

ll_node *ll_nodeCreate(void) {
    ll_node *newNode;
    if (spare != NULL) {
        newNode = spare;
        spare = spare->next;
    } else {
        newNode = (ll_node *)malloc(sizeof(ll_node));
        if (newNode == NULL) errorReport(LL_CREATE_FAILURE, true);
    }
    newNode->data = NULL;
    newNode->next = NULL;
    return newNode;
}

void ll_nodeDestroy(ll_node *node) {
    if (node == NULL) errorReport(LL_DESTROY_FAILURE, true);
    node->data = NULL;
    node->next = spare;
    spare = node;
}

void ll_nodeDestroyAllSpare(void) {
    ll_node *byebye;
    while (spare != NULL) {
        byebye = spare;
        spare = spare->next;
        free(byebye);
    }
}
