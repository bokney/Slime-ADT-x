
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

llstack *ourArena = NULL;

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
    
    ourArena = llstackCreate(chuCreate, chuInit, chuDestroy);
    
    chungus *tmpChung;
    tmpChung = llstackPush(ourArena);
    tmpChung->string = "slapping all over ";
    tmpChung = llstackPush(ourArena);
    tmpChung->string = "boogie swinging dicks ";
    tmpChung = llstackPush(ourArena);
    tmpChung->string = "the musk produced, from ";
    tmpChung = llstackPush(ourArena);
    tmpChung->string = "once again, ";
    
    printf("%i nodes detected\n\n", llstackCount(ourArena));
    
    llstackReverse(ourArena);
    llstackReverse(ourArena);
    
    chungus *retrieve = llstackPop(ourArena);
    while (retrieve != NULL) {
        printf("%s", retrieve->string);
        retrieve = llstackPop(ourArena);
    }
    
    llstackDestroy(ourArena);
    
    return 0;
}
