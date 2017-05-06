
//  fruit.h
//  Slime ADT x
//  [05/05/2017]

#ifndef fruit_h
#define fruit_h

typedef struct fruit_ {
    char *name;
    unsigned int weight;
}fruit;

void *createFruit(void);
void initFruit(void *data);
void destroyFruit(void *data);

#endif /* fruit_h */
