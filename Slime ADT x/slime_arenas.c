
//  slime_arenas.c
//  Slime ADT x
//  [22/03/2017]

#include <stdio.h>
#include <stdlib.h>
#include "slime_arenas.h"
#include "slime_errors.h"
#include "slime_lists.h"

struct slime_arena_ {
    ll_node *unusedHead;
    unsigned int unusedCount;
    unsigned int spareLimit;
    unsigned int padAmount;
    void *(*create)(void);
    void (*init)(void *data);
    void (*destroy)(void *data);
};

slime_arena *arenaCreate(void *(*create)(void),
                         void (*init)(void *),
                         void (*destroy)(void *)) {
    slime_arena *newArena = (slime_arena *)malloc(sizeof(slime_arena));
    if (newArena == NULL) errorReport("Failed to allocate memory for new arena!", true);
    newArena->unusedHead = NULL;
    newArena->create = create;
    newArena->init = init;
    newArena->destroy = destroy;
    return newArena;
}

void arenaDestroy(slime_arena *arena) {
    if (arena == NULL) errorReport("Tried to destroy a nonexistant arena!", true);
    ll_node *traversal = arena->unusedHead;
    while (traversal != NULL) {
        arena->destroy(traversal->data);
        traversal = traversal->next;
    }
    llDestroy(&arena->unusedHead);
    free(arena);
    arena = NULL;
}

void *arenaRequest(slime_arena *arena) {
    if (arena == NULL) errorReport("Requested an instance from a nonexistant arena!", true);
    void *data;
    if (arena->unusedHead != NULL) {
        // oh  shit
        ll_node *tmpNode = arena->unusedHead;
        arena->unusedHead = arena->unusedHead->next;
        data = tmpNode->data;
        ll_nodeDestroy(tmpNode);
    } else {
        data = arena->create();
    }
    arena->init(data);
    return data;
}

void arenaReturn(slime_arena *arena, void *data) {
    if (arena == NULL) errorReport("Tried to return an instance to a nonexistant arena!", true);
    if (data == NULL) errorReport("Tried to return a NULL instance to an arena!", true);
    llPrepend(&arena->unusedHead, data);
}
