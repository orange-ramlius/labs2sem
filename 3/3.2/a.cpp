float y = 0;
void f(float a) { y = a; }
class T {
  int y;

public:
  void f() { y = 2; }
};
class B : public T {
public:
  void f(float n, float m) { ::y = n * m; }
  void f(char c1, char c2) { ::y = c1 + c2; }
  void g() {
    T::f();
    ::f(1);
    f(-1, 1);
    ::y = 2;
  }
};
int main() {
  B b;
  f(5);
  f('+', 6);
  return 0;
}
