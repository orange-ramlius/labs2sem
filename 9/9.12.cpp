#include <iostream>
#include <list>

void f(std::list<int> &lst) {
  std::list<int>::iterator p = lst.begin();

  while (p != lst.end()) {
    p++;
    lst.insert(p, -*--p);
    p++;
  }

  p = lst.begin();
  while (p != lst.end()) {
    std::cout << *p << std::endl;
    p++;
  }

  p = lst.begin();
  while (p != lst.end()) {
    if ((*p) < 0) {
      p = lst.erase(p);
    } else {
      p++;
    }
  }
  std::cout << "result: \n";
  p = lst.begin();
  while (p != lst.end()) {
    std::cout << *p << std::endl;
    p++;
  }
}

int main(void) {
  std::list<int> lst = {-1, -2, 3, -4, 5};
  f(lst);
}
