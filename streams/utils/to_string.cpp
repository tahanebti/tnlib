//
//  to_string
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}



template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}



void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

string my_itoa(int number ){
    string ss="";   
    while(number) {
        int rem=number%10;
        char i= rem + '0';
       number /=10;
        ss +=i;      //append new character at the front of the string!
    }
    return ss;
}

string to_string(int number){
  std::string s=" ";
  std::stringstream out;
  out << number;
 return out.str();
}



template <typename T>
T lexical_cast(const std::string& str){
    T var;
    std::istringstream iss;
    iss.str(str);
    iss >> var;
    // deal with any error bits that may have been set on the stream
    return var;
}
