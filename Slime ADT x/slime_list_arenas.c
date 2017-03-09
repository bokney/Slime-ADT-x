
//  slime_list_arenas.c
//  Slime ADT x
//  [25/02/2017]

#include <stdio.h>
#include <stdlib.h>
#include "slime_list_arenas.h"
#include "slime_lists.h"

//#define LLARENA_CHUNK_SIZE  10

struct llarena_ {
    unsigned int amountActive;
    unsigned int amountInactive;
    llnode *activeHead;
    llnode *inactiveHead;
    void *(*create)(void);
    void (*init)(void *data);
    void (*destroy)(void *data);
};

void llarenaCheck(llarena *arena) {
    if (arena == NULL) {
        printf("Error! passed a NULL llarena!\n");
        exit(EXIT_FAILURE);
    }
}

llarena *llarenaCreate(void *(*create)(void),
                       void (*init)(void *),
                       void (*destroy)(void *)) {
    // allocate & check memory for new arena
    llarena *newArena = (llarena *)malloc(sizeof(llarena));
    if (newArena == NULL) {
        printf("Error allocating memory for new llarena!\n");
        exit(EXIT_FAILURE); }
    // initialise arena
    newArena->create = create;
    newArena->init = init;
    newArena->destroy = destroy;
    newArena->activeHead = NULL;
    newArena->inactiveHead = NULL;
    newArena->amountActive = 0;
    newArena->amountInactive = 0;
    return newArena;
}

void llarenaDestroy(llarena *arena) {
    // check arena exists
    llarenaCheck(arena);
    llnode *tmpNode;
    // destroy all active
    while (arena->activeHead != NULL) {
        tmpNode = arena->activeHead;
        arena->activeHead = arena->activeHead->next;
        arena->destroy(tmpNode->data);
    }
    // destroy all inactive
    while (arena->inactiveHead != NULL) {
        tmpNode = arena->inactiveHead;
        arena->inactiveHead = arena->inactiveHead->next;
        arena->destroy(tmpNode->data);
    }
    free(arena);
    arena = NULL;
}

void *llarenaPush(llarena *arena) {
    // check arena exists
    llarenaCheck(arena);
    void *data;
    llnode *node;
    // check for inactive nodes
    if (arena->inactiveHead == NULL) {
        // create new node/data pair
        data = arena->create();
        node = ll_createNode();
        node->data = data;
    } else {
        // grab inactive node/data pair
        node = arena->inactiveHead;
        data = arena->inactiveHead->data;
        arena->inactiveHead = arena->inactiveHead->next;
    }
    // stick it at the start of active
    node->next = arena->activeHead;
    arena->activeHead = node;
    arena->init(data);
    return data;
}

void *llarenaPop(llarena *arena) {
    // check arena exists
    llarenaCheck(arena);
    // check for active nodes
    if (arena->activeHead == NULL) {
        // no active
        return NULL;
    } else {
        llnode *node = arena->activeHead;
        arena->activeHead = arena->activeHead->next;
        node->next = arena->inactiveHead->next;
        arena->inactiveHead = node;
        return node->data;
    }
}
