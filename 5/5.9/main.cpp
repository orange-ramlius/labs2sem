#include <iostream>
using namespace std;

class Ex {
  int code;

public:
  Ex(int i) : code(i) {}
  Ex(const Ex &ex) : code(ex.code) {}
  int Get() const { return code; }
};
struct Ex51 : Ex {
  Ex51() : Ex(51) {}
};
void f() {
  throw Ex51();
  cout << "train" << endl;
}
void t() {
  try {
    f();
  } catch (Ex51 &x) {
    cout << "plane" << endl;
    throw Ex(x.Get() + 1);
    cout << "helicopter" << endl;
  } catch (Ex &) {
    cout << "car" << endl;
  }
  cout << "truck" << endl;
}
int main() {
  try {
    t();
  } catch (Ex &x) {
    cout << "boat " << x.Get() << endl;
  } catch (...) {
    cout << "rocket" << endl;
  }
  return 0;
}

/* output
plane
boat 52
*/
