#include <iostream>
#include <list>

void f(const std::list<int> &lst, int x) {
  for (std::list<int>::const_iterator i = lst.begin(); i != lst.end(); i++) {
    if (*i == x) {
      std::cout << "Yes" << std::endl;
      return;
    }
  }
  std::cout << "No" << std::endl;
}

int main() {
  const std::list<int> lst = {5, 4, 3, 2, 1};
  f(lst, 3);
  return 0;
}
