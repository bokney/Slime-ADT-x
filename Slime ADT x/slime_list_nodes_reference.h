
//  slime_list_nodes_reference.h
//  Slime ADT x
//  [18/03/2017]

#ifndef slime_list_nodes_reference_h
#define slime_list_nodes_reference_h

typedef struct ll_node_ ll_node;

void *ll_nodeGetData(ll_node *node);
ll_node *ll_nodeGetNext(ll_node *node);

#endif /* slime_list_nodes_reference_h */
