#include <iostream>
using namespace std;

struct B {
  int x;
  B(int a = 0) {
    x = a;
    cout << 1;
  }
  virtual ~B() { cout << 3; }
};
struct D : B {
  D(int d) : B(d) { cout << 6; }
  ~D() { cout << 4; }
};
int main() {
  B *p1 = new B[2], *p2 = new D(1);
  delete[] p1;
  delete p2;
  return 0;
}
