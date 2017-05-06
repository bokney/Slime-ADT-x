
//  slime_stacks.h
//  Slime ADT x
//  [06/05/2017]

#ifndef slime_stacks_h
#define slime_stacks_h

typedef struct slimeStack_ slimeStack;

// returns a fresh instance of slimeStack
slimeStack *slimeStackCreate(void *(*create)(void),
                             void (*init)(void *),
                             void (*destroy)(void *));

// puts all in active into bucket
// bucket is then destroyed
// and stack sent to stackBucket
void slimeStackDestroy(slimeStack *stack);

// returns a fresh node which is
// added to the active list
void *slimeStackPush(slimeStack *stack);

// returns data of first node in active
// while also putting it in the bucket
void *slimeStackPop(slimeStack *stack);

// reverse direction of active list
void slimeStackReverse(slimeStack *stack);

// count amount of active nodes
unsigned int slimeStackCount(slimeStack *stack);

#endif /* slime_stacks_h */
