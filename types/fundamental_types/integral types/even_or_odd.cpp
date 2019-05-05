/*
*	     Mathematics, Algorithms & Data structures
*   	 Author : Taha Nebti
*      	 github : github.com/tahanebti
*/
	int n = 10;
    //print even number in 10 times
    for(int i=0; i<n; ++i){
        cout<<2*i<<" ";
    }
    
    //print odd number in 10 times
    for(int i=0; i<n; ++i){
        cout<<2*i+1<<" ";
    }
    cout<<endl;

    //print even number in range[0..10]
    //complexity O(n)
    for(int i=0; 2*i<n; ++i){
        cout<<i<<" ";
    }
    
    //print even number in range[0..10]
    //complexity (n/2) more better
    for(int i=0; i<n; i+=2){
        cout<<i<<" ";
    }

    
    
    






















#include <bits/stdc++.h>
using namespace std;

//.isEven or Odd -> if number % 2 == 0 is odd else is Even
string even_or_odd(int number){
    return (number % 2 == 0) ? "is Even" : "is Odd";
}

//using bitwise operator -> if last bit is 1 return is Even else 0 return Odd
string even_or_odd1(int number){
	return (number & 1) ? "is Even" : "is Odd";
}

int main()
{
	/*
		check the parity of random number in range[0..10]
	*/

    int n = 10;
    srand((unsigned)time(0));
    for(int i=0; i<n; ++i){
        int r = (rand()  % n) + 1;
        cout<<r<<" "<<even_or_odd(r)<<endl;;
    }

    return 0;
}

























#include <bits/stdc++.h>
using namespace std;		

//.isEven or Odd -> if number % 2 == 0 is odd else is Even
string even_or_odd(int number){
    return (number % 2 == 0) ? "is Even" : "is Odd";
}

//using bitwise operator -> if last bit is 1 return is Even else 0 return Odd
string even_or_odd1(int number){
	return (number & 1) ? "is Even" : "is Odd";
}

/*
	-> Mod operator is slow and it very bad when using for a bignumber
	->sometimes problem solution depends on the equation
        a % b = a - b * [a/b]  
        7 % 3 = 3 - 3 * 2 = 1
*/
int modulo(int a, int b){
    return a - b * (a/b);
}

int int main(int argc, char const *argv[])
{
	int number;
	cin>>number;

	cout<<even_or_odd(number)<<endl;

	//call modulo function
	if(modulo(number) == 0) 
		cout<<"if Even"<<endl;
	cout<<"is Odd"<<endl; 

		return 0;
}
