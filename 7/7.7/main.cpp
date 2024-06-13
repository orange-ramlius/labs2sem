#include <iostream>
using namespace std;

struct A {
  virtual void z() {}
};
struct B : A {};
struct C : B {
  int x;
  C(int n = 3) { x = n; }
};

C &f(A &ra) {
  B *pb = dynamic_cast<B *>(&ra);
  if (!pb)
    throw 0;
  C *pc = dynamic_cast<C *>(pb);
  if (!pc) {
    throw 0;
  }
  return *pc;
}

int main() {
  C c, &pc = f(c); // если использовать амперсанд то не работает, т.к. &c
                   // воспринимается как указатель -_-, а не ссылка
  cout << pc.x << endl;
  return 0;
}
