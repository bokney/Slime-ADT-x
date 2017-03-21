
//  slime_list_stacks.h
//  Slime ADT x
//  [25/02/2017]

#ifndef slime_list_stacks_h
#define slime_list_stacks_h

typedef struct ll_stack_ ll_stack;
// forward declaration of ll_stack type

ll_stack *ll_stackCreate(void *(*create)(void),
                       void (*init)(void *),
                       void (*destroy)(void *));
void ll_stackDestroy(ll_stack *stack);

void *ll_stackPush(ll_stack *stack);
// returns a new or previously
// inactive node's data and
// puts the node in active

void *ll_stackPop(ll_stack *stack);
// returns the first active node's
// data while deactivating the node

unsigned int ll_stackCount(ll_stack *stack);
// returns amount of active nodes

void ll_stackReverse(ll_stack *stack);
// flip direction of active list

#endif /* slime_list_stacks_h */
