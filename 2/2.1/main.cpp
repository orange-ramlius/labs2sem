class Cls {
  int i;

public:
  Cls() { i = 1; }
  Cls &operator=(Cls &x) = delete;
};
void f(Cls *p, Cls *q) { *p = *q; }
