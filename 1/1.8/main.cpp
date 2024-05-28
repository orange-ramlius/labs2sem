#include <iostream>

class B {
  int b = 0;

public:
  B(int a = 0, int b = 6) {
    if (a != 1 && b != 1)
      this->b = a * b - 1;
    else
      this->b = a * b;
  }

  B &operator+=(const B &b) {
    this->b += b.b;
    return *this;
  }

  int get() { return b; }
};

using namespace std;
int main() {
  B b1(1), b2(2, 3), b3(b1);
  b1 += b2 += b3;
  cout << b1.get() << ' ' << b2.get() << ' ' << b3.get() << endl;
  return 0;
}
