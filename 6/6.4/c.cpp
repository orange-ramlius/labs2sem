#include <iostream>

class A {
public:
  static void g() { std::cout << 1; }
  void h() const { std::cout << 2; }
};

int main() {
  const A x;
  A::g();
  x.h();
  return 0;
}
