#include <iostream>
using namespace std;

class A {
  // делаем снова публичным...
public:
  static int i;
  static void f() {
    if (i >= 0)
      i = -1, g();
    cout << "f()" << endl;
  }
  static void g() { // делаем статическим
    f();
    cout << "g()" << endl;
  }
};

int A::i = 1;
int main() {
  A::i = 1;
  const A a;
  a.f();
  a.i = 0;
  return 0;
}
