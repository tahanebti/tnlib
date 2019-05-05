//
//  complexity
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS

/**
*       Complexity : input >= 0
*       - function do more work for move input
*       - drop all constant
*       - ignore lower order
*       - ignore the base of log
*       - 2n = O(n)
*
*          O(1)         : Constant time
*          O(log n )    : Logarithm                     tree
*          O(sqrt(n)    : Square root                   prime
*          O(n)         : Linear                        once per item  (
*          O(n log n)   : divide and conquer            mergeSort ,quickSort
*          O(n^2)       : Quadratic                     compare all x all
*          O(n^3)       : Cubic                         matrix multiplication
*          ---------------------------------------------Polynomial
*          O(2^n)       :
*          O(n!)        : factorial
*          O(n^n)       :
*          ---------------------------------------------Exponential
*
*/

/**
    Notes :

    GREEDY ALGORITHM: Takes the best/highest value first and moves to the lower values
    DIVIDE AND CONQUER: Smaller problems solved recursively and pulled together to form overall solution
    DYNAMIC PROGRAMMING: Smaller problems solved and stored and pulled together to form overall solution
    BACKTRACKING ALGORITHM: Builds and abandons candidates when determined one cannot be completed to a valid solution

**/

/**
    Notes :

    =====================================================================================================
    ARRAY SORTING     AVG SPD     SPACE    DESCRIPTION
    =====================================================================================================
    Quick Sort        O(NlogN)    O(logN)  Comparison, Recursive, Unstable, Fastest average though can get worst speed of O(N²)
    Heap Sort         O(NLogN)    O(1)     Comparison, In-place, Unstable, Removes top of heap and reconstructs
    Merge Sort        O(NlogN)    O(N)     Comparison, Recursive, Stable, Continually splits elements in half
    Radix Sort        O(NK)       O(N+K)   Distribution, Can be stable, Works on arrays of numbers
    Bucket/Bin Sort   O(NK)       O(N+K)   Distribution, Can be stable, Partitions into buckets
    Insertion Sort    O(N²)       O(1)     Comparison, In-place, Stable, Bad for large arrays
    Selection Sort    O(N²)       O(1)     Comparison, In-place, Can be stable, Bad for large arrays
    Bubble Sort       O(N²)       O(1)     Comparison, In-place, Stable, Swaps elements, Slowest of all sorts

**/

/**
    Notes :

    =====================================================================================================
    SEARCHING              AVG SPD   SPACE   TYPE         DESCRIPTION
    =====================================================================================================
    Binary Search          O(logN)   O(1)    Array        Sorted arrays, compares the value with the middle element
    Linear Search          O(N)      O(1)    Array        Unsorted arrays, Brute force checking
    Breadth-First Search   O(N+E)    O(N)    Graph/Tree   Traverses to all children before moving down a level
    Depth-First Search     O(N+E)    O(N)    Graph/Tree   Traverses graph to the greatest depth before backtracking
    A*                     O(E)      O(N)    Graph/Tree   Pathfinding using heuristics to traverse
**/

/**
    Kadane's Algorithm   Array    Find the maximum continuous subsequence in an array
    Euclid's Algorithm   2 ints   Find the largest integer that divides 2 integers
**/


int calcSum(int a, int b){      //O(1)
  int sum = a+b;
  return sum;
}

double calcAverage(int a, int b){       //O(1)
  double avg = (a+b)/2.0;
  return avg;
}

bool isAlphabit(char x){        //O(1)
  return (x>='A' && x<='Z' || x>='a' && x<='z');
}



double sumHarmonicSeries(int n){        //O(n)
  double sum = 0;
  for(int i = 1 ; i <= n ; ++i){
    sum += (1.0/i);
  }
  return sum;
}

long long calcSumSegment(int a, int b){     //O(b)
  long long sum = 0;
  for(int i = a ; i<=b ; ++i)
    sum += i;
  return sum;
}

int fact(int n){        //O(n)
  if(!n || n==1)    return 1;
  return n*fact(n-1);
}

int power1(int base, int power){        //O(power)
  if(!power)  return 1;
  return base*power1(base, power-1);
}



bool binarySearch(int A[],int val, int n){          //O(log(n))
  int lo = 0, hi = n, mid;
  while(lo<hi){
    mid = ((lo+hi)>>1);
    if(A[mid] == val) return 1;
    if(A[mid] < val)
      lo = mid+1;
    else
      hi = mid-1;
  }
  return 0;
}

int calcLog(int n){     //O(log(n))
    int ret = 0;
    while(n > 1){
        ++ret;
        n /= 2;
    }
  return ret;
}

int power2(int base, int power){        //O(log(n))
  if(!power)  return 1;
  int sub = power2(base, power>>1);
  return (power&1? sub*sub*base : sub*sub);
}




int fib(int n){     //O(2^n)
  if(!n || n==1)    return n;
  return fib(n-1)+fib(n-2);
}


/*
void searchArray(int B[], size_t n){        //O(n*log(n))
  for(int i = 0 ; i < n ; ++i){
    if(binarySearch(B[i], 0, n))
      puts("Found");
    else
      puts("Not Found");
  }
}

bool isComp[1008];
void something(){       //O(n*log(n))
  for(int i = 0 ; i < n ; ++i){
    if(!isComp[i]){
      for(int j = i ; j < n ; j+=i)
        isComp[i] = 1;
    }
  }
}

*/

