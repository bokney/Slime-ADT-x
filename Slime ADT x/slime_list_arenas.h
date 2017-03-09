
//  slime_list_arenas.h
//  Slime ADT x
//  [25/02/2017]

#ifndef slime_list_arenas_h
#define slime_list_arenas_h

typedef struct llarena_ llarena;
// forward declaration of llarena type

llarena *llarenaCreate(void *(*create)(void),
                       void (*init)(void *),
                       void (*destroy)(void *));
void llarenaDestroy(llarena *arena);

void *llarenaPush(llarena *arena);
// returns a new or previously
// inactive node's data and
// puts the node in active

void *llarenaPop(llarena *arena);
// returns the first active node's
// data while deactivating the node

unsigned int llarenaCount(llarena *arena);
// returns amount of active nodes

void llarenaReverse(llarena *arena);
// flip direction of active list

#endif /* slime_list_arenas_h */
