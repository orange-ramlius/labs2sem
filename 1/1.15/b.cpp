class A {};
class B : public A {};
class C : public B {};
int main() {
  class D {
    B b;
    A a;

  public:
    D() : a(b) {}
  } d;
  C c;
}
