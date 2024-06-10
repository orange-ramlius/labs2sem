double a = 0;
void f(double x) { a = x; }
struct A {
  double a;
  void f() { a = 2; }
};

class B : A {
public:
  void f(int a) { ::a = a; } // глобальная переменная a
  void g();
};
void B::g() {
  f(1.2);
  // f(); нет такой перегрузки
  a = 2;
}
void empty(B &a, B b) {}

int main() {
  B d;
  // f(); нет такой перегрузки
  f(6);
  empty(d, d);
  return 0;
}
