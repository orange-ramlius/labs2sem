double a = 0;
void f(double x = 2) { a = x; }
void f() { a = 1; }

struct BBase {
  double a;
  void f() { a = 2; }
};
class B : BBase {
public:
  void f(int a) { ::a = a; } // глобальный a
  void g() {
    f('r');
    // f();
    a = 2;
  }
};
int main() {
  B d;
  // f(); обе перегрузки подходят, непонятно какую использовать
  f(6);
  return 0;
}
