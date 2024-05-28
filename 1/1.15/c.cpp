class A {};
class B {};
class C : public A, public B {};
int main() {
  C c;
  class D {
    C c;
    B b;

  public:
    D() : b(c) {}
  } d;
}
