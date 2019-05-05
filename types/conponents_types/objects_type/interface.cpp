#include <iostream>
using namespace std;

struct Base {
  Base() {
    foo();
  }
  virtual ~Base() = default;
  Base(Base const&) = default;
  Base(Base&&) = default;
  Base& operator=(Base const&) = default;
  Base& operator=(Base&&) = default;

  virtual void foo() {
    std::cout << "Base::foo\n";
  }
};

struct Derived : public Base {
  virtual void foo() override {
    std::cout << "Derived::foo\n";
  }
};

int main() {
  Derived d; //prints Base::foo
return 0;
}
