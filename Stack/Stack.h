#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define LEN_OF_CANARY 3

#define $( var )({ printf("%s = %d\n",#var,var);})

#define assert_stack(nameStack) {\
    if ( !(StackOK(nameStack)) ) {\
        printf("| !!!Assertion failed!!!\n");\
        printf("|       what: StackOK(%s),\n", #nameStack);\
        printf("|       in: %s,\n", __FILE__);\
        printf("|       function: %s,\n",  __PRETTY_FUNCTION__);\
        printf("|       on: %d line.\n", __LINE__);\
        printf("|   !!!Look at DUMP!!!\n");\
        Dump_(nameStack);\
        abort();\
    }\
}\

typedef int val_type;

enum errors
    {
    BAD_SIZE = (1001),
    BAD_SIZE_CAPACITY = (1010),
    BAD_CAPACITY = (1011),
    BAD_PROTACTION = (1100),
    BAD_CANARY_DEAD = (1101),
    NO_PROBLEM = (1000)


};

    FILE *Dump ;
#endif // STACK_H_INCLUDED
