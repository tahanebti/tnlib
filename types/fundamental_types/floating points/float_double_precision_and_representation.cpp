/*
*       Lib Mathematics, Algorithms & Data structures
*       Author : Taha Nebti
*       github : github.com/tahanebti
*/


/*
        Float / double point precision
*/

#include <bits/stdc++.h>
using namespace std;

int get_base(double number){
    return floor(number);
}

int count_digit_base(double number){
    int res = get_base(number);
    return ceil(log(res)/log(10));
}

double get_mantissa(double number){
    double res = fmod(number, 1);
    return res;
}

int count_digit_mantissa(double number){
    double res = get_mantissa(number);
    string s, l;
    stringstream out;
    out << res;
    s = out.str();
    l = s.substr(s.find('.')+1);
    return l.length();
}

int main()
{

    double number = 123.456;
    cout<<get_base(number)<<endl;
    cout<<get_mantissa(number)<<endl;
    cout<<count_digit_base(number)<<endl;
    cout<<count_digit_mantissa(number)<<endl;

    //float IEEE 764 representation
    string sign = (number>0 ? "+" : "-");
    float base = sqrt(floor(pow(2,6)));
    float mantissa = sqrt(1/floor(pow(10,46)-1));
    cout<<"sign : "<< sign <<", base : "<<base<<" bits , mantissa : "<<mantissa<<" bits = "
        <<fixed<<setprecision(23)<<mantissa;

    return 0;
}
