#include <iostream>
using namespace std;

struct A {
  virtual void z() {}
};
struct B : A {
  int x;
  B(int n = 7) { x = n; }
};
B *f(void *p) {
  B *pb = dynamic_cast<B *>(static_cast<A *>(static_cast<void *>(p)));
  if (!pb) {
    throw 0;
  }
  return pb;
}
int main() {
  B b, *pb = f(&b);
  cout << pb->x << endl;
  return 0;
}
