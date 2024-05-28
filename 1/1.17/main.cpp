#include <cstdio>
struct S {
  int x;
  S(int n) {
    x = n;
    printf("Cons\t");
  }
  S(const S &a) {
    x = a.x;
    printf("Copy\t");
  }
  ~S() { printf("Des\t"); }
};
S f(S &y) {
  y = S(3);
  return y;
}
int main() {
  S s(1);
  f(s);
  printf("%d ", s.x);
  return 0;
}

/*
Cons	Cons	Des	Copy	Des	3 Des
*/
