#include <iostream>
using namespace std;

struct K {
  virtual void add_st(K *n) {
    st++;
    cout << "add_st(K *) from K" << endl;
  }
  static int st;
};
struct L : K {
  virtual void add_st(L *a) {
    st++;
    cout << "add_st(L *) from L" << endl;
  }
};
int K::st = 2;
int main() {
  L ob, ob2;
  K k, *pl = &ob;
  pl->add_st(&ob2);
  k.st++;
  ++ob.st;
  cout << k.st << ' ' << ob.st << ' ' << K::st << endl;
  return 0;
}
/* output
add_st(K *) from K
5 5 5
*/
