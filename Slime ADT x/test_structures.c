
//  test_structures.c
//  Slime ADT x
//  [23/03/2017]

#include <stdio.h>
#include <stdlib.h>
#include "test_structures.h"

struct bunny_ {
    char *name;
    unsigned int weight;
    unsigned int height;
    rabbitFood favouriteFood;
};

void checkBunny(bunny *bun, char *reason) {
    if (bun == NULL) {
        printf("Error! %s\n", reason);
        exit(EXIT_FAILURE); }
}

void *createBunny(void) {
    bunny *newBunny = (bunny *)malloc(sizeof(bunny));
    if (newBunny == NULL) {
        checkBunny(newBunny, "Could not allocate memory for new bunny!");
        exit(EXIT_FAILURE); }
    return newBunny;
}

void initBunny(void *data) {
    bunny *bun = data;
    bun->height = 0;
    bun->weight = 0;
    bun->name = "";
}

void destroyBunny(void *data) {
    checkBunny(data, "Tried to destroy a NULL bunny!");
    free(data);
}

void setName(bunny *bun, char *name) {
    checkBunny(bun, "Tried to set name of a NULL bunny!");
    bun->name = name;
}

char *getName(bunny *bun) {
    checkBunny(bun, "Tried to get name of a NULL bunny!");
    return bun->name;
}

void setWeight(bunny *bun, unsigned int weight) {
    checkBunny(bun, "Tried to set weight of a NULL bunny!");
    bun->weight = weight;
}

unsigned int getWeight(bunny *bun) {
    checkBunny(bun, "Tried to get weight of a NULL bunny!");
    return bun->weight;
}

void setHeight(bunny *bun, unsigned int height) {
    checkBunny(bun, "Tried to set height of a NULL bunny!");
    bun->height = height;
}

unsigned int getHeight(bunny *bun) {
    checkBunny(bun, "Tried to get height of a NULL bunny!");
    return bun->height;
}

void setFavouriteFood(bunny *bun, rabbitFood foodType) {
    checkBunny(bun, "Tried to set fav food of a NULL bunny!");
    bun->favouriteFood = foodType;
}

rabbitFood getFavouriteFood(bunny *bun) {
    checkBunny(bun, "Tried to get fav food of a NULL bunny!");
    return bun->favouriteFood;
}

void setBunny(bunny *bun, char *name, unsigned int weight,
              unsigned int height, rabbitFood favFood) {
    setName(bun, name);
    setWeight(bun, weight);
    setHeight(bun, height);
    setFavouriteFood(bun, favFood);
}

char *getFoodName(rabbitFood foodType) {
    switch (foodType) {
        case CARROTS:
            return "Carrots"; break;
        case LETTUCE:
            return "Green Leaves"; break;
        case OWN_SHIT:
            return "Its Own Shit... Gross!"; break;
    }
}

void inspectBunny(bunny *bun) {
    printf("\nBunny Name: \t%s\n", getName(bun));
    printf("Weight: \t\t%i\n", getWeight(bun));
    printf("Height: \t\t%i\n", getHeight(bun));
    printf("Fav Food: \t\t%s\n\n", getFoodName(getFavouriteFood(bun)));
}
