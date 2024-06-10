int x = 0;
int f(int a, int b) { return x = a + b; }
class A {
  int x;

public:
  A(int n = 1) { x = n; }
  int f() { return ::x = x; }
};
class B {
  int x;

public:
  B(int n = 2) { x = n; }
};
class C : public A, public B {
  int x;

public:
  int f(int a) { return ::x = x; }
  void g();
};
void C::g() {
  x = A::f();
  f(3);
  x = ::f(4, 5);
  x = 6;
}
int main() {
  C c;
  B b = c;
  A a = c;
  c.A::f();
  c.f(7);
  x = f('8', 9);
  return -1;
}
// вызов конструкторов
// ABC
// апкаст к B
// апкаст к A
// destructors
// A
// B
// C
// B
// A
