
//  slime_lists.h
//  Slime ADT x
//  [19/02/2017]

#ifndef slime_lists_h
#define slime_lists_h

typedef struct llnode_ {
    void *data;
    struct llnode_ *next;
}llnode;

//  //  mem  //  //

// returns a newly created node
llnode *ll_createNode(void);

//  //  set  //  //

// add to list
void ll_append(llnode **head, void *data);
void ll_prepend(llnode **head, void *data);

// sort list into reverse order
void ll_reverse(llnode **head);

//  //  get  //  //

// get amount of nodes in a list
unsigned int ll_count(llnode *head);

// get node[number]'s data from the list
// returns NULL if out of bounds
// be sure to use ll_count beforehand
void *ll_retrieve(llnode **head, unsigned int number);

// get a node's data,
// deactivating the node
void *ll_pop(llnode **head);

// get rid of any spare nodes
void ll_purge_spare(void);

#endif /* slime_lists_h */
