
//  slime_lists.h
//  Slime ADT x
//  [16/03/2017]

#include <stdio.h>
#include <stdlib.h>
#include "slime_lists.h"

llnode *llGetLastNode(llnode *list) {
    llnode *curr = list;
    llnode *prev = curr;
    while (curr != NULL) {
        prev = curr;
        curr = llnodeGetNext(curr);
    }
    return prev;
}

unsigned int llCount(llnode *list) {
    unsigned int count = 0;
    llnode *traversal = list;
    while (traversal != NULL) {
        count++;
        traversal = llnodeGetNext(traversal);
    }
    return count;
}

void llPrepend(llnode **list, void *data) {
    llnode *newNode = llnodeCreate();
    llnodeSetData(newNode, data);
    llnodeSetNext(newNode, *list);
    *list = newNode;
}

void llAppend(llnode **list, void *data) {
    llnode *affix = llGetLastNode(*list);
    llnode *newNode = llnodeCreate();
    llnodeSetData(newNode, data);
    llnodeSetNext(affix, newNode);
}

void llDestroy(llnode **list) {
    llnode *traversal = *list;
    llnode *byebye;
    while (traversal != NULL) {
        byebye = traversal;
        traversal = llnodeGetNext(traversal);
        llnodeDestroy(byebye);
    }
    *list = NULL;
}

void llReverse(llnode **list) {
    llnode *prev = NULL;
    llnode *curr = *list;
    llnode *next;
    while (curr != NULL) {
        next = llnodeGetNext(curr);
        llnodeSetNext(curr, prev);
        prev = curr;
        curr = next;
    }
    *list = prev;
}
