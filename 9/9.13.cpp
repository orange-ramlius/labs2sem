#include <iostream>
#include <list>

void f(const std::list<int> &lst) {
  int cnt = 0;
  std::list<int>::const_iterator it = lst.begin();
  while (it != lst.end()) {
    if (*it > 0) {
      cnt++;
    }
    it++;
  }
  std::cout << "count: " << cnt << std::endl;
}

int main(void) {
  const std::list<int> lst = {1, 5, -7, -24, 3};
  f(lst);
}
