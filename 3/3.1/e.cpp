float y = 0;
void f(float a) { y = a; }
class T {
  int y;

public:
  void f() { y = 2; }
};
class B : public T {
public:
  void f(float n, float m) { ::y = n * m; }   // глобальная y
  void f(char c1, char c2) { ::y = c1 + c2; } // глобальная y
  void g() {
    // f(); нет такой перегрузки
    // f(1); нет такой перегрузки
    // f(-1, 1); нет такой перегрузки
    // y = 2; приватный член
  }
};
int main() {
  B b;
  f(5);
  // f('+', 6); нет нужной перегрузки
  return 0;
}
