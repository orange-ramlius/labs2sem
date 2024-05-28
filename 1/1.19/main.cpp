#include <iostream>
using namespace std;

struct B {
  float x;
  B(float a = 0) {
    x = a;
    cout << 5;
  }
  virtual ~B() { cout << 2; }
};
struct D : B {
  D() : B() { cout << 3; }
  ~D() { cout << 4; }
};

int main() {
  B *p1 = new B(1), *p2 = new D[2];
  delete p1;
  delete[] p2;
  return 0;
}

// очень странная шутка, что предыдущий бинарник выводит все правильно
// а когда я компилирую по новой, то вывод другой -_-
