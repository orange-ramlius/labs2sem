class A {};
class B : public A {};
class C : public B {};
int main() {
  C c;
  A a = c;
  struct D {
    B b;
    D() : b() {} // 5 inside b() cause error
  } d;
}

// порядок: ABC
// конструктор копирования, еще тут upcast происходит по идее
// AB
// D
