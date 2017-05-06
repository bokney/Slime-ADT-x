
//  slime_buckets.c
//  Slime ADT x
//  [05/05/2017]

#include <stdlib.h>
#include "slime_buckets.h"
#include "slime_lists.h"
#include "slime_list_nodes_access.h"
#include "slime_errors.h"

struct slimeBucket_ {
    ll_node *unused;
    unsigned int count;
    void *(*create)(void);
    void (*init)(void *);
    void (*destroy)(void *);
};

slimeBucket *bucketCreate(void *(*create)(void),
                          void (*init)(void *),
                          void (*destroy)(void *)) {
    slimeBucket *newBucket = (slimeBucket *)malloc(sizeof(slimeBucket));
    if (newBucket == NULL) errorReport("Failed to allocate memory for new slimeBucket", true);
    newBucket->unused = NULL;
    newBucket->count = 0;
    newBucket->create = create;
    newBucket->init = init;
    newBucket->destroy = destroy;
    return newBucket;
}

void bucketDestroy(slimeBucket *bucket) {
    if (bucket == NULL) errorReport("Tried to destroy a NULL slimeBucket", true);
    if (bucket->destroy == NULL) errorReport("Bucket has a NULL destroy routine", true);
    ll_node *traversal = bucket->unused;
    while (traversal != NULL) {
        bucket->destroy(traversal->data);
        traversal = traversal->next;
    }
    llDestroy(&bucket->unused);
    free(bucket);
    bucket = NULL;
}

void *bucketRequest(slimeBucket *bucket) {
    if (bucket == NULL) errorReport("Requested instance from a NULL slimeBucket", true);
    void *data;
    if (bucket->count == 0) {
        if (bucket->create == NULL) errorReport("Bucket has a NULL create routine", true);
        data = bucket->create();
    } else {
        ll_node *tmpNode = bucket->unused;
        bucket->unused = bucket->unused->next;
        data = tmpNode->data;
        ll_nodeDestroy(tmpNode);
        bucket->count--;
    }
    if (bucket->init == NULL) errorReport("Bucket has a NULL init routine", true);
    bucket->init(data);
    return data;
}

void bucketReturn(slimeBucket *bucket, void *data) {
    if (bucket == NULL) errorReport("Tried to return instance to a NULL slimeBucket", true);
    if (data == NULL) errorReport("Tried to return NULL data to a slimeBucket", true);
    llPrepend(&bucket->unused, data);
    bucket->count++;
}
