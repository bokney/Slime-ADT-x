
//  slime_observer.c
//  Slime ADT x
//  [04/04/2017]

#include "slime_observer.h"

struct slime_observer_ {
    void (*attach)(void);
    void (*detach)(void);
};
