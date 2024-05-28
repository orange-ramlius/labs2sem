#include <iostream>
using namespace std;

class B {
  int b;

public:
  B() {
    this->b = 10;
    cout << 1;
  }

  B(const B &b) {
    if (b.b == 10) {
      this->b = b.b * 2;
    } else {
      this->b = b.b * 1.5;
    }
    cout << 2;
  }

  int get() { return b; }
};

int main() {
  B b1, b2 = b1, b3(b2);
  cout << b1.get() << b2.get() << b3.get() << endl;
  return 0;
}
