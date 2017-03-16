
//  slime_list_arenas.c
//  Slime ADT x
//  [25/02/2017]

#include <stdio.h>
#include <stdlib.h>
#include "slime_list_arenas.h"
#include "slime_lists.h"

struct llarena_ {
    llnode *activeHead;
    llnode *inactiveHead;
    void *(*create)(void);
    void (*init)(void *data);
    void (*destroy)(void *data);
};

llarena *llarenaCreate(void *(*create)(void),
                       void (*init)(void *),
                       void (*destroy)(void *)) {
    llarena *newArena = (llarena *)malloc(sizeof(llarena));
    if (newArena == NULL) {
        printf("Error allocating memory for new llarena!\n");
        exit(EXIT_FAILURE); }
    newArena->activeHead = NULL;
    newArena->inactiveHead = NULL;
    newArena->create = create;
    newArena->init = init;
    newArena->destroy = destroy;
    return newArena;
}

void llarenaDestroy(llarena *arena) {
    if (arena == NULL) {
        printf("Error! Tried to destroy a NULL arena!\n");
        exit(EXIT_FAILURE); }
    // free list node's datas
    llnode *traversal = arena->activeHead;
    while (traversal != NULL) {
        arena->destroy(llnodeGetData(traversal));
        traversal = llnodeGetNext(traversal);
    }
    traversal = arena->inactiveHead;
    while (traversal != NULL) {
        arena->destroy(llnodeGetData(traversal));
        traversal = llnodeGetNext(traversal);
    }
    // free the lists themselves
    llDestroy(&arena->activeHead);
    llDestroy(&arena->inactiveHead);
    // free the arena
    free(arena);
    arena = NULL;
}

void *llarenaPush(llarena *arena) {
    if (arena == NULL) {
        printf("Error! Tried to push to a NULL arena!\n");
        exit(EXIT_FAILURE); }
    void *data;
    if (arena->inactiveHead == NULL) {
        data = arena->create();
        llPrepend(&arena->activeHead, data);
    } else {
        llnode *node = arena->inactiveHead;
        arena->inactiveHead = llnodeGetNext(arena->inactiveHead);
        llnodeSetNext(node, arena->activeHead);
        arena->activeHead = node;
        data = llnodeGetData(node);
    }
    return data;
}

void *llarenaPop(llarena *arena) {
    if (arena == NULL) {
        printf("Error! Tried to pop from a NULL arena!\n");
        exit(EXIT_FAILURE); }
    if (arena->activeHead == NULL) {
        return NULL;
    } else {
        llnode *node = arena->activeHead;
        void *data = llnodeGetData(node);
        arena->activeHead = llnodeGetNext(arena->activeHead);
        llnodeSetNext(node, arena->inactiveHead);
        arena->inactiveHead = node;
        return data;
    }
}

unsigned int llarenaCount(llarena *arena) {
    if (arena == NULL) {
        printf("Error! Tried to count nodes in a NULL arena!\n");
        exit(EXIT_FAILURE); }
    return llCount(arena->activeHead);
}

void llarenaReverse(llarena *arena) {
    if (arena == NULL) {
        printf("Error! Tried to reverse NULL arena!\n");
        exit(EXIT_FAILURE); }
    llReverse(&arena->activeHead);
}