void printPermutations(string s){       //O(n!)
  sort(s.begin(), s.end());
    do {
        cout << s << endl;
    } while(next_permutation(s.begin(), s.end()));
}




int rec_sum(int n){
    if(n==1) return 1;
    return n + rec_sum(n-1);
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a = 1000000001;
    cerr<<"O(1) : Constant static allocation : \t\t"<<double(clock()-1)/ CLOCKS_PER_SEC<<endl;

    cout<<"+-----------------------------------------------+"<<endl;

    int b = (int)malloc(sizeof(int));
    b = 1000000001;
    cerr<<"O(1) : Constant dynamic allocation: \t\t"<<double(clock()-1)/ CLOCKS_PER_SEC<<endl;

    cout<<"+-----------------------------------------------+"<<endl;

    int *ptr;
    ptr = (int*)malloc(sizeof(int));
   *ptr = 1000000001;
    cerr<<"O(1) : Dynamic allocation using malloc  : \t"<<double(clock()-1)/ CLOCKS_PER_SEC<<endl;
    free(ptr);

    cout<<"+-----------------------------------------------+"<<endl;

    ptr = new int;
    *ptr = 2000000001;
    cerr<<"O(1) : Dynamic allocation using new  : \t\t"<<double(clock()-1)/ CLOCKS_PER_SEC<<endl;
    delete ptr;

    cout<<"+-----------------------------------------------+"<<endl;

    cout<<calcSum(5, 6)<<endl; //O(1)
    cerr<<"O(1) : Math operation\t\t"<<double(clock()-1)/ CLOCKS_PER_SEC<<endl;

    cout<<"+-----------------------------------------------+"<<endl;
    int n = 10;
    int sum = 0;
    for(int i = 0; i<=n; ++i){
        sum+=i;
        cout<<i<<" + ";
   }
    cout<<" = "<<sum<<endl;
    cerr<<"O(n) : Linear Sum using loop \t\t\t"<<double(clock()-1)/ CLOCKS_PER_SEC<<endl;

    cout<<"+-----------------------------------------------+"<<endl;


    int sum_fn = n*(n+1)/2;
    cout<<sum_fn<<endl;
    cerr<<"O(1) : sum using math function : \t\t"<<double(clock()-1)/ CLOCKS_PER_SEC<<endl;

    cout<<"+-----------------------------------------------+"<<endl;

    cout<<rec_sum(n)<<endl;
    cerr<<"O(n) : Linear Sum using recursion \t\t"<<double(clock()-1)/ CLOCKS_PER_SEC<<endl;

    cout<<"+-----------------------------------------------+"<<endl;

    cout<<sumHarmonicSeries(6)<<endl;
    cerr<<"O(n) : sum harmonic series\t\t"<<double(clock()-1)/ CLOCKS_PER_SEC<<endl;

    cout<<"+-----------------------------------------------+"<<endl;

    cout<<calcSumSegment(5, 4)<<endl;
    cerr<<"O(b) : sum segment a_b \t\t"<<double(clock()-1)/ CLOCKS_PER_SEC<<endl;

    cout<<"+-----------------------------------------------+"<<endl;

    sum = 0;
    for(int i = 0; i<n; i+=2){
            sum+=i;
            cout<<i<<" + ";
    }
    cout<<" = "<<sum<<endl;
    cerr<<"O(n/k) : half Linear sum of pair \t\t\t\t"<<double(clock()-1)/ CLOCKS_PER_SEC<<endl;

    cout<<"+-----------------------------------------------+"<<endl;

    sum = 0;
    for(int i = 1; i<=n; i*=2){
        sum+=i;
        cout<<i<<" + ";
    }
    cout<<" = "<<sum<<endl;
    cerr<<"O(logn) : Logarithmic : \t\t\t"<<double(clock()-1)/ CLOCKS_PER_SEC<<endl;

    cout<<"+-----------------------------------------------+"<<endl;

    sum = 0;
    for(int i=n-1; i>0; i/=2){
        sum+=i;
        cout<<i<<" + ";
    }
    cout<<" = "<<sum<<endl;
    cerr<<"O(logn) : Logarithmic inverse : \t\t"<<double(clock()-1)/ CLOCKS_PER_SEC<<endl;

    cout<<"+-----------------------------------------------+"<<endl;

    sum = 0;
    for(int i = 1; i<sqrt(n); ++i){
        sum+=i;
        cout<<i<<" + ";
    }
    cout<<" = "<<sum<<endl;
    cerr<<"O(sqrtn) : Square Root \t\t\t\t"<<double(clock()-1)/ CLOCKS_PER_SEC<<endl;

    cout<<"+-----------------------------------------------+"<<endl;

    sum=0;
    for(int i = 0; i*i<n; i+=2){
            sum+=i;
            cout<<i<<" + ";
    }
    cout<<" = "<<sum<<endl;
    cerr<<"O(sqrtn) : Optimize Square Root \t\t"<<double(clock()-1)/ CLOCKS_PER_SEC<<endl;

    cout<<"+-----------------------------------------------+"<<endl;

    return 0;
}
