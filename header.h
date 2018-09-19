#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <math.h>
#include <stdio.h>
#include <assert.h>

#define INFINITY_ROOTS 3
#define TWO_COMPLEX_ROOTS -1
#define EPC 0.00001

int Solve_Square(double a, double b, double c, double *x1, double *x2);
int Linear_Equation(double b, double c, double *x1);


#endif // HEADER_H_INCLUDED
