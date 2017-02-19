
//  slime_lists.h
//  Slime ADT x
//  [19/02/2017]

#ifndef slime_lists_h
#define slime_lists_h

// forward declaration llnode type
typedef struct llnode_ llnode;

//  //  set  //  //

// add to list
void ll_append(llnode **head, void *data);
void ll_prepend(llnode **head, void *data);

// sort list into reverse order
void ll_reverse(llnode **head);

//  //  get  //  //

// get amount of nodes in a list
unsigned int ll_count(llnode *head);
// get a pointer node's data from the list
void *ll_retrieve(llnode **head, unsigned int number);

// get a node's data while deactivating it's node
void *ll_pop(llnode **head);

// get rid of any spare nodes
void ll_purge_spare(void);

#endif /* slime_lists_h */
