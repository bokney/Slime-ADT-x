
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
#include <time.h>
#include "slime_stacks.h"
#include "slime_lists.h"
#include "fruit.h"

extern ll_node *spare;

slimeStack *fruitStack = NULL;

int main(int argc, char **argv) {
    
    printf("Starting up\n");
    printf("%i spare nodes\n", llCount(spare));
    
    printf("Creating fruitStack\n");
    fruitStack = slimeStackCreate(createFruit, initFruit, destroyFruit);
    
    printf("Adding fruit\n");
    fruit *testFruit = slimeStackPush(fruitStack);
    testFruit->name = "piss orange";
    testFruit->weight = 99;
    testFruit = slimeStackPush(fruitStack);
    testFruit->name = "gentle fellow peach";
    testFruit->weight = 14;
    testFruit = slimeStackPush(fruitStack);
    testFruit->name = "dingo buttock";
    testFruit->weight = 37;
    
    printf("Fruit added\n");
    printf("%i spare nodes\n", llCount(spare));

    printf("Popping fruit\n");
    fruit *provenFruit = slimeStackPop(fruitStack);
    while (provenFruit != NULL) {
        printf("%s, weighing in at %i chungos\n", provenFruit->name, provenFruit->weight);
        provenFruit = slimeStackPop(fruitStack);
    }
    printf("%i spare nodes\n", llCount(spare));

    printf("Destroying fruitStack\n");
    slimeStackDestroy(fruitStack);
    printf("%i spare nodes\n", llCount(spare));
    printf("End\n");
    return 0;
}
