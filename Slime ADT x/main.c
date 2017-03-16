
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
#include "slime_lists.h"

llnode *ourList = NULL;

int main(int argc, char **argv) {
    
    printf("i counted %i nodes!\n", llCount(ourList));
    
    llnode *nodePtrA = llnodeCreate();
    llnode *nodePtrB = llnodeCreate();
    llnodeSetData(nodePtrA, "piss spray, ");
    llnodeSetData(nodePtrB, "everywhere!\n");
    llnodeSetNext(nodePtrA, nodePtrB);
    
    ourList = nodePtrA;
    
    llAppend(&ourList, "that musky smell...\n");
    llPrepend(&ourList, "also, ");
    llPrepend(&ourList, "nice clean buttholes!\n");
    llPrepend(&ourList, "imagine the scenario...");
    
    llnode *traversal = ourList;
    
    while (traversal != NULL) {
        printf("%s", llnodeGetData(traversal));
        traversal = llnodeGetNext(traversal);
    }
    
    traversal = ourList;
    
    printf("you heard it right, %s", llnodeGetData(llGetLastNode(ourList)));
    
    printf("i counted %i nodes!\n", llCount(ourList));
    
    printf("time to reverse!!\n\n");
    
    llReverse(&ourList);
    
    traversal = ourList;
    
    while (traversal != NULL) {
        printf("%s", llnodeGetData(traversal));
        traversal = llnodeGetNext(traversal);
    }
    
    printf("\n\ni counted %i nodes!\n", llCount(ourList));
    
    llDestroy(&ourList);
    
    printf("after freeing, i count %i nodes!\n", llCount(ourList));
    
    return 0;
}
