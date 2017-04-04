
//  slime_stacks.c
//  Slime ADT x
//  [25/02/2017]

#include <stdio.h>
#include <stdlib.h>
#include "slime_stacks.h"
#include "slime_errors.h"
#include "slime_lists.h"

struct slime_stack_ {
    ll_node *activeHead;
    ll_node *inactiveHead;
    void *(*create)(void);
    void (*init)(void *data);
    void (*destroy)(void *data);
};

slime_stack *stackCreate(void *(*create)(void),
                       void (*init)(void *),
                       void (*destroy)(void *)) {
    slime_stack *newStack = (slime_stack *)malloc(sizeof(slime_stack));
    if (newStack == NULL) errorReport("Could not allocate memory for new slime_stack!", true);
    newStack->activeHead = NULL;
    newStack->inactiveHead = NULL;
    newStack->create = create;
    newStack->init = init;
    newStack->destroy = destroy;
    return newStack;
}

void stackDestroy(slime_stack *stack) {
    if (stack == NULL) errorReport("Tried to destroy a NULL stack!", true);
    // free list node's datas
    ll_node *traversal = stack->activeHead;
    while (traversal != NULL) {
        stack->destroy(traversal->data);
        traversal = traversal->next;
    }
    traversal = stack->inactiveHead;
    while (traversal != NULL) {
        stack->destroy(traversal->data);
        traversal = traversal->next;
    }
    // free the lists themselves
    llDestroy(&stack->activeHead);
    llDestroy(&stack->inactiveHead);
    // free the stack
    free(stack);
    stack = NULL;
}

void *stackPush(slime_stack *stack) {
    if (stack == NULL) errorReport("Tried to push to a NULL stack!", true);
    void *data;
    if (stack->inactiveHead == NULL) {
        data = stack->create();
        llPrepend(&stack->activeHead, data);
    } else {
        ll_node *node = stack->inactiveHead;
        stack->inactiveHead = stack->inactiveHead->next;
        node->next = stack->activeHead;
        stack->activeHead = node;
        data = node->data;
    }
    return data;
}

void *stackPop(slime_stack *stack) {
    if (stack == NULL) errorReport("Tried to pop from a NULL stack!", true);
    if (stack->activeHead == NULL) {
        return NULL;
    } else {
        ll_node *node = stack->activeHead;
        void *data = node->data;
        stack->activeHead = stack->activeHead->next;
        node->next = stack->inactiveHead;
        stack->inactiveHead = node;
        return data;
    }
}

unsigned int stackCount(slime_stack *stack) {
    if (stack == NULL) errorReport("Tried to count nodes in a NULL stack!", true);
    return llCount(stack->activeHead);
}

void stackReverse(slime_stack *stack) {
    if (stack == NULL) errorReport("Tried to reverse NULL stack!", true);
    llReverse(&stack->activeHead);
}
