int x = 0;
int f() { return x = 1; }
class A {
  int x;

public:
  A(int n = 2) { x = n; }
  int f() { return x = 3; }
  int f(int a, int b) { return x = a % b; }
};
class B : public A {
  int x;

public:
  int f(int a) { return x = a; }
  int f(int a, int b) { return x = a + b; }
  int g(A *a, B *b);
};
int B::g(A *pa, B *pb) {
  x = A::f();
  x = f(5);
  x = f(6, 6);
  x = f(5);
  return -1;
}
int main() {
  B a;
  x = a.A::f();
  x = a.f(7);
  class C {
    A a1;

  public:
    C() : a1() {} // а нет b, есть только a, но если его подставить - ошибочки
  };
  C c;
  return a.g(&a, &a);
}
