#include <iostream>
using namespace std;
struct X; // ругалось, что функция не знает что такое X
void f(X &x, int n);
struct X {
  X() {
    try {
      ::f(*this, -1); // не видел функцию
      cout << "a";
    } catch (X) {
      cout << "b";
    } catch (int) {
      cout << "c";
    }
  }
  X(X &) { cout << "d"; }
  virtual ~X() { cout << "e"; }
};
struct Y : X {
  Y() {
    try {
      f(*this, 0);
      cout << "f";
    } catch (Y) {
      cout << "g";
    } catch (int) {
      cout << "h";
    }
    cout << "i";
  }
  Y(Y &) { cout << "j"; }
  ~Y() { cout << "k"; }
};
void f(X &x, int n) {
  try {
    if (n < 0)
      throw -n;
    else if (n == 0)
      throw x;
    else
      throw n;
  } catch (int) {
    cout << "l";
  }
}
int main() {
  try {
    Y a;
  } catch (...) {
    cout << "m";
    return 1;
  }
  cout << "n";
  return 0;
}

// output: lademe
