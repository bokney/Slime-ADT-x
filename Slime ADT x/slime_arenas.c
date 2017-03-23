
//  slime_arenas.c
//  Slime ADT x
//  [22/03/2017]

#include <stdio.h>
#include <stdlib.h>
#include "slime_arenas.h"
#include "slime_list_nodes_access.h"
#include "slime_lists.h"

struct slime_arena_ {
    ll_node *unusedHead;
    void *(*create)(void);
    void (*init)(void *data);
    void (*destroy)(void *data);
};

void arenaCheckExists(slime_arena *arena, char *string) {
    if (arena == NULL) {
        printf("Error! %s\n", string);
        exit(EXIT_FAILURE); }
}

slime_arena *arenaCreate(void *(*create)(void),
                         void (*init)(void *),
                         void (*destroy)(void *)) {
    slime_arena *newArena = (slime_arena *)malloc(sizeof(slime_arena));
    arenaCheckExists(newArena, "Failed to allocate memory for new arena!");
    newArena->unusedHead = NULL;
    newArena->create = create;
    newArena->init = init;
    newArena->destroy = destroy;
    return newArena;
}

void arenaDestroy(slime_arena *arena) {
    arenaCheckExists(arena, "Tried to destroy a nonexistant arena!");
    ll_node *traversal = arena->unusedHead;
    while (traversal != NULL) {
        arena->destroy(ll_nodeGetData(traversal));
        traversal = ll_nodeGetNext(traversal);
    }
    llDestroy(&arena->unusedHead);
    free(arena);
    arena = NULL;
}

void *arenaRequest(slime_arena *arena) {
    arenaCheckExists(arena, "Requested an instance from a nonexistant arena!");
    void *data;
    if (arena->unusedHead != NULL) {
        // oh  shit
        ll_node *tmpNode = arena->unusedHead;
        arena->unusedHead = ll_nodeGetNext(arena->unusedHead);
        data = ll_nodeGetData(tmpNode);
        ll_nodeDestroy(tmpNode);
    } else {
        data = arena->create();
    }
    arena->init(data);
    return data;
}

void arenaReturn(slime_arena *arena, void *data) {
    arenaCheckExists(arena, "Tried to return an instance to a nonexistant arena!");
    if (data == NULL) {
        printf("Error! Tried to return a NULL instance to an arena!\n");
        exit(EXIT_FAILURE); }
    llPrepend(&arena->unusedHead, data);
}
