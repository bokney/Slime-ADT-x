
//  slime_priority_lists.c
//  Slime ADT x
//  [25/02/2017]

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "slime_priority_lists.h"
#include "slime_errors.h"
#include "slime_lists.h"
#include "slime_arenas.h"

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
    ll_node *fast = source->next;
    ll_node *slow = source;
    while(fast) {
        fast = fast->next;
        if (fast) {
            fast = fast->next;
            slow = slow->next;
        }
    }
    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

ll_node *sortedMerge(ll_node *a, ll_node *b) {
    ll_node *result = NULL;
    // base cases
    if (a == NULL) return b;
    else if (b == NULL) return a;
    // pick a or b and recurse
    pl_node *nodeA = a->data;
    pl_node *nodeB = b->data;
    if (nodeA->priority <= nodeB->priority) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

void mergeSort(ll_node **head2merge) {
    ll_node *head = *head2merge;
    ll_node *a, *b;
    // base case
    if ((head == NULL) || (head->next == NULL)) return;
    listSplit(head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    *head2merge = sortedMerge(a, b);
}

ll_node *priorityListDiscardContainer(pl_container *container) {
    priorityListCheck(container, "Tried to sort and discard a NULL pl_container!");
    mergeSort(&container->listHead);
    ll_node *sortedHead = NULL;
    ll_node *zeroes = NULL;
    ll_node *traversal = container->listHead;
    while (traversal != NULL) {
        pl_node *node = traversal->data;
        if (node->priority == 0) llPrepend(&zeroes, node->data);
        else llPrepend(&sortedHead, node->data);
        arenaReturn(pl_nodeArena, node);
        traversal = traversal->next;
    }
    llDestroy(&container->listHead);
    free(container);
    container = NULL;
    llReverse(&sortedHead);
    traversal = llGetLastNode(sortedHead);
    traversal->next = zeroes;
    return sortedHead;
}
