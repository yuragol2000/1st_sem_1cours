
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "Solve_Square.c"


//--------------------------------------------------------------

int main()
{

    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    printf("# Enter a, b, c \n");
    scanf("%lf %lf %lf" , &a, &b, &c);
    int n_Roots = Solve_Square(a, b, c, &x1, &x2);

    switch (n_Roots)
    {
     case 0:
        printf("# No Solution \n");
        break;

     case 1:
        printf("# One Solution x = %lf \n", x1);
        break;

     case 2:
        printf("# Two Solution \nx1 = %lf \nx2 = %lf \n", x1, x2);
        break;

     case INFINITY_ROOTS://*  */
        printf("# An Infinity Number of solution\n ");
        break;

     case TWO_COMPLEX_ROOTS:
        printf("# Two Complex Roots\n");
        break;

     default :
        printf("# ERROR LOOL\n");
        break;
    }
    return 0;
}
//-----------------------------------------------------------------------
