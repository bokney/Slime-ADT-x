
//  slime_priority_lists.c
//  Slime ADT x
//  [25/02/2017]

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "slime_priority_lists.h"
#include "slime_lists.h"
#include "slime_arenas.h"
#include "slime_list_nodes_access.h"

typedef struct pl_node_ {
    void *data;
    unsigned int priority;
}pl_node;

struct pl_container_ {
    ll_node *listHead;
};

slime_arena *pl_nodeArena = NULL;

void *pl_nodeCreate(void) {
    pl_node *newPLNode = (pl_node *)malloc(sizeof(pl_node));
    if (newPLNode == NULL) {
        printf("Error allocating memory for new pl_node!!\n");
        exit(EXIT_FAILURE); }
    return newPLNode;
}

void pl_nodeInit(void *pln) {
    if (pln == NULL) {
        printf("Error! pl_nodeInit was passed NULL!\n");
        exit(EXIT_FAILURE); }
    pl_node *tmpNode = pln;
    tmpNode->data = NULL;
    tmpNode->priority = 0;
}

void pl_nodeDestroy(void *pln) {
    if (pln == NULL) {
        printf("Error! Tried to destroy a NULL pl_node!\n");
        exit(EXIT_FAILURE); }
    free(pln);
}

void pl_nodeArenaCreate(void) {
    pl_nodeArena = arenaCreate(pl_nodeCreate, pl_nodeInit, pl_nodeDestroy);
}

void priorityListCheck(pl_container *container, char *reason) {
    if (container == NULL) {
        printf("Error! %s\n", reason);
        exit(EXIT_FAILURE); }
}

pl_container *priorityListCreate(void) {
    if (pl_nodeArena == NULL) pl_nodeArenaCreate();
    pl_container *newPL = (pl_container *)malloc(sizeof(pl_container));
    priorityListCheck(newPL, "Failed to create new priority list container!");
    newPL->listHead = NULL;
    return newPL;
}

void priorityListAmend(pl_container *container,
                       void *data,
                       unsigned int priority) {
    priorityListCheck(container, "Tried to amend a NULL pl_container!");
    pl_node *node = arenaRequest(pl_nodeArena);
    node->data = data;
    node->priority = priority;
    llPrepend(&container->listHead, node);
}

void listSplit(ll_node *source, ll_node **front, ll_node **back) {
    ll_node *fast;
    ll_node *slow;
    // check if list has only 0 or 1 nodes
    if ((source == NULL) || (ll_nodeGetNext(source) == NULL)) {
        *front = source;
        *back = NULL;
        return;
    }
    slow = source;
    fast = ll_nodeGetNext(source);
    // move fast by 2 and slow by 1
    while (fast != NULL) {
        fast = ll_nodeGetNext(fast);
        if (fast != NULL) {
            slow = ll_nodeGetNext(slow);
            fast = ll_nodeGetNext(fast);
        }
    }
    // time to split
    *front = source;
    *back = ll_nodeGetNext(slow);
    ll_nodeSetNext(slow, NULL);
}

ll_node *sortedMerge(ll_node *a, ll_node *b) {
    ll_node *result = NULL;
    // base cases
    if (a == NULL) return b;
    else if (b == NULL) return a;
    // pick a or b and recurse
    pl_node *nodeA = ll_nodeGetData(a);
    pl_node *nodeB = ll_nodeGetData(b);
    if (nodeA->priority <= nodeB->priority) {
        result = a;
        ll_nodeSetNext(a, sortedMerge(ll_nodeGetNext(a), b));
    } else {
        result = b;
        ll_nodeSetNext(a, sortedMerge(a, ll_nodeGetNext(b)));
    }
    return result;
}

void mergeSort(ll_node **head2merge) {
    ll_node *head = *head2merge;
    ll_node *a, *b;
    // base case
    if ((head == NULL) || (ll_nodeGetNext(head) == NULL)) return;
    listSplit(head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    *head2merge = sortedMerge(a, b);
}

ll_node *priorityListDiscardContainer(pl_container *container) {
    priorityListCheck(container, "Tried to sort and discard a NULL pl_container!");
    mergeSort(&container->listHead);
    ll_node *sortedHead = NULL;
    ll_node *traversal = container->listHead;
    while (traversal != NULL) {
        pl_node *node = ll_nodeGetData(traversal);
        llPrepend(&sortedHead, node->data);
        arenaReturn(pl_nodeArena, node);
        traversal = ll_nodeGetNext(traversal);
    }
    llDestroy(&container->listHead);
    free(container);
    container = NULL;
    return sortedHead;
}
