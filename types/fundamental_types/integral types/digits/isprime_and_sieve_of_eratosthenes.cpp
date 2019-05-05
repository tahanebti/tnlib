/*
*       Lib Mathematics, Algorithms & Data structures
*       Author : Taha Nebti
*       github : github.com/tahanebti
*/


/*
*
*       check if number isPrime next we print all prime number in range from 2 to n-1
*       using seive of eratosthenes methode
*
*/

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    for(int i=2; i*i<=n; ++i){
        if(n%i==0)
            return false;
    }
    return true;
}

const int N=100000;
bool prime[N+1];
//or we can create a function named and we caled it in first line from main
int fast()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
//  freopen("input.txt", stdin);
//  freopen("output.text", stdout);
#endif

    time_t now = time(NULL);
    cout<<"The time and date "<<asctime(gmtime(&now))<<endl;
}

int main()
{
    fast();
    int n;
    cin>>n;
    if(isPrime(n))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
/*
    //its correct
   for(int i =0; i<=N ; ++i)
        prime[i] = false;
    prime[0] = prime[1] = false;     
        
   for(int i = 2; i*i <= N; ++i){ //loop to racine n
        if(prime[i] == false)
            continue;
        for(int j = i*i; j <= N; j += i){ //loop to factor of n
            prime[j] = false;
        }
    }     
*/        
     //more optimizing   
    for(int i =0; i<=N ; ++i)
        prime[i] = i%2!=0;
    prime[0] = prime[1] = false;
    prime[2] = true;
    for(int i = 3; i*i <= N; i+=2){ //loop to racine n
        if(prime[i] == false)
            continue;
        for(int j = i*i; j <= N; j += i+i){ //loop to factor of n
            prime[j] = false;
        }
    }


    for(int i=1; i<=100; ++i)
        if(prime[i])
            cout<<i<<" ";
    cout <<endl;
    return 0;
}
