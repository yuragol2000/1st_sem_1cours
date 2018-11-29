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

struct Stack
{
    int size;// то что внутри
    int capacity;// то место которое может быть доступным
    val_type *data;
    int hash_sum;
    char print_format[3];
    val_type *canary;
    int *errors;

};
enum errors
    {
    BAD_SIZE = 1,
    BAD_SIZE_CAPACITY = 2,
    BAD_CAPACITY = 3,
    BAD_PROTACTION = 4,
    BAD_CANARY_DEAD = 5,
    NO_PROBLEM = 0,
    PROBLEMS = 6
};

    FILE *Dump ;

#endif // STACK_H_INCLUDED
