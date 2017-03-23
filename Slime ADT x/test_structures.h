
//  test_structures.h
//  Slime ADT x
//  [23/03/2017]

#ifndef test_structures_h
#define test_structures_h

typedef struct bunny_ bunny;

typedef enum rabbitFood_ {
    CARROTS,
    LETTUCE,
    OWN_SHIT
}rabbitFood;

void *createBunny(void);
void initBunny(void *data);
void destroyBunny(void *data);

void setName(bunny *bun, char *name);
char *getName(bunny *bun);

void setWeight(bunny *bun, unsigned int weight);
unsigned int getWeight(bunny *bun);

void setHeight(bunny *bun, unsigned int height);
unsigned int getHeight(bunny *bun);

void setFavouriteFood(bunny *bun, rabbitFood foodType);
rabbitFood getFavouriteFood(bunny *bun);

void setBunny(bunny *bun, char *name, unsigned int weight,
              unsigned int height, rabbitFood favFood);

char *getFoodName(rabbitFood foodType);

#endif /* test_structures_h */
