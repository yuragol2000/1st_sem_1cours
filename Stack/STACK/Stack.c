#include "Stack.h"

void Ctor(struct Stack *st)
{
    assert(st != NULL);

    st->size     = 0;
    st->capacity = 1;

    st->data   = (val_type*)calloc(st->capacity + 2 * LEN_OF_CANARY,sizeof(val_type));
    st->canary = (val_type*)calloc(2 * LEN_OF_CANARY,sizeof(val_type));
    st->errors = (int*     )calloc(6,sizeof(int));



    assert((st)->canary != NULL);
    assert((st)->data != NULL);
    assert((st)->errors != NULL);


/**
    st->print_format[0] = '%';
    st->print_format[1] = 'b';
    st->print_format[2] = '\0';

    switch (sizeof(val_type))
    {
        case sizeof(char):
            st->print_format[1] = 'c';
            break;

        case sizeof(int):
            st->print_format[1] = 'd';
            break;

        case sizeof(double):
            st->print_format[1] = 'f';
            break;

        default:
            break;
    }
**/


 Canary(st);

            fprintf(Dump, "#    ------------------------------------    #\n");
            fprintf(Dump, "#    -----------CONSTRUCKTED-------------    #\n");
            fprintf(Dump, "#    ------------------------------------    #\n");

            Dump_(st);
return ;
}

val_type Stack_hash(struct Stack* st)
{
    val_type sum = 0;

    for(int i = 0, sign = 1; i < st->size; i++, sign = -sign)
        sum += sign * (i + 1) * (st->data[i]);

        st->hash_sum = sum;

return sum;
}

void Canary(struct Stack *st){

    for (int i = 0; i < LEN_OF_CANARY;i++)
    {
        st->data[i] = (i)*2;
        st->canary[i] = (i)*2;
    }

    for (int i = LEN_OF_CANARY + st->capacity - 1  ,z = LEN_OF_CANARY -1, m = LEN_OF_CANARY  ;z >= 0;i++,z--,m++)
    {
        st->data[i] = z*2;
        st->canary[m] = z*2;
    }
}
void Push(struct Stack *st,val_type val)
{


    if (st->size == st->capacity)
    {
        st->capacity *= 2;
        st->data = (val_type*) realloc(st->data,st->capacity*sizeof(val_type)+2*LEN_OF_CANARY*sizeof(int));
    }

    for (int i = 2 * LEN_OF_CANARY + st->size; i > LEN_OF_CANARY + st->size;)
    {
        st->data[i]=st->data[i-1];
        i--;
    }

    st->data[LEN_OF_CANARY + st->size++] = val;

return;
}

int Stack_OK(const struct Stack* st)
{

     assert(st);

int problems  = 0;

    if(st->size < 0)
    {
        st->errors[BAD_SIZE] = 1;
        problems++;
    }


    if(st->size > st->capacity)
    {
        st->errors[BAD_SIZE_CAPACITY] = 1;
        problems++;
    }


    if(st->capacity < 0)
    {
        st->errors[BAD_CAPACITY] = 1;
        problems++;
    }

    //   val_type sum = st->hash_sum;
    //  if(sum != Stack_hash(st))
    //  return BAD_PROTACTION;

    for(int i = 0; i < LEN_OF_CANARY; ++i)

        if(st->data[i] != st->canary[i] || st->data[st->size +  LEN_OF_CANARY   + i] != st->canary[LEN_OF_CANARY + i])
        {

            st->errors[BAD_CANARY_DEAD] = 1;
            problems++;

        }

    if (problems == 0)

        return NO_PROBLEM;

    else

        return PROBLEMS;
}

val_type Pop(struct Stack *st)
{
    if (st->size <= 0)

        return 0;

    if ((st->size-1) * 4 <= st->capacity)
    {
        st->capacity /= 2;

        if (st->capacity == 0)
            st->capacity = 1;

        st->data = (val_type*) realloc(st->data,st->capacity*sizeof(val_type)+2*LEN_OF_CANARY*sizeof(int));
    }
        for (int i = LEN_OF_CANARY + st->size - 1; i <  LEN_OF_CANARY * 2 + st->size -1 ;)
    {
        st->data[i] = st->data[i+1];
        i++;
    }

    return st->data[--st->size];
}

