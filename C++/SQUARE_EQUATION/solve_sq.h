#ifndef SQ_H
#define SQ_H

#include <iostream>
#include <cassert>
#include <math.h>
#include <limits>

using namespace std;
#define EPC 0.00001

int Linear_Equation(const double b, const double& c, double& x);
int Solve_Square(const double& a, const double& b, const double& c,
                 double& x1, double& x2);

enum Roots {
  NO_SOLUTION = 10,
  ONE_SOLUTION,
  TWO_SOLUTION,
  INFINITY_ROOTS,
  TWO_COMPLEX_ROOTS,
  ERROR
};


#endif
