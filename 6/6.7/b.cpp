#include <iostream>
using namespace std;

class A {
  int i;

public:
  A(int x) { i = x; }
  A(const A &y) { i = y.i; } // и туть, если я не перепутал
  const A f(const A &c) const { // туть
    cout << c.i << endl;
    return *this;
  }
};
const A t1(const A a) {
  A b = A(5);
  return b.f(a);
}
