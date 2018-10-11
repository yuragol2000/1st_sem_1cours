//////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------//
//----------------------------------------------LIB---------------------------------------------//
//----------------------------------------------------------------------------------------------//
//////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "STEK.c"

int MAXELEMENTS = 100;

//////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------//
//--------------------------------------------MAIN----------------------------------------------//
//----------------------------------------------------------------------------------------------//
//////////////////////////////////////////////////////////////////////////////////////////////////

int main() {

    system ("chcp 1251");

    int i = 0, n = 0;
    float elem = 0;

    struct stack *stk = calloc(1,sizeof(struct stack));

    init(stk);

    printf("������� ���������� ��������� � �����: ");


    if (scanf("%d",&n) != 1){

        fputs("������ ������� ������",stdout);
        exit(1);
    }


    for(i = 0; i < n; i++){

        printf("������� ������� %d:", i);

        if (scanf("%f", &elem) != 1){

            fputs("������ ������� ������",stdout);
            exit(2);

        }

        push(stk,elem);
    }
        STK_PRINT(stk);

    do {

        printf("��������� ������� %f, ", pop(stk));
        printf("� ����� �������� %d ���������\n", gettop(stk));

        }

    while(isempty(stk) == 0);

return 0;
}
