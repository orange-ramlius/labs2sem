#include <iostream>
using namespace std;

struct B {
  int x;
  B() {
    x = 7;
    cout << 7;
  }
  virtual ~B() { cout << 8; }
};
struct D : B {
  D(int d = 7) {
    x = d;
    cout << 6;
  }
  ~D() { cout << 9; }
};
int main() {
  B *p1 = new B[1], *p2 = new D[1];
  delete[] p1;
  delete[] p2;
  return 0;
}
