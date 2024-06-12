#include <cstring>
struct B {
  virtual void g() {}
};
struct D : B {
  char y[100];
};
void f9(B &b, D &d, int n) {
  D *pd = (n > 0) ? &d : static_cast<D *>(&b); // динамический
                                               // выдает segfault
  strcpy(pd->y, "one_variant\n");
}

int main() {
  B b;
  D d;
  f9(b, d, 0);
  return 0;
}
