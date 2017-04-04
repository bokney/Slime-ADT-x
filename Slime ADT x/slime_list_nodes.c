
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
#define LL_ACCESS_FAILURE       "Failed to retrieve ll_node!"

#define LL_SET_DATA_FAILURE     "Error! Tried to set data from a NULL ll_node"
#define LL_SET_NEXT_FAILURE     "Error! Tried to set the node following a NULL ll_node"

#define LL_GET_DATA_FAILURE     "Error! Tried to get data from a NULL ll_node"
#define LL_GET_NEXT_FAILURE     "Error! Tried to get the node following a NULL ll_node"

struct ll_node_ {
    void *data;
    struct ll_node_ *next;
};

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
    ll_nodeSetData(newNode, NULL);
    ll_nodeSetNext(newNode, NULL);
    return newNode;
}

void ll_nodeDestroy(ll_node *node) {
    if (node == NULL) errorReport(LL_DESTROY_FAILURE, true);
    node->data = NULL;
    node->next = spare;
    spare = node;
}

void *ll_nodeGetData(ll_node *node) {
    if (node == NULL) errorReport(LL_GET_DATA_FAILURE, true);
    return node->data;
}

void ll_nodeSetData(ll_node *node, void *data) {
    if (node == NULL) errorReport(LL_SET_DATA_FAILURE, true);
    node->data = data;
}

ll_node *ll_nodeGetNext(ll_node *node) {
    if (node == NULL) errorReport(LL_GET_NEXT_FAILURE, true);
    return node->next;
}

void ll_nodeSetNext(ll_node *node, ll_node *next) {
    if (node == NULL) errorReport(LL_SET_NEXT_FAILURE, true);
    node->next = next;
}

void ll_nodeDestroyAllSpare(void) {
    ll_node *byebye;
    while (spare != NULL) {
        byebye = spare;
        spare = spare->next;
        free(byebye);
    }
}
