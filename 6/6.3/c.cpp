#include <iostream>
using namespace std;

class A {
public:
  static int i;
  void f() const {
    if (i < 0)
      g(i);
    cout << "f ()" << endl;
  }
  void g(int &n) const { // const
    i = n;
    f();
    cout << "g ()" << endl;
  }
};
int A::i = 1;
int main() {
  const A a;
  int b = 2;
  a.g(b); // нельзя временное значение передавать по ссылке, поэтому добавили
          // переменную, а также сделали метод g публичным
  return 0;
}
