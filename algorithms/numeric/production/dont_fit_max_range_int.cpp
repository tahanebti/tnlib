#include <bits/stdc++.h>
using namespace std;

int main() {
   //prod overflow : don't fit max int ~ 9 digit
    int m = std::numeric_limits<int>::max() , p=1;
    for(int i=1; i<100; ++i){
   //(p* i < max)
    if(p < m / i)
         cout<<((p *=i))<<endl;
}
    return 0;
}
