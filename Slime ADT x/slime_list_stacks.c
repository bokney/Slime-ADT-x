
//  slime_list_stacks.c
//  Slime ADT x
//  [25/02/2017]

#include <stdio.h>
#include <stdlib.h>
#include "slime_list_stacks.h"
#include "slime_lists.h"
#include "slime_list_nodes_access.h"

struct ll_stack_ {
    ll_node *activeHead;
    ll_node *inactiveHead;
    void *(*create)(void);
    void (*init)(void *data);
    void (*destroy)(void *data);
};

ll_stack *ll_stackCreate(void *(*create)(void),
                       void (*init)(void *),
                       void (*destroy)(void *)) {
    ll_stack *newstack = (ll_stack *)malloc(sizeof(ll_stack));
    if (newstack == NULL) {
        printf("Error allocating memory for new ll_stack!\n");
        exit(EXIT_FAILURE); }
    newstack->activeHead = NULL;
    newstack->inactiveHead = NULL;
    newstack->create = create;
    newstack->init = init;
    newstack->destroy = destroy;
    return newstack;
}

void ll_stackDestroy(ll_stack *stack) {
    if (stack == NULL) {
        printf("Error! Tried to destroy a NULL stack!\n");
        exit(EXIT_FAILURE); }
    // free list node's datas
    ll_node *traversal = stack->activeHead;
    while (traversal != NULL) {
        stack->destroy(ll_nodeGetData(traversal));
        traversal = ll_nodeGetNext(traversal);
    }
    traversal = stack->inactiveHead;
    while (traversal != NULL) {
        stack->destroy(ll_nodeGetData(traversal));
        traversal = ll_nodeGetNext(traversal);
    }
    // free the lists themselves
    llDestroy(&stack->activeHead);
    llDestroy(&stack->inactiveHead);
    // free the stack
    free(stack);
    stack = NULL;
}

void *ll_stackPush(ll_stack *stack) {
    if (stack == NULL) {
        printf("Error! Tried to push to a NULL stack!\n");
        exit(EXIT_FAILURE); }
    void *data;
    if (stack->inactiveHead == NULL) {
        data = stack->create();
        llPrepend(&stack->activeHead, data);
    } else {
        ll_node *node = stack->inactiveHead;
        stack->inactiveHead = ll_nodeGetNext(stack->inactiveHead);
        ll_nodeSetNext(node, stack->activeHead);
        stack->activeHead = node;
        data = ll_nodeGetData(node);
    }
    return data;
}

void *ll_stackPop(ll_stack *stack) {
    if (stack == NULL) {
        printf("Error! Tried to pop from a NULL stack!\n");
        exit(EXIT_FAILURE); }
    if (stack->activeHead == NULL) {
        return NULL;
    } else {
        ll_node *node = stack->activeHead;
        void *data = ll_nodeGetData(node);
        stack->activeHead = ll_nodeGetNext(stack->activeHead);
        ll_nodeSetNext(node, stack->inactiveHead);
        stack->inactiveHead = node;
        return data;
    }
}

unsigned int ll_stackCount(ll_stack *stack) {
    if (stack == NULL) {
        printf("Error! Tried to count nodes in a NULL stack!\n");
        exit(EXIT_FAILURE); }
    return llCount(stack->activeHead);
}

void ll_stackReverse(ll_stack *stack) {
    if (stack == NULL) {
        printf("Error! Tried to reverse NULL stack!\n");
        exit(EXIT_FAILURE); }
    llReverse(&stack->activeHead);
}
