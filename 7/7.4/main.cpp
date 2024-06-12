#include <cstring>
#include <iostream>
using namespace std;

struct B {
  virtual void hi() { cout << "Hi !" << endl; }
};
struct D : B {
  char txt[10][4];
};
void puthi(B *pb, D *pd) {
  int i = 10;
  if (!dynamic_cast<D *>(pb))
    return;
  pd = (D *)pb;
  while (i)
    strcpy((pd->txt)[--i], "Hi!");
}

int main() {
  B b;
  D d;
  puthi(&b, &d);
  return 0;
}
// хорошо дальше надо написать, а не подправить)
//
