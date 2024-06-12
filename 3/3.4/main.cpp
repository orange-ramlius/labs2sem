class S {
public:
  int s;
  void sp(int si) { s = si; }
};
class T : public S {
public:
  int t;
  void tp(int ti) {
    t = ti;
    s = ti;
  }
};
class U : public T {
public:
  int u;
  void up(int ui) {
    u = ui;
    t = ui;
    s = ui;
  }
};
void g() {
  U *pu = new U;
  T *pt = pu;
  S *ps = pu;
}
// добавили public в наследовании чтобы дочерние классы могли использовать
// родительские поля
//  чтобы проверить компилируется ли
int main(void) {
  g();
  return 0;
}
