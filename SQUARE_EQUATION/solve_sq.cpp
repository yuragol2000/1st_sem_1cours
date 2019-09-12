#include "solve_sq.h"

/**
 *   @breaf Solving Square Equation
 *
 *  @function Solve_Square
 *  @function Linear_Equation
 *
 *
 *   @param [in] a a-coefficient
 *   @param [in] b b-coefficient
 *   @param [in] c c-coefficient
 *   @param [out] x1 the 1-st solution
 *   @param [out] x2 the 2-nd solution
 *
 *
 *   @return solutions, one of :
 *                             {
 *                                 NO_SOLUTION,
 *                                 ONE_SOLUTION,
 *                                 TWO_SOLUTION,
 *                                 INFINITY_ROOTS,
 *                                 TWO_COMPLEX_ROOTS
 *                             }
 *
 *  @date 19.09.2018
 *  @autors (C) YURAGOL, 2019
 *  @vercion 1.2
 */
int Solve_Square(const double& a, const double& b, const double& c,
                 double& x1, double& x2){

    assert(! isnan (a) );
    assert(! isnan (b) );
    assert(! isnan (c) );

    assert(! isinf (a) );
    assert(! isinf (b) );
    assert(! isinf (c) );

    assert(&x1 != NULL);
    assert(&x2 != NULL);
    assert(&x1 != &x2);



    if (a == 0)
    return Linear_Equation(b, c, x1);

    double D = b*b-4*a*c ;

    if (D == 0){

      x2 = x1 = -b/(2*a);

      return Roots::ONE_SOLUTION;
    }
    if (D > 0){

      double D_Sqrt = sqrt(D);

      x1 = ( (-b + D_Sqrt) / (2 * a) );
      x2 = ( (-b - D_Sqrt) / (2 * a) );

      return Roots::TWO_SOLUTION;
   }
   if (D < 0){

     double D_Sqrt = sqrt(-D);

     x1 = ( D_Sqrt / (2 * a) );
     x2 =  ( -b / (2 * a) );

     return Roots::TWO_COMPLEX_ROOTS;
   }
}
//------------------------------------------------------------------------------
/**
 *   @breaf Linear_Equation
 *
 *   @param [in] b b-coefficient
 *   @param [in] c c-coefficient
 *   @param [out] x1 the 1-st solution
 *
 *
 *   @return solutions, one of :
 *                             {
 *                                 ONE_SOLUTION,
 *                                 INFINITY_ROOTS
 *                             }
 *
 *  @date 19.09.2019
 *  @autors (C) YURAGOL, 2019
 *  @vercion 1.2
 */
//------------------------------------------------------------------------------
int Linear_Equation(const double b, const double& c, double& x) {

   assert(! isnan (b) );
   assert(! isnan (c) );

   assert(! isinf (b) );
   assert(! isinf (c) );

   assert(&x != NULL);

   if(fabs(b) < EPC){

     if(fabs(c) < EPC){

       return Roots::INFINITY_ROOTS;
     }

    return 0;//(c!=0)
   }

   else if (fabs(b) > EPC){

     x = (-c / b);

     return  Roots::ONE_SOLUTION;
   }
}
//------------------------------------------------------------------------------
