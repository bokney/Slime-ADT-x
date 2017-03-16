
//  slime_lists.h
//  Slime ADT x
//  [16/03/2017]

#ifndef slime_lists_h
#define slime_lists_h

#include "slime_list_nodes.h"

llnode *llGetLastNode(llnode *list);

unsigned int llCount(llnode *list);

void llAppend(llnode **list, void *data);
void llPrepend(llnode **list, void *data);

void llDestroy(llnode **list);

void llReverse(llnode **list);

#endif /* slime_lists_h */
