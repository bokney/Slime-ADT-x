
//  slime_stacks.c
//  Slime ADT x
//  [06/05/2017]

#include <stdlib.h>
#include "slime_stacks.h"
#include "slime_errors.h"
#include "slime_buckets.h"
#include "slime_lists.h"

struct slimeStack_ {
    slimeBucket *bucket;
    ll_node *active;
};

slimeBucket *stackBucket = NULL;

void *slimeStackMalloc(void) {
    slimeStack *newStack = (slimeStack *)malloc(sizeof(slimeStack));
    if (newStack == NULL) errorReport("Failed to allocate memory for new slimeStack", true);
    newStack->bucket = NULL;
    newStack->active = NULL;
    return newStack;
}

void slimeStackInit(void *data) {
    slimeStack *tmpStack = data;
    tmpStack->bucket = NULL;
    tmpStack->active = NULL;
}

void slimeStackFree(void *data) {
    free(data);
    data = NULL;
}

slimeStack *slimeStackCreate(void *(*create)(void),
                        void (*init)(void *),
                        void (*destroy)(void *)) {
    if (stackBucket == NULL) stackBucket = bucketCreate(slimeStackMalloc,
                                                        slimeStackInit,
                                                        slimeStackFree);
    slimeStack *newStack = bucketRequest(stackBucket);
    newStack->bucket = bucketCreate(create, init, destroy);
    return newStack;
}

void slimeStackDestroy(slimeStack *stack) {
    if (stack == NULL) errorReport("Tried to destory a NULL stack", true);
    // empty the list into the bucket
    ll_node *traversal = stack->active;
    while (traversal != NULL) {
        bucketReturn(stack->bucket, traversal->data);
        traversal = traversal->next;
    }
    llDestroy(&stack->active);
    // destroy the bucket
    bucketDestroy(stack->bucket);
    // destroy the stack
    bucketReturn(stackBucket, stack);
}

void *slimeStackPush(slimeStack *stack) {
    if (stack == NULL) errorReport("Tried to push a NULL stack", true);
    void *tmpData = bucketRequest(stack->bucket);
    llPrepend(&stack->active, tmpData);
    return tmpData;
}

void *slimeStackPop(slimeStack *stack) {
    if (stack == NULL) errorReport("Tried to pop a NULL stack", true);
    if (stack->active != NULL) {
        ll_node *tmpNode = stack->active;
        stack->active = stack->active->next;
        tmpNode->next = NULL;
        void *tmpData = tmpNode->data;
        bucketReturn(stack->bucket, tmpData);
        llDestroy(&tmpNode);
        return tmpData;
    } else return NULL;
}

void slimeStackReverse(slimeStack *stack) {
    if (stack == NULL) errorReport("Tried to reverse a NULL stack", true);
    llReverse(&stack->active);
}

unsigned int slimeStackCount(slimeStack *stack) {
    if (stack == NULL) errorReport("Tried to count a NULL stack", true);
    return llCount(stack->active);
}

