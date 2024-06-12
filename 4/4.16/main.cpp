#include <iostream>
using namespace std;

struct S {
  static double d;
  virtual S &g() { cout << "g() from S" << endl; }
};
struct T : S {
  virtual T &g() { cout << "g() from T" << endl; }
  // по идее можно return *this и всё будет хорошо
};
double S::d = 1.5;
int main() {
  T t;
  S s, *ps = &t;
  ps->g();
  s.d = 5;
  t.d = 7;
  cout << s.d << ' ' << t.d << ' ' << S::d << endl;
  return 0;
}

/* программа крашится с кодом 132
g() from T
zsh: illegal hardware instruction (core dumped)  ./a.out

если добавить return *this
g() from T
7 7 7
*/
