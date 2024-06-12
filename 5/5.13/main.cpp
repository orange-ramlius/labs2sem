#include <iostream>
using namespace std;

struct S {
  S(int a) {
    try {
      if (a > 0)
        throw *this;
      else if (a < 0)
        throw 0;
    } catch (S &) {
      cout << "SCatch_S &" << endl;
    } catch (int) {
      throw;
    }
    cout << "SConstr" << endl;
  }
  S(const S &a) { cout << "Copy" << endl; }
  ~S() { cout << "Destr" << endl; }
};

int main() {
  try {
    S s1(1), s2(-2);
    cout << "Main" << endl;
  } catch (S &) {
    cout << "MainCatch_S &" << endl;
  } catch (...) {
    cout << "MainCatch_..." << endl;
  }
  return 0;
}

/* output
Copy
SCatch_S &
Destr
SConstr
Destr
MainCatch_...
*/
