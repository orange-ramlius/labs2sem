// ура, наконец-то что-то пописать

class A {
public:
  static int x;
  int get_0() const { return 0; }
};

int A::x;
int main() {
  const A a;
  a.x = 1;
  a.get_0();
  return 0;
}
