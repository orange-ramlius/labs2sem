#include <cstdio>

struct S {
  int x;
  S(int n) {
    x = n;
    printf("Cons\t");
  }
  S(const S &a) {
    x = a.x;
    printf(" Copy\t");
  }
  ~S() { printf("Des\t"); }
};

S &f(S y, S &z) {
  y = S(3);
  return z;
}
int main() {
  S s(1);
  f(s, s);
  printf("%d\t", s.x);
  return 0;
}

// Cons	 Copy	Cons	Des	Des	1	Des
