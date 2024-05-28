#include <iostream>

class A {
  int a;

public:
  A(int a = 7) { this->a = a; }

  A &operator=(const int a) {
    this->a = a;
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
  A a1(5), a2 = 4, a3;
  a2 *= a1 *= 3;
  cout << a1.get() << ' ' << a2.get() << ' ' << a3.get() << endl;
  return 0;
}
