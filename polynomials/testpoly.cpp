#include <iostream>
using namespace std;
#include "poly.h"


int main()
{
  Poly P1;				//Declare object representing polynomial P1
  P1[3] = 2; P1[1] = 3.6; P1[0] = 7;	//Specify coefficients of P1 = 2x^3 + 3.6x + 7
  
  Poly P2 = 5;				//Declare object representing polynomial P2 = 5
  P2[1] = 3; P2[2] = -6; P2[4] = 1;	//Specify additional coefficients of P2 = x^4 + 6x^2 + 3x + 5
  
  cout << "Polynomial P1: " << P1 << endl;	//Print P1 	
  cout << "Polynomial P2: " << P2 << endl;	//Print P2
  
  Poly P3 = P1 + P2;						//Add P1 and P2 	
  cout << "Sum of polynomials P1 and P2: " << P3 << endl;	//Print sum of P1 and P2
  
  P3 = P1 * P2;							//Multiply P1 by P2 	
  cout << "Product of polynomials P1 and P2: " << P3 << endl;	//Print product of P1 and P2

  P3 = 2 * P1;							//Multiply P1 by 2 	
  cout << "Polynomial P1 multiplied by 2: " << P3 << endl;	//Print product of P1 and 2
  
  double val = P1(3.14);						//Calculate the value of P1 at point 3.14
  cout << "Value of polynomial P1 at point 3.14: " << val << endl;	//Print the value of P1 at point 3.14
  
  const Poly P4 = P1;
  double val1 = P4.operator()(3.14);						//Calculate the value of P4 at point 3.14
  cout << "Value of polynomial P4 at point 3.14: " << val1 << endl;	//Print the value of P4 at point 3.14
  
  P3 = P4;
  
  Poly P0;
  P0[0] = 1; P0[1] = 2; P0[2] = 1; P0[3] = 7;
  cout << "P0: " << P0 << endl; //testowy
}
