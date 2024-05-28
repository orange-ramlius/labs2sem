#include <iostream>

class C {
  int c;

public:
  C(int c) { this->c = c * 2; }

  int operator+(const C &c) { return (this->c + c.c); }

  int get() { return c; }
};

using namespace std;
int main() {
  C c1(7), c2 = 5, c3(c1 + c1);
  cout << c1.get() << ' ' << c3.get() << endl;
  return 0;
}
