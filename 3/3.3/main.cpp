class A {
public:
  int *n;
  int m;
};
class B : public A {
public:
  int *p;
};
class C : public A {
public:
  int *c;
};
class D : public B, public C {
public:
  int *e;
};
int main() {
  D fA, *f = new D;
  fA.C::m = 0;
  return *((*f).e = &fA.C::m);
}
