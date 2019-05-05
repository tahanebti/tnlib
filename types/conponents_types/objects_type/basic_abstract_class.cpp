#include <bits/stdc++.h>
using namespace std;

class Parent { //abstract expression
protected:
    virtual void foo1() = 0; //primitive operation, don't wanna give access to public
    virtual void foo2() = 0; //primitive operation, don't wanna give access to public

public:
    void publicFoo(){ //template method
        this -> foo1();
        this -> foo2();
        //maybe does other things too
    }; // this is what the user will call

};

class ChildA: public Parent { //terminal expression
protected:
    void foo1() override; //whatever implementation
    void foo2() override; //whatever implementation

};

class ChildB: public Parent{ //terminal expression
protected:
    void foo1() override; //whatever implementation
    void foo2() override; //whatever implementation

};

class ChildC: public Parent { //non terminal expression
   std::vector<Parent*> parents;
protected:
    void foo1() override {
        for ( auto p: parents){
            p->foo1(); //calls correct foo1 depending on what p truly is (this does not compile)
        }
    }
    void foo2() override {
        for ( auto p: parents){
            p->foo2(); //calls correct foo2 depending on what p truly is (this does not compile)
        }
    }
};

int main() {
  // your code goes here
  return 0;
}
