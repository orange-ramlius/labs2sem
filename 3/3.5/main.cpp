class W {
public:
  int *w;
  void wf(int *wp) { w = wp; }
};
class X : public W { // делаем наследование от X публичным, +6
public:
  int *x;
  void xf(int *xp) {
    x = xp;
    w = xp;
  }
};
class Y : W {
public:
  int *y;
  void yf(int *yp) {
    y = yp;
    w = yp;
  }
};
class Z : public X, Y { // делаем наследование от X публичным, +6
public:
  int *z;
  void zf(int *zp) {
    z = zp;
    x = zp;
    y = zp;
  }
};
void h() {
  int hi;
  W *pw;
  X *px;
  Y *py;
  Z *pz;
  pz = (Z *)(Y *)new W; // даункаст к Y, а затем к Z, +8
  (*pz).X::w = &hi; // берем из родительского класса поле w
  pz->xf((*pz).X::w);
}

// для проверки компиляции
int main(void) {
  h();
  return 0;
}
