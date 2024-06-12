#include <iostream>
using namespace std;

class Ex {
  int code;

public:
  Ex(int i) : code(i) {}
  Ex(const Ex &ex) : code(ex.code) {}
  int Get() const { return code; }
};
struct Ex60 : Ex {
  Ex60() : Ex(60) {}
};
void f() {
  throw Ex60();
  cout << "sword" << endl;
}
void t() {
  try {
    f();
  } catch (Ex60 &x) {
    cout << "lance" << endl;
    throw Ex(x.Get() + 1);
    cout << "dagger" << endl;
  } catch (Ex &) {
    cout << "knife" << endl;
  }
  cout << "hammer" << endl;
}

int main() {
  try {
    t();
  } catch (Ex &x) {
    cout << "arche " << x.Get() << endl;
  } catch (...) {
    cout << "pistole" << endl;
  }
  return 0;
}

/* output
lance
arche 61
*/
