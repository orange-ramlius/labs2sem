struct S {
  virtual void f() const = 0;
  virtual ~S() {}
};

struct A {
  S s; // поле класса не может быть абстрактным классом
  int i;
};
