
//  slime_priority_lists.h
//  Slime ADT x
//  [25/02/2017]

#ifndef slime_priority_lists_h
#define slime_priority_lists_h

#include "slime_list_nodes.h"

typedef struct pl_container_ pl_container;

// create a new pl_container
pl_container *priorityListCreate(void);

// add something to the list
void priorityListAmend(pl_container *container,
                       void *data,
                       unsigned int priority);

// sort the containers contents,
// destroy the container,
// destroy all pl_nodes,
// return the sorted list
ll_node *priorityListDiscardContainer(pl_container *container);

#endif /* slime_priority_lists_h */
