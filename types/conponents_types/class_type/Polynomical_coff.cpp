#include <iostream>
using namespace std;

struct Poly
{
   int degree;
   int *coeffs; // array of coefficients from lowest degree to highest degree
};

Poly* readPoly();
void outputPoly(const Poly* p, char x);
Poly* multPoly(const Poly* a, const Poly* b);

int main()
{

   cout << "First polynomial" << endl;
   Poly* a = readPoly();
   cout << "Second polynomial" << endl;
   Poly* b = readPoly();


   cout << "a = ";
   outputPoly(a, 'x');
   cout << "b = ";
   outputPoly(b, 'x');

   Poly* prodOfPoly = multPoly(a,b);
   cout << "d = ";
   outputPoly(prodOfPoly, 'x');

   return 0;
}

Poly* readPoly()
{
   int deg;
   int* A;
   cout << "Input the degree: ";
   cin >> deg;
   A = new int[deg+1]; //add 1 for constants

   cout << "Input coefficients: ";

   //assign coefficients
   for (int i = 0; i <= deg; i++){
      cin >> A[i];
   }

   cout << endl;

   //create the polynomial structure and assign values to the fields
   Poly* p;
   p = new Poly;
   p->degree = deg;
   p->coeffs = A;

   return p;
}
void outputPoly(const Poly* p, char x)
{
   for (int i = 0; i <= p->degree; i++){
      //coefficient is non-zero
      if ( p->coeffs[i] != 0){
         //exponent is 0
         if (i == 0) 
            cout << *(p->coeffs);
         //exponent is 1 and coefficient is 1
         else if ( i == 1 && p->coeffs[i] == 1) 
            cout << " + " <<  x;
         //exponent is 1 and coefficient is NOT 1
         else if ( i == 1 && p->coeffs[i] != 1) 
            cout << " + " << p->coeffs[i] << "*" << x;
         //exponent is > 1 and coefficient is 1
         else if ( p->coeffs[i] == 1) 
            cout << " + " << x << "^" << i;
         //coefficient is positive
         else if ( p->coeffs[i] > 0) 
            cout  << " + " << p->coeffs[i] << "*" << x << "^" << i;
         //coefficient is negative
         else if ( p->coeffs[i] < 0)
            cout  << " - " << -p->coeffs[i] << "*" <<  x << "^" << i;
      }
      //polynomial is a constant
      else if( p->coeffs[i] == 0 && p->degree == 0)
         cout << p->coeffs[i];
   }
   cout << endl;
}
Poly* multPoly(const Poly* a, const Poly* b)
{
   Poly* finalProduct;
   finalProduct = new Poly;
   finalProduct->degree = a->degree + b->degree; 

   int* productCoeffs = new int[finalProduct->degree + 1];

   for (int i = 0; i <= finalProduct->degree; i++){
      productCoeffs[i] = 0.0;
   }

   //solve for product of polynomials
   for (int i = 0; i <= a->degree; i++){
      for (int j = 0; j <= b->degree; j++)
      {
         productCoeffs[i + j] += a->coeffs[i] * b->coeffs[j];
      }
   }

   finalProduct->coeffs = productCoeffs;

   return finalProduct;
}

