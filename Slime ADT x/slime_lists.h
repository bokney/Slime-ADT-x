
//  slime_lists.h
//  Slime ADT x
//  [16/03/2017]

#ifndef slime_lists_h
#define slime_lists_h

#include "slime_list_nodes_reference.h"

ll_node *llGetLastNode(ll_node *list);

unsigned int llCount(ll_node *list);

void llAppend(ll_node **list, void *data);
void llPrepend(ll_node **list, void *data);

void llDestroy(ll_node **list);

void llReverse(ll_node **list);

#endif /* slime_lists_h */
