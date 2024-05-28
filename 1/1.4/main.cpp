#include <iostream>

class A {
  int a;

public:
  A(int a = 0) { this->a = a; }

  A &operator=(const int a) {
    this->a = a;
    return *this;
  }

  A &operator*=(const int a) {
    this->a *= a;
    return *this;
  }

  A &operator*=(const A &a) {
    this->a *= a.a;
    return *this;
  }

  int get() { return a; }
};

using namespace std;
int main() {
  A a1(5), a2 = 3;
  a1 *= 10;
  a2 *= a1 *= 2;
  cout << a1.get() << a2.get() << endl;
  return 0;
}
