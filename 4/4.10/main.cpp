#include <iostream>
using namespace std;

class A {
  int i;

public:
  A(int x) {
    i = x;
    cout << "dog" << endl;
  }
  virtual ~A() { cout << "cat" << endl; }
  int f() const { return i + g() + h(); }
  virtual int g() const { return i; }
  int h() const { return 5; }
};
class B : public A {
public:
  B() : A(21) { cout << "sheep" << endl; }
  ~B() { cout << "horse" << endl; }
  int f() const { return g() - 3; }
  virtual int g() const { return 7; }
  int h() const { return 9; }
};
int main() {
  B b;
  A *p = &b;
  cout << "result = (" << p->f() << ';' << b.f() << ')' << endl;
  return 0;
}

/* output
dog
sheep
result = (33;4)
horse
cat
*/
