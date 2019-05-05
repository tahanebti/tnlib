//
//  template
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS

//Template
#include <stdio.h>      //C io routine
#include <stdlib.h>
#include <ctype.h>      //char routine : isalpha...

#include <iostream>     //C++ io routine
#include <bits/stdc++.h>  //all bib

#include <algorithm>   //sort, lower_bound, min, max, next_permutation
#include <bitset>     //bit maniplulate, seive of Eratosthenes

#include <stack>      //stack best unsing to reverse
#include <queue>      //queue
#include <deque>      //deque
#include <set>        //balanced BST(RB tree) with key only
#include <map>        //balanced BST(RB tree) for key data paire
#include <vector>     //resizable array
#include <string>     //class string
#include <utility>    //pair , make_pair
#include <functional> //C++11

using namespace std;

//commun data type
typedef long long       ll;     //64 bits
typedef long double     ld;     //128 bits
typedef vector<int>       vi;
typedef pair<int, int>   ii;
typedef vector<ii>      vii;
typedef vector<bool>    vb;
typedef map<int, int>     mii;
typedef map<string, int>  msi;
typedef set<int>      si;

#define REP(i,a,b)    for(int i = int(a); i < int(b); ++i)
#define REPN(i,n)   REP(i, 0, int(n))
#define REPD(i,a,b)   for(int i=int(a); i>=int(b); --i)

#define TRvi(c, it)   for(vi::iterator it=(c).begin(); it!=(c).end() ; ++it)
#define TRvii(c, it)  for(vii::iterator it=(c).begin(); it!=(c).end() ; ++it)
#define TRmsi(c, it)    for(msi::iterator it=(c).begin(); it!=(c).end() ; ++it)

#define min(a,b)((a)<(b)?(a):(b))
#define max(a,b)((a)>(b)?(a):(b))

#define ONLINE_JUDGE



int fast()
{

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("input.txt", stdin);
  freopen("output.text", stdout);
#endif

  time_t now = time(NULL);
  cout<<"The time and date "<<asctime(gmtime(&now))<<endl;
}

//int int main(int argc, char const *argv[])
//int main()

//Modern C++
auto main() -> int
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 

  fast();
  return 0;


  cerr<<"Time Complexity : "<<double(clock()-1)/ CLOCKS_PER_SEC<<endl;
}
