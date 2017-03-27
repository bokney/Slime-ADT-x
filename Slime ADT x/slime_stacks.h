
//  slime_stacks.h
//  Slime ADT x
//  [25/02/2017]

#ifndef slime_stacks_h
#define slime_stacks_h

typedef struct slime_stack_ slime_stack;
// forward declaration of slime_stack type

slime_stack *stackCreate(void *(*create)(void),
                       void (*init)(void *),
                       void (*destroy)(void *));
void stackDestroy(slime_stack *stack);

void *stackPush(slime_stack *stack);
// returns a new or previously
// inactive node's data and
// puts the node in active

void *stackPop(slime_stack *stack);
// returns the first active node's
// data while deactivating the node

unsigned int stackCount(slime_stack *stack);
// returns amount of active nodes

void stackReverse(slime_stack *stack);
// flip direction of active list

#endif /* slime_stacks_h */
