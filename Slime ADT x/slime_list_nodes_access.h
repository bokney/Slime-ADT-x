
//  slime_list_nodes_access.h
//  Slime ADT x
//  [18/03/2017]

#ifndef slime_list_nodes_access_h
#define slime_list_nodes_access_h

#include "slime_list_nodes_reference.h"

ll_node *ll_nodeCreate(void);
void ll_nodeDestroy(ll_node *node);

void ll_nodeSetData(ll_node *node, void *data);
void ll_nodeSetNext(ll_node *node, ll_node *next);

#endif /* slime_list_nodes_access_h */
