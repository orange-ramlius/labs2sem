#include <iostream>
#include <list>
using namespace std;
int main();
// нет, нельзя использвать += с итератором по листу
int g(list<int> &lst) {
  int S = 0;
  list<int>::iterator p = lst.begin();
  while (p != lst.end()) {
    S += *p;
    // p += 2;
    p++; // исправляем при помощи двух операций инкремента
    p++;
  }
  return S;
};
