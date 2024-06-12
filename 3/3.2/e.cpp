int x = 4;
class A {
  int x;

public:
  A(int n = 1);
  int f(int a = 0, int b = 0);
};

class B : public A {
public:
  int x;
  B(int n = 2);
  int f(int a);
};
class C : public B {
  int x;

public:
  C(int n = 3);
  int f(int a, int b);
  int g(A *p);
};
int main() {
  A *p;
  B b;
  C c;
  A a = c;
  struct D {
    B b;
    D() : b(5) {}
  } d;
  p = &b;
  x = c.g(&c);
  x = c.A::f();
  x = c.B::f(x);
  x = c.f(x, 1);
  x = p->f();
  x = p->f(x);
  x = p->f(x, 1);
  return 1;
  // constructors
  // AB
  // ABC
  // апкаст к родителю
  // B
  // D
  // апкаст, again
  // destructors
  // D
  // B
  // A
  // CBA
  // BA
}
