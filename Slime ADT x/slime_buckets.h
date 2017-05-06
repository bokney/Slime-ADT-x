
//  slime_buckets.h
//  Slime ADT x
//  [05/05/2017]

#ifndef slime_buckets_h
#define slime_buckets_h

typedef struct slimeBucket_ slimeBucket;

// each individual bucket deals
// with the allocation and deallocation
// of one type of structure
// unused instances are stored in a
// list ready to be re-deployed

// create a new instance of slimeBucket
// the create routine must return a newly
// allocated instance of the buckets type
// the init routine  effectively
// wipes the instance it is passed
// the destroy routine frees
// any instance it is passed
slimeBucket *bucketCreate(void *(*create)(void),
                          void (*init)(void *),
                          void (*destroy)(void *));

// run destroy() on all instances
// in unused list, then free bucket
void bucketDestroy(slimeBucket *bucket);

// request an instance from the bucket
// creates a new one if none spare
void *bucketRequest(slimeBucket *bucket);

// return an instance to the bucket
// sticking it in the unused list
void bucketReturn(slimeBucket *bucket, void *data);

#endif /* slime_buckets_h */
