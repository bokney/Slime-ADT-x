
//  slime_errors.c
//  Slime ADT x
//  [29/03/2017]

#include <stdio.h>
#include <stdlib.h>
#include "slime_errors.h"

void errorReport(char *reason, bool quit) {
    printf("Error! %s\n", reason);
    if (quit) exit(EXIT_FAILURE);
}
