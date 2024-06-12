#include <iostream>
using namespace std;

class K {
public:
  virtual void g() { cout << "K::g"; } // делаем виртуальным и вжух
  // ошибок нет
  // для dynamic_cast требуется, чтобы тип был полиморфным
  // а чтобы он был полиморфным хотя бы один метод должен быть
  // виртуальным
  // поэтому апкаст и не работал
  // хотя апкаст очень странный, на самом деле
  // еще можно было бы заменить всё на static_cast
};
class L : public K {
public:
  void f() { cout << "L::f"; }
};
class M : public K {
public:
  virtual void h() { cout << "M::h"; }
};
class P : public L {
public:
  void f() { cout << "P::f"; }
};
class Q : public M {
public:
  virtual void h() { cout << "Q::h"; }
};
class R : public P {
public:
  virtual void f() { cout << "R::f"; }
  virtual void h() { cout << "R::h"; }
};
class S : public Q {
public:
  virtual void f() { cout << "S::f"; }
  virtual void h() { cout << "S::h"; }
};
int main() {
  S os, *s = &os;
  K *k;
  L *l;
  M *m;
  P *p;
  Q *q;
  R *r;
  int a, b;
  k = dynamic_cast<K *>(s);
  s = dynamic_cast<S *>(k); // ошибочка
  l = dynamic_cast<L *>(k); // ошибка
  m = dynamic_cast<M *>(s);
  p = dynamic_cast<P *>(l); // ошибка
  q = dynamic_cast<Q *>(m);
  r = dynamic_cast<R *>(q);
  s = dynamic_cast<S *>(p); // ошибка
  return 0;
}
