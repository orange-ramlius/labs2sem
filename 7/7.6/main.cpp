#include <iostream>
using namespace std;

struct A {
  virtual void z() {}
};
struct B : A {
  int x;
  B(int y = 5) { x = y; }
};
B *f(A *pa) {
  if (!dynamic_cast<B *>(pa))
    throw 1;
  else
    return dynamic_cast<B *>(pa);
}
int main() {
  try {
    B b, *pb = f(&b);
    cout << pb->x << endl;
    A a;
    pb = f(&a);
    cout << pb->x << endl;
  } catch (...) {
  }
  return 0;
}
