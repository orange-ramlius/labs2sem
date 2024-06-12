#include <iostream>
using namespace std;

class A {
public: // делаем всё публичным
  static int i;
  static void f() {
    g();
    cout << "f()" << endl;
  }
  static void g() { // делаем статическим
    if (i >= 0)
      i = -1, f();
    cout << "g()" << endl;
  }
};
int A::i = 1;

int main() {
  A::i = 1;
  A a;
  a.f();
  a.i = 0;
  return 0;
}
