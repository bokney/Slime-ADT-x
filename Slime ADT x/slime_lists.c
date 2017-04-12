
//  slime_lists.h
//  Slime ADT x
//  [16/03/2017]

#include <stdio.h>
#include <stdlib.h>
#include "slime_lists.h"
#include "slime_list_nodes_access.h"

ll_node *llGetLastNode(ll_node *list) {
    ll_node *traversal = list;
    ll_node *prev = traversal;
    while (traversal != NULL) {
        prev = traversal;
        traversal = traversal->next;
    }
    return prev;
}

unsigned int llCount(ll_node *list) {
    unsigned int count = 0;
    ll_node *traversal = list;
    while (traversal != NULL) {
        count++;
        traversal = traversal->next;
    }
    return count;
}

void llPrepend(ll_node **list, void *data) {
    ll_node *newNode = ll_nodeCreate();
    newNode->data = data;
    newNode->next = *list;
    *list = newNode;
}

void llAppend(ll_node **list, void *data) {
    ll_node *newNode = ll_nodeCreate();
    newNode->data = data;
    ll_node *affix = llGetLastNode(*list);
    if (affix == NULL) {
        *list = newNode;
    } else {
        affix->next = newNode;
    }
}

void llDestroy(ll_node **list) {
    ll_node *traversal = *list;
    ll_node *byebye;
    while (traversal != NULL) {
        byebye = traversal;
        traversal = traversal->next;
        ll_nodeDestroy(byebye);
    }
    *list = NULL;
}

void llReverse(ll_node **list) {
    ll_node *prev = NULL;
    ll_node *curr = *list;
    ll_node *next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *list = prev;
}
