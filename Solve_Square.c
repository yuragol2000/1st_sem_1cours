/**
 *   @breaf Solving Square Equation
 *
 *
 *
 *
 *   @param [in] a a-coefficient
 *   @param [in] b b-coefficient
 *   @param [in] c c-coefficient
 *   @param [out] x1 the 1-st solution
 *   @param [out] x2 the 2-nd solution
 *
 *
 *   @return all solutions
 *   @todo a
 *   @warning LOLLL!!!
 *  @note Use it carefully!!!
 *
 *  @autors (C) YURiGOL, 2018
 */

#include "header.h"


//-------------------------------------------------------------------------------
int Solve_Square(double a, double b, double c, double *x1, double *x2) {

    assert(! isnan (a) );
    assert(! isnan (b) );
    assert(! isnan (c) );

    assert(! isinf (a) );
    assert(! isinf (b) );
    assert(! isinf (c) );

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);



    if (a == 0)
        return Linear_Equation(b, c, x1);

    double D = b * b - 4 * a * c  ;

    if (D == 0)
        {

        *x2 = *x1 = -b / (2 * a);
        return 1;

        }
    if (D > 0)
    {
        double D_Sqrt = sqrt(D);
        *x1 = ( (-b + D_Sqrt) / (2 * a) );
        *x2 = ( (-b - D_Sqrt) / (2 * a) );
        return 2;
    }

    if (D < 0)

    {


            double D_Sqrt = sqrt(-D);
            *x1 = ( D_Sqrt / (2 * a) );
            *x2 =  ( -b / (2 * a) );
            return TWO_COMPLEX_ROOTS;
    }
}
//-------------------------------------------------------------------------------

int Linear_Equation(double b, double c, double *x) {
    assert(! isnan (b) );
    assert(! isnan (c) );

    assert(! isinf (b) );
    assert(! isinf (c) );

    assert(x != NULL);

        double eps =  0.00001;
     if(fabs(b) < eps)
        {
            if ((fabs(c) < eps))
                return INFINITY_ROOTS;
                return 0;//(c!=0)
        }

    else
        {
            *x = (-c / b);
            return 1;
        }
}
//-------------------------------------------------------------------------------
