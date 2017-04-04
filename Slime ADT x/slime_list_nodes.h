
//  slime_list_nodes.h
//  Slime ADT x
//  [04/04/2017]

#ifndef slime_list_nodes_h
#define slime_list_nodes_h

typedef struct ll_node_ {
    void *data;
    struct ll_node_ *next;
}ll_node;

ll_node *ll_nodeCreate(void);
void ll_nodeDestroy(ll_node *node);

void ll_nodeDestroyAllSpare(void);

#endif /* slime_list_nodes_h */
