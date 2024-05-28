#include <iostream>
using namespace std;

class X {
  int i;
  double t;
  //снова 2 перекрывающих друг друга конструктора,
  //только этот уже имеет другое значение у t
  /*
  X() {
     i = 0;
     t = 1.0;
     cout << 1;
  }
  */
public:
  X(int k = 0, double r = 1.0) { //было 1.5
    i = k;
    t = r;
    cout << 2;
  }
  X(const X &a) {
    i = a.i;
    t = a.t;
    cout << 3;
  }
};
int main() {
  X a;
  X b(1);
  X c(1.5, 2);
  X d = b;
  X e = 3;
  b = c = e;
  return 0;
}

//выводит 22232
