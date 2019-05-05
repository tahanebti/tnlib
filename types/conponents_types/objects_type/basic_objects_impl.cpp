#include <bits/stdc++.h>
using namespace std;

class Object{
    int _no;
public:
    Object(){cout<<"default constructor "<<endl;}
    Object( int no ) :_no( no ) { cout<<"arguments constructor "<<endl;}

   Object(const Object& other){
    cout<<"copy constructor "<<endl;
    _no = other._no;
}
   Object& operator=(const Object& other){
    cout<<"copy assignments operator "<<endl;
    if(this == &other)
        return *this;

  _no = other._no;
  return *this;
}



   ~Object(){cout<<"default deconstructor "<<endl;}

   int getData()const{return _no;}

  friend ostream& operator<<(ostream& os, Object&);

};

inline ostream& operator<<(ostream& os, Object& o){
return os<<o.getData();
}

template<typename T>
void call(T &&arg){
  //check(arg);
  //check(static_cast<T>(arg));
   check(forward<T>(arg));
}

void check(Object& o){
  cout<<"lvalue"<<endl;
}

void check(Object&& o){
  cout<<"rvalue"<<endl;
}

int main() {
   Object p(5);
   cout<<typeid(p).name()<<endl;
   cout<<sizeof(p)<<endl;
   cout<<p.getData()<<endl;
   call(p); //lvalue
   call(Object()); //rvalue
   Object q(p);
   q = p;
    return 0;
}
