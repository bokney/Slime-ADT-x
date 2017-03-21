
//  main.c
//  Slime ADT x
//  for testing various
//  ADTs intended for
//  the slime system
//  piss in a jar
//  and call it honey
//  i'll break your legs
//  if you don't give me my money
//  [19/02/2017]

#include <stdio.h>
#include <stdlib.h>
#include "slime_list_stacks.h"

ll_stack *ourArena = NULL;

typedef struct chungus_ {
    char *string;
}chungus;

void *chuCreate(void) {
    chungus *newChung = (chungus *)malloc(sizeof(chungus));
    if (newChung == NULL) {
        printf("Error creating that chungus!\n");
        exit(EXIT_FAILURE); }
    return newChung;
}

void chuInit(void *chu) {
    if (chu == NULL) {
        printf("Error! chuInit was passed NULL!\n");
        exit(EXIT_FAILURE); }
    chungus *theChung = chu;
    theChung->string = NULL;
}

void chuDestroy(void *chu) {
    if (chu == NULL) {
        printf("Error! chuDestroy was passed NULL!\n");
        exit(EXIT_FAILURE); }
    free(chu);
}

int main(int argc, char **argv) {
    
    ourArena = ll_stackCreate(chuCreate, chuInit, chuDestroy);
    
    chungus *tmpChung;
    tmpChung = ll_stackPush(ourArena);
    tmpChung->string = "slapping all over ";
    tmpChung = ll_stackPush(ourArena);
    tmpChung->string = "boogie swinging dicks ";
    tmpChung = ll_stackPush(ourArena);
    tmpChung->string = "the musk produced, from ";
    tmpChung = ll_stackPush(ourArena);
    tmpChung->string = "once again, ";
    
    printf("%i nodes detected\n\n", ll_stackCount(ourArena));
    
    ll_stackReverse(ourArena);
    ll_stackReverse(ourArena);
    
    chungus *retrieve = ll_stackPop(ourArena);
    while (retrieve != NULL) {
        printf("%s", retrieve->string);
        retrieve = ll_stackPop(ourArena);
    }
    
    ll_stackDestroy(ourArena);
    
    return 0;
}
