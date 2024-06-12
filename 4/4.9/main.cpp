#include <iostream>
using namespace std;

class A {
  int i;

public:
  A(int x) {
    i = x;
    cout << "mercury" << endl;
  }
  virtual ~A() { cout << "venus" << endl; }
  int f() const { return 96; }
  virtual int g() const { return i; }
  int h() const { return i - f() - g(); }
};
class B : public A {
public:
  B(int x) : A(x + 20) { cout << "earth" << endl; }
  ~B() { cout << "mars" << endl; }
  int f() const { return 8; }
  virtual int g() const { return 3; }
  int h() const { return f() + g(); }
};

int main() {
  B b(17);
  A *p = &b;
  cout << "result = (" << p->h() << ';' << b.h() << ')' << endl;
  return 0;
}
/* output
mercury
earth
result = (-62;11)
mars
venus
*/
