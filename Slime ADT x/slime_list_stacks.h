
//  slime_list_stacks.h
//  Slime ADT x
//  [25/02/2017]

#ifndef slime_list_stacks_h
#define slime_list_stacks_h

typedef struct llstack_ llstack;
// forward declaration of llstack type

llstack *llstackCreate(void *(*create)(void),
                       void (*init)(void *),
                       void (*destroy)(void *));
void llstackDestroy(llstack *stack);

void *llstackPush(llstack *stack);
// returns a new or previously
// inactive node's data and
// puts the node in active

void *llstackPop(llstack *stack);
// returns the first active node's
// data while deactivating the node

unsigned int llstackCount(llstack *stack);
// returns amount of active nodes

void llstackReverse(llstack *stack);
// flip direction of active list

#endif /* slime_list_stacks_h */
