class A {
public: // делаем все публичным, иначе нет доступа к a.i
  static int i; // делаем статическим, иначе нельзя A::i=201
  int f(int x) const { return g(x); } // так как объект класса const
  int g(int x) const { // мы не можем передать по ссылке временное значение
    if (x >= 0)
      f(-i);
    return i;
  }
};
int A::i = 2013;
int main() {
  const A a;
  A::i = 201;
  a.f(20);
  return a.i = 1;
}
