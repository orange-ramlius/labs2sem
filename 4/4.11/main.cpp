struct A {
  int i;
  virtual void f() = 0;
  virtual ~A() {}
};
int g(A a) { return a.i * 5; }
// A это абстрактный класс, то бишь он не подразумевает
// создание экземпляров себя(объектов)
