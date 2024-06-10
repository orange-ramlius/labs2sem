int x = 0;
void f(int a, int b) { x = a + b; }
class A {
  int x;

public:
  void f() { x = 2; }
};
class B : public A {
public:
  void f(int a) { ::x = a; } // глобальный x
  void g();
};
void B::g() {
  // f(); // нет подходящей перегрузки
  f(1);
  // f(5, 1); // нужная перегрузка является внешней функцией
  // x = 2; // приватный член, поэтмоу нельзя поменять
}
B ret(B &x, B &y) { return x; }
int main() {
  B b; // сначала конструктор A, потом конструктор B
  // f(5); //нет такой перегрузки
  f('+', 6);
  b = ret(b, b);
  return 0; // деструктор B, потом деструктор A
}
