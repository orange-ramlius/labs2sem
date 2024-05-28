#include <iostream>

class C {
  int c;

public:
  C(int c) { this->c = c * 2; }

  C(const C *c) { this->c = c->c; }

  C *operator+(const C &c1) { return new C(this->c + c1.c); }

  int get() { return c; }
};

using namespace std;
int main() {
  C c1(7), c2 = 5, c3(c1 + c2);
  cout << c1.get() << c2.get() << c3.get() << endl;
  return 0;
}
