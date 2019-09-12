void Print(const int& i,const int& n_Roots,const double& a,const double& b,const double& c,
   const double& x1,const double& x2){

     printf("Solving Equation №%d\n\n",i);

     printf("\ta = %lf\n",a);
     printf("\tb = %lf\n",b);
     printf("\tc = %lf\n\n",c);

     switch (n_Roots){

       case Roots::NO_SOLUTION:
          printf("# No Solution \n");

          break;

       case Roots::ONE_SOLUTION:
          printf("# One Solution\n\n");
          printf("\tx = %lf \n\n", x1);

          break;

       case Roots::TWO_SOLUTION:
          printf("# Two Solution\n\n" );
          printf(" \tx1 = %lf \n",x1);
          printf(" \tx2 = %lf \n\n",x2);
          break;

       case Roots::INFINITY_ROOTS:
          printf("# An Infinity Number of solution\n ");

          break;

       case Roots::TWO_COMPLEX_ROOTS:
          printf("# Two Complex Roots\n\n");
          printf(" \tx1 = %lf + %lfi\n",x2, x1);
          printf(" \tx2 = %lf - %lfi\n\n",x2, x1);

          break;

       default :
          printf("# ERROR LOOL \n");
          printf("\t%d Roots\n",n_Roots);

          break;
      }


   }

void unittest(void){

  double x1 = 0;
  double x2 = 0;

  double a = 0;
  double b = 0;
  double c = 0;

  int n_Roots = 0;
  int i = 0;

  {
    n_Roots = Solve_Square(1,-13, 12, x1, x2);

    Print(i++,n_Roots,1,-13, 12, x1, x2);

    assert(n_Roots == Roots::TWO_SOLUTION);
    assert((x1 == 1 && x2 == 12) || (x2 == 1 && x1 == 12));

    printf("Equation №%d Solved\n\n\n",i);
  }

  {
    n_Roots = Solve_Square(1,-7, 12, x1, x2);

    Print(i++,n_Roots,1,-7, 12, x1, x2);

    assert(n_Roots == Roots::TWO_SOLUTION);
    assert((x1 == 3 && x2 == 4) || (x2 == 3 && x1 == 4));

    printf("Equation №%d Solved\n\n\n",i);
  }

  {

    n_Roots = Solve_Square(1,-6, 9, x1, x2);

    Print(i++,n_Roots,1,-6, 9, x1, x2);
    assert(n_Roots == Roots::ONE_SOLUTION);
    assert((x1 == 3 && x2 == 3) );

    printf("Equation №%d Solved\n\n\n",i);
  }
  {
    a = 1;
    b = -6;
    c = 9;


    n_Roots = Solve_Square(a, b, c, x1, x2);

    Print(i++,n_Roots, a, b, c, x1, x2);

    assert(n_Roots == Roots::ONE_SOLUTION);
    assert((x1 == 3 && x2 == 3) );

    printf("Equation №%d Solved\n\n\n",i);
  }
}
