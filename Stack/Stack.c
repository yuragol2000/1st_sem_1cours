#include "Stack.h"


struct Stack
{
    int size;
    int capacity;
    val_type *data;
    val_type *hash_sum;
    char print_format[3];
    val_type *canary;

};
/*struct Err
{
    bool BadSIZE;
    bool BadSIZE_CAPACITY;
    bool BadCAPACITY;
    bool BadPROTACTION;
    bool BadCANARYDEAD;

};*/
void Ctor(struct Stack *st)
{
    st->size = 0;
    st->capacity = 1;
    st->data = (val_type*)calloc(st->capacity + 2 * LEN_OF_CANARY,sizeof(val_type));
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
return ;
}
val_type Stack_hash(const struct Stack* st)
{
    val_type sum = 0;

    for(int i = 0, sign = 1; i < st->size; i++, sign = -sign)
        sum += sign * (i + 1) * (st->data[i]);

return sum;
}

void Canary(struct Stack *st){

    for (int i = 0; i < LEN_OF_CANARY;)
        st->data[i] = (++i)*2;

    for (int i = LEN_OF_CANARY + st->capacity - 1 ,z = 3;i < LEN_OF_CANARY * 2 + st->capacity ;i++,z--)
        st->data[i] = z*2;

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

enum errors Stack_OK(const struct Stack* st)
{

    enum errors error = NO_PROBLEM;
    if(st->size < 0)
        return BAD_SIZE; // ({error = BAD_SIZE; error});

    if(st->size > st->capacity)
        return BAD_SIZE_CAPACITY;

    if(st->capacity < 0)
        return BAD_CAPACITY;

    if(st->hash_sum != Stack_hash(st))
        return BAD_PROTACTION;

    for(int i = 0; i < LEN_OF_CANARY; ++i)
        if(st->data[i] != st->canary[i] || st->data[st->capacity + 2 * LEN_OF_CANARY - 1 - i] != st->canary[i])
            return BAD_CANARY_DEAD;

return NO_PROBLEM;
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
    st->size = -1;
    st->capacity = -1;

    free(st->data);
    free(st->hash_sum);
    free(st->canary);
    free(st->print_format);

    st->hash_sum = NULL;
    st->canary = NULL;
    st->data = NULL;

    fclose(Dump);

return;
}

void Dump_(const struct Stack* nameStack)
{

    fprintf(Dump, "#----------------------------------------------------------\n");
    fprintf(Dump, "# Stack nameStack");
    fprintf(Dump, " [%p] \n\n", nameStack);
    fprintf(Dump, "#        (!!!ERROR!!!)      #\n\n");

    switch (Stack_OK(nameStack))
    {
        case BAD_SIZE:
            fprintf(Dump, "#    ----------ERROR with SIZE-----------    #\n");
            fprintf(Dump, "#    size = %ld \n"             , nameStack->size);
            fprintf(Dump, "#    ------------------------------------    #\n");
            break;

        case BAD_SIZE_CAPACITY:
            fprintf(Dump, "#    ------ERROR with SIZE&CAPACITY------    #\n");
            fprintf(Dump, "#    capacity = %ld\n"      , nameStack->capacity);
            fprintf(Dump, "#    size = %ld \n"         ,     nameStack->size);
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

        default :
            break;
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
    fprintf(Dump, "#    size = %ld                        #\n", nameStack->size);
    fprintf(Dump, "#----------------------------------------------------------\n");

    fclose(Dump);

    Dump = fopen("DUMP.txt", "a");
}

int main()
{

    struct Stack st = {};
    Dump = fopen("DUMP.txt", "w");

    Ctor(&st);
    Dump_(&st);

    Push(&st,91);
    Push(&st,92);
    Push(&st,93);
    Push(&st,94);
    Push(&st,95);
    Push(&st,96);
    Push(&st,91);
    Push(&st,92);
    Push(&st,93);
    Push(&st,94);
    Push(&st,95);
    Push(&st,96);
    Push(&st,91);
    Push(&st,92);
    Push(&st,93);
    Push(&st,94);
    Push(&st,95);
    Push(&st,96);
    Push(&st,91);
    Push(&st,92);
    Push(&st,93);
    Push(&st,94);
    Push(&st,95);
    Push(&st,96);
    Push(&st,91);
    Push(&st,92);
    Push(&st,93);
    Push(&st,94);
    Push(&st,95);
    Push(&st,96);


    Dump_(&st);
    Pop(&st);
    Dump_(&st);
    Pop(&st);
    Dump_(&st);
    Pop(&st);
    Dump_(&st);
    Pop(&st);
    Pop(&st);
    Pop(&st);
    Pop(&st);
    Pop(&st);
    Dump_(&st);
    Dtor(&st);

    return 0;
}


