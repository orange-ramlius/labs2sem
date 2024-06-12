class B {
public:
  virtual int f() = 0;
  int g() { return f() * 10; }
  virtual ~B() {}
};
int h(B b) { return b.g() + 2; }
// абстрактный класс не может быть параметром функции