void Dtor(struct Stack *st)
{
    Dump_(st);



    free(st->data);
    free(st->hash_sum);
    free(st->canary);
    free(st->print_format);

    st->size     = -1;
    st->capacity = -1;
    st->data     = NULL;
    st->hash_sum = 0;
    st->canary   = 0;

    st->hash_sum = NULL;
    st->canary = NULL;


    fprintf(Dump, "#    ------------------------------------    #\n");
    fprintf(Dump, "#    -----------DESTRUCKTED--------------    #\n");
    fprintf(Dump, "#    ------------------------------------    #\n");

    st = -1;

return;
}

void Dump_(const struct Stack* nameStack)
{
    int check  = Stack_OK(nameStack);

    fprintf(Dump, "#----------------------------------------------------------\n");
    fprintf(Dump, "# Stack nameStack\n");
    fprintf(Dump, "#    ----------date 08/11/2018--------------    #\n");
    fprintf(Dump, " [%p] \n\n", nameStack);


    if (check != 0)
    {
        for (int i = 0; i < 7;i++)
        {
            if (nameStack->errors[i] == 1)
                switch (i)
                {
                    case BAD_SIZE:
                        fprintf(Dump, "#    ----------ERROR with SIZE-----------    #\n");
                        fprintf(Dump, "#    size = %ld \n", nameStack->size);
                        fprintf(Dump, "#    ------------------------------------    #\n");
                        break;

                    case BAD_SIZE_CAPACITY:
                        fprintf(Dump, "#    ------ERROR with SIZE&CAPACITY------    #\n");
                        fprintf(Dump, "#    capacity = %ld\n", nameStack->capacity);
                        fprintf(Dump, "#    size = %ld \n", nameStack->size);
                        fprintf(Dump, "#    ------------------------------------    #\n");
                        break;

                    case BAD_CAPACITY:
                        fprintf(Dump, "#    ------ERROR with CAPACITY-----------    #\n");
                        fprintf(Dump, "#    capacity = %ld\n", nameStack->capacity);
                        fprintf(Dump, "#    ------------------------------------    #\n");
                        break;

                    case BAD_PROTACTION:
                        fprintf(Dump, "#    --------ERROR with PROTACTION-------    #\n");
                        fprintf(Dump, "#    hash_sum = %ld\n", nameStack->hash_sum);
                        fprintf(Dump, "#    Stack_hash = %ld ", Stack_hash(&nameStack));
                        fprintf(Dump, "#    ------------------------------------    #\n");
                        break;

                    case BAD_CANARY_DEAD:
                        fprintf(Dump, "#    --------ERROR with SIZE-------------    #\n");
                        fprintf(Dump, "#    capacity = %ld\n", nameStack->capacity);
                        fprintf(Dump, "#    size = %ld ", nameStack->size);
                        fprintf(Dump, "#    ------------------------------------    #\n");
                        break;

                    case NO_PROBLEM:

                    default :
                        break;
                }
        }
    }

    else

        if (check == 0)
        {
            fprintf(Dump, "#    ------------------------------------    #\n");
            fprintf(Dump, "#    -----------NO_PROBLEM---------------    #\n");
            fprintf(Dump, "#    ------------------------------------    #\n");
        }


    switch (sizeof(val_type))
    {
        case sizeof(char):

            for (int i = LEN_OF_CANARY; i < nameStack->size+LEN_OF_CANARY;i++)
            {
                fprintf(Dump, "#    ELEM ¹ [%d] = %c                  #\n",i-2 ,nameStack->data[i]);
            }

            break;

        case sizeof(int):

            for (int i = 0; i < nameStack->size+(2*LEN_OF_CANARY);i++)
            {
                fprintf(Dump, "#    ELEM ¹ [%d] = %d                  #\n",i ,nameStack->data[i]);
            }

            break;

        case sizeof(double):

            for (int i = LEN_OF_CANARY; i < nameStack->size+LEN_OF_CANARY;i++)
            {
                fprintf(Dump, "#    ELEM ¹ [%d] = %f                  #\n",i-2,nameStack->data[i]);
            }

            break;

        default:

            break;
    }

    fprintf(Dump, "\n#    capacity = %ld                    #\n", nameStack->capacity);
    fprintf(Dump, "#    size = %ld                          #\n", nameStack->size);
    fprintf(Dump, "#----------------------------------------------------------\n");

    fclose(Dump);

    Dump = fopen("DUMP.txt", "a");

    if (check != NO_PROBLEM)
        exit(1);

}
