
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
