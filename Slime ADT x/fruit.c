
//  fruit.c
//  Slime ADT x
//  [05/05/2017]

#include <stdlib.h>
#include "fruit.h"
#include "slime_errors.h"

void *createFruit(void) {
    void *newFruit = (fruit *)malloc(sizeof(fruit));
    if (newFruit == NULL) errorReport("Failed to allocate space for new fruit", true);
    return newFruit;
}

void initFruit(void *data) {
    fruit *tmpFruit = data;
    tmpFruit->name = NULL;
    tmpFruit->weight = 0;
}

void destroyFruit(void *data) {
    free(data);
}
