int x = 0;
void f(int a, int b) { x = a + b; }
class A {
  int x;

public:
  void f() { x = 2; }
  void f(char a1, char b1) { x = a1 - b1; }
};
class B : public A {
public:
  void f(int a) { ::x = a; } // глобальный x
  void g() {
    // f(); нет такой перегрузки
    f(0);
    // f(5.3, 1); нет такой перегрузки, слишком много аргументов
    // x = 1; приватный член
  }
};
int main() {
  B b;
  // f(2); нет такой перегрузки
  f(3, 'a');
  return 0;
}
