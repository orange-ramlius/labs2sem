#include <iostream>
#include <list>

void f(std::list<int> &lst) {
  std::list<int>::iterator it = lst.begin();
  while (it != lst.end()) {
    it++;
    lst.insert(it, *--it);
    it++;
  }
  for (std::list<int>::reverse_iterator i = lst.rbegin(); i != lst.rend();
       i++) {
    std::cout << *i << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::list<int> lst = {1, 2, 3, 4};
  f(lst);
  return 0;
}
