
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
#include "slime_list_arenas.h"

typedef struct testStruct_ {
    int number;
    char *string;
}testStruct;

void *testCreate(void) {
    testStruct *newStruct = malloc(sizeof(testStruct));
    if (newStruct == NULL) {
        printf("Error allocating memory for new testStruct!\n");
        exit(EXIT_FAILURE); }
    return newStruct;
}

void testInit(void *data) {
    testStruct *ts = (testStruct *)data;
    ts->number = 0;
    ts->string = "BONGER!";
}

void testDestroy(void *data) {
    free(data);
    data = NULL;
}


int main(int argc, char **argv) {
    
    llarena *testArena = llarenaCreate(testCreate, testInit, testDestroy);
    testStruct *tmpStruct = llarenaPush(testArena);
    tmpStruct->number = 4;
    tmpStruct->string = "WAllaAAAA";
    tmpStruct = NULL;
    tmpStruct = llarenaPop(testArena);
    printf("tmpStruct->number = %i,\ntmpStruct->string = %s\n", tmpStruct->number, tmpStruct->string);
    
    return 0;
}
