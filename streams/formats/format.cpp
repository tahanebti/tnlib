/**
       format
       Author : Taha Nebti
       github : github.com/tahanebti


      Notes : 

      Using Streams
      cin An input stream, reads data from the “input console.”
      cout A buffered output stream, writes data to the output console.
      cerr An unbuffered output stream, writes data to the “error console”
      clog A buffered version of cerr.

**/

#include <bits/stdc++.h>

using namespace std;

int main()
{

//Set integral representation: default: dec
cout<< dec << 0xF; //prints 16
cout<< hex << 16; //prints 0xF
cout<< oct << 8; //prints 10  

//bit representation
std::cout << std::bitset<32>(3.45f); // (32: num. of bits)
// print 01000000010111001100110011001101

//Print true/false text:
cout<< boolalpha << 1; //prints true
cout<< boolalpha << 0; //prints false

//Set decimal precision: default: 6
cout << setprecision(2) << 3.538; ! 3.54

//Set float representation: default: std::defaultfloat
cout << setprecision(2) << fixed << 32.5;       // 32.50
cout << setprecision(2) << scientific << 32.5; // 3.25e+01

//Set alignment: default: right
cout << right << setw(7) << "abc" << "##"; // ____abc##
cout << left << setw(7) << "abc" << "##"; // abc___##
//(better than using tab nt)

         bool boolValue = true;
          cout << "Value \"" << std::boolalpha << boolValue
               << "\" was parsed as " << std::noboolalpha << boolValue;

          int number = 42;
          cout.setf(ios::hex, ios::basefield);
          cout.setf( ios::showbase);
          cout<<"hex :" <<number<<endl;

          cout.setf(ios::oct, ios::basefield);
          cout.setf( ios::showbase);
          cout<<"octal  :" <<number<<endl;

          cout<<"binary : "<<bitset<8>(number)<<endl;
          cout.setf(ios::dec, ios::basefield);


          float f = 42.5f;
                double d = 42.00000000005;
                //set the format of the numeric output
                cout<<"scientific"<<scientific<<endl;
                cout<<f<<endl;
                cout<<d<<endl;
                cout<<"showpoint"<<showpoint<<endl;
                cout<<f<<endl;
                cout<<d<<endl;
                cout<<"fixed"<<fixed<<endl;
                cout<<f<<endl;
                cout<<d<<endl;
                //form <iomanip>
                cout<<"setprecision"<<setprecision(4)<<endl;
                cout<<f<<endl;
                cout<<d<<endl;
                typedef std::numeric_limits<long double> ld;
                const long double pi = std::acos(-1.L);
                cout << '\n'
                      << "default precision (6): pi: " << pi << '\n'
                      << " 10pi: " << 10 * pi << '\n'
                      << "std::setprecision(4): 10pi: " << std::setprecision(4) << 10 * pi << '\n'
                      << " 10000pi: " << 10000 * pi << '\n'
                     //   << "std::fixed: 10000pi: " << std::fixed << 10000 * pi << std::defaultfloat <<'\n'
                      << "std::setprecision(10): pi: " << std::setprecision(10) << pi << '\n'
                      << "max-1 radix precicion: pi: " << std::setprecision(ld::digits - 1) << pi << '\n'
                      << "max+1 radix precision: pi: " << std::setprecision(ld::digits + 1) << pi << '\n'
                      << "significant digits prec: pi: " << std::setprecision(ld::digits10) << pi << '\n';
               cout << "-------------------------------------" << '\n';
          // need <locale> header
          //cout.imbue(std::locale("en_US.utf8"));
          cout << std::left << std::showbase << std::setfill('*')
               << "flt: " << std::setw(15) << -9.87 << '\n'
               << "hex: " << std::setw(15) << 41 << '\n'
               << " $: " << std::setw(15) << std::put_money(367, false) << '\n'
               << "usd: " << std::setw(15) << std::put_money(367, true) << '\n'
               << "usd: " << std::setw(15)
              << std::setfill(' ') << std::put_money(367, false) << '\n';
  return 0;
}
      
