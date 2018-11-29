#include "Stack.c";
#include "unittest.C"

int main()
{

    struct Stack st = {};

    Dump = fopen("DUMP.txt", "w");

    Ctor(&st);

    test(&st);

    Dtor(&st);

    return 0;
}
