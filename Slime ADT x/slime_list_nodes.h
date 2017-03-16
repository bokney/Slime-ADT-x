
//  slime_list_nodes.h
//  Slime ADT x
//  [16/03/2017]

#ifndef slime_list_nodes_h
#define slime_list_nodes_h

typedef struct llnode_ llnode;

llnode *llnodeCreate(void);
void llnodeDestroy(llnode *node);

void *llnodeGetData(llnode *node);
void llnodeSetData(llnode *node, void *data);

llnode *llnodeGetNext(llnode *node);
void llnodeSetNext(llnode *node, llnode *next);

#endif /* slime_list_nodes_h */
