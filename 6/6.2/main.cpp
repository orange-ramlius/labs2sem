#include <iostream>
using namespace std;

class X {
public:
  static void g() { cout << "g" << endl; } // делаем метод статическим
  int h(int n) const { // снова делаем константной
    cout << "f" << endl;
    return n;
  }
};
int main() {
  int k;
  const X x;
  X::g();
  k = x.h(5);
  return 0;
}
