
//  slime_stacks.c
//  Slime ADT x
//  [25/02/2017]

#include <stdio.h>
#include <stdlib.h>
#include "slime_errors.h"
#include "slime_stacks.h"
#include "slime_lists.h"
#include "slime_list_nodes_access.h"

struct slime_stack_ {
    ll_node *activeHead;
    ll_node *inactiveHead;
    void *(*create)(void);
    void (*init)(void *data);
    void (*destroy)(void *data);
};

void stackCheck(slime_stack *stack, char *reason) {
    if (stack == NULL) errorReport(reason, true);
}

slime_stack *stackCreate(void *(*create)(void),
                       void (*init)(void *),
                       void (*destroy)(void *)) {
    slime_stack *newStack = (slime_stack *)malloc(sizeof(slime_stack));
    stackCheck(newStack, "Could not allocate memory for new slime_stack!");
    newStack->activeHead = NULL;
    newStack->inactiveHead = NULL;
    newStack->create = create;
    newStack->init = init;
    newStack->destroy = destroy;
    return newStack;
}

void stackDestroy(slime_stack *stack) {
    stackCheck(stack, "Tried to destroy a NULL stack!");
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

void *stackPush(slime_stack *stack) {
    stackCheck(stack, "Tried to push to a NULL stack!");
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

void *stackPop(slime_stack *stack) {
    stackCheck(stack, "Tried to pop from a NULL stack!");
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

unsigned int stackCount(slime_stack *stack) {
    stackCheck(stack, "Tried to count nodes in a NULL stack!");
    return llCount(stack->activeHead);
}

void stackReverse(slime_stack *stack) {
    stackCheck(stack, "Tried to reverse NULL stack!");
    llReverse(&stack->activeHead);
}
