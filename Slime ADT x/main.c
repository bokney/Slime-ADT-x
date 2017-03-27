
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
#include "slime_list_nodes_access.h"
#include "slime_lists.h"
#include "slime_priority_lists.h"
#include "test_structures.h"

extern ll_node *spare;

int main(int argc, char **argv) {
    
    srand(time(NULL));
    
    pl_container *testPL = priorityListCreate();
    
    printf("Adding some numbers to the priority list:\n");
    unsigned int amt = 4 + (rand() % 8);
    for (int i = 0; i != amt; i++) {
        int r = rand() % 8;
        if (!(i % 8)) r = 0;
        printf("%i ", r);
        priorityListAmend(testPL, r, r);
    }
    
    ll_node *sorted = priorityListDiscardContainer(testPL);
    
    printf("\nReading out the sorted numbers:\n");
    
    ll_node *traversal = sorted;
    while (traversal != NULL) {
        printf("%i ", ll_nodeGetData(traversal));
        traversal = ll_nodeGetNext(traversal);
    }
    printf("\n");
    
    printf("Destroying the sorted list!\n");
    llDestroy(&sorted);
    
    printf("Detected %i spare nodes!\nDestroying all spare!\n", llCount(spare));
    
    ll_nodeDestroyAllSpare();
    
    printf("Detected %i spare nodes!\n", llCount(spare));
    
    return 0;
}
