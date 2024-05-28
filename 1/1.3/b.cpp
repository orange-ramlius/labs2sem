#include <iostream>
using namespace std;

class X {
  int i;
  double t;
  // X() {
  //   i = 0;
  //   t = 1.0;
  //   cout << 1;
  // } private constructor, no need

public:
  X(int k = 0, double r = 1.5) {
    i = k;
    t = r;
    cout << 2;
  }
  X(const X &a) {
    i = a.i;
    t = a.t;
    cout << 3;
  }
};
int main() {
  // X a; no such constructor
  X b(1);
  X c(1.5, 2);
  X d = b;
  X e = 3;
  b = c = e;
  return 0;
}
