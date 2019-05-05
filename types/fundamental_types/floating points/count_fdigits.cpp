#include <bits/stdc++.h>
using namespace std;
void my_double(){
  double d = sqrt(1/floor(pow(10,104)-1));
  int digit = floor(log(pow(2,53))/log(10));
//cout<<"\ndouble = "<<d<<" up to ~= "<<digit<<" digits = "<<fixed<<setprecision(52)<<d;
}

void my_float(){
  float f = sqrt(1/floor(pow(10,46)-1));
  //cout<<"Float = "<<f<<" = "<<fixed<<setprecision(23)<<f;
}


int main() {

float f = sqrt(1/floor(pow(10,46)-1));
int fdigit = floor(log(pow(2,24))/log(10));
cout<<"Float = "<<f<<" = "<<" up to ~= "<<fdigit<<" digits  ";

double d= sqrt(1/floor(pow(10,104)-1));
int ddigit = floor(log(pow(2,53))/log(10));


cout<<"\nDouble = "<<d<<" up to ~= "<<ddigit<<" digits  ";

  return 0;
}
