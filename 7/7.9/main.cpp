#include <iostream>
using namespace std;

struct A {
  int x;
  virtual void z() {}
};
struct B : A {
  int x;
};
struct C : B {
  int x;
  C(int n = 4) { x = n; }
};

C *f(B &rb) {
  C *pc = dynamic_cast<C *>(&rb);

  if (!pc)
    throw 0;

  return pc;
}

int main() {
  C c, *pc = f(c);
  cout << pc->x << endl;
  return 0;
}
