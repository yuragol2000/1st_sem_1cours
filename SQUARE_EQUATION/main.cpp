#include "solve_sq.cpp"
#include "unittest.cpp"


int main(){

  cout << "# Solve Square Equation (C) YURAGOL #\n";
  cout << "# Enter a, b, c \n\n";
//------------------------------------------------------------------------------

    double a = 0;
    double b = 0;
    double c = 0;

    double x1 = 0;
    double x2 = 0;


    if(!(cin >> a >> b >> c)) {

      cout << "# ERROR \n";

      return 0;
    }

    cout << "\n# Your INPUT \n";
    cout << "\ta = " << a << endl;
    cout << "\tb = " << b << endl;
    cout << "\tc = " << c << endl;

    double &nullReference = *(double*)0;//

    int n_Roots = Roots::ERROR;

    n_Roots = Solve_Square(a, b, c, x1, x2);//number of solutions

    switch (n_Roots){

      case Roots::NO_SOLUTION:
         printf("# No Solution \n");

         break;

      case Roots::ONE_SOLUTION:
         printf("# One Solution\n");
         printf("\tx = %lf \n", x1);

         break;

      case Roots::TWO_SOLUTION:
         printf("# Two Solution\n" );
         printf(" \tx1 = %lf \n",x1);
         printf(" \tx2 = %lf \n",x2);
         break;

      case Roots::INFINITY_ROOTS:
         printf("# An Infinity Number of solution\n ");

         break;

      case Roots::TWO_COMPLEX_ROOTS:
         printf("# Two Complex Roots\n");
         printf(" \tx1 = %lf + %lfi\n",x2, x1);
         printf(" \tx2 = %lf - %lfi\n",x2, x1);

         break;

      default :
         printf("# ERROR LOOL \n");
         printf("\t%d Roots\n",n_Roots);

         break;
     }


     //unittest();

   return 0;
}
//------------------------------------------------------------------------------
