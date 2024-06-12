int x = 4;
class A {
  int x;

public:
  A(int n = 3);
  int f(int a = 0, int b = 0);
};
class B : public A {
  int x;

public:
  B(int n = 1);
  int f(int a = 0);
};
class C : public B {
  int x;

public:
  C(int n = 2);
  int f(int a, int b);
  int g(A *p);
};
int main() {
  A *p;
  B b;
  C c;
  class D {
    B b;
    A a;

  public:
    D() : a(b) {}
  } d;
  p = &b;
  x = c.g(&b);
  x = c.B::f();
  x = c.B::f(x);
  x = c.f(x, 1);
  x = p->f();
  x = p->f(x);
  x = p->f(x, 1);
  return 2;
  // constuctors
  // AB
  // ABC
  // AB
  // A
  // D
  // desctructors
  // все что выше в обратном порядке
}
