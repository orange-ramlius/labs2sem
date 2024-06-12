#include <iostream>
using namespace std;

class A {
  int i;

public:
  A(int x) { i = x; }
  A(const A &y) { i = y.i; }    // больше const!
  const A f(const A &z) const { // ещё больше!!!
    cout << endl;
    return *this;
  }
};
const A t1() {
  const A a = 5;
  return a.f(a);
}
