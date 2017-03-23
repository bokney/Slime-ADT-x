
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
#include "slime_list_nodes_access.h"
#include "slime_arenas.h"
#include "test_structures.h"

extern ll_node *spare;
void countSpare(void) {
    printf("Counted %i spare nodes.\n", llCount(spare));
}

void inspectBunny(bunny *bun) {
    printf("\nBunny Name: \t%s\n", getName(bun));
    printf("Weight: \t\t%i\n", getWeight(bun));
    printf("Height: \t\t%i\n", getHeight(bun));
    printf("Fav Food: \t\t%s\n\n", getFoodName(getFavouriteFood(bun)));
}

slime_arena *bunnyArena = NULL;
ll_node *bunnyList = NULL;

int main(int argc, char **argv) {
    
    printf("\n\tStarting Test!!\n\n");
    countSpare();
    
    printf("Creating an arena for bunnies...\n");
    bunnyArena = arenaCreate(createBunny, initBunny, destroyBunny);
    
    
    printf("Time to retrieve some bunnies from the arena!\n");
    bunny *bunnyPtr = arenaRequest(bunnyArena);
    setBunny(bunnyPtr, "Shit-For-Brains", 10, 25, rand() % 3);
    inspectBunny(bunnyPtr);
    
    bunny *bunnyPtr2 = arenaRequest(bunnyArena);
    setBunny(bunnyPtr2, "Greatest Chomper", 12, 26, 2);
    inspectBunny(bunnyPtr2);
    
    countSpare();
    
    arenaReturn(bunnyArena, bunnyPtr);
    arenaReturn(bunnyArena, bunnyPtr2); 
    
    printf("\n\tStress Test!!\n\n");
    for (int i = 0; i != 5000; i++) {
        llPrepend(&bunnyList, arenaRequest(bunnyArena));
    }
    
    printf("Added %i elements to bunnyList\n", llCount(bunnyList));
    countSpare();
    
    printf("Returning these elements to the arena!\n");
    
    ll_node *traversal = bunnyList;
    /*while (bunnyList != NULL) {
        traversal = bunnyList;
        bunnyList = ll_nodeGetNext(bunnyList);
        arenaReturn(bunnyArena, ll_nodeGetData(traversal));
        ll_nodeDestroy(traversal);
    }*/
    while (traversal != NULL) {
        arenaReturn(bunnyArena, ll_nodeGetData(traversal));
        traversal = ll_nodeGetNext(traversal);
    }
    llDestroy(&bunnyList);
    
    countSpare();
    
    printf("Destroying arena!\n");
    arenaDestroy(bunnyArena);
    
    countSpare();
    printf("Destroying all spare...\n");
    ll_nodeDestroyAllSpare();
    countSpare();
    
    return 0;
}
