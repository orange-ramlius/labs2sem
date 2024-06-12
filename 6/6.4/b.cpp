#include <iostream>

class A {
public:
  static const char a;
  static void f() { std::cout << 1; }
};

const char A::a = '+';
int main() {
  A ob;
  A::f();
  return 0;
}
