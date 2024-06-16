#include <iostream>
#include <list>
#include <vector>

int g(std::list<int> &lst, std::vector<int *> &vec) {
  int swaps = 0;

  auto lst_it = lst.begin();
  auto vec_it = vec.rbegin();

  while (lst_it != lst.end() && vec_it != vec.rend()) {
    std::swap(*lst_it, **vec_it);
    ++swaps;
    ++lst_it;
    ++vec_it;
  }

  for (int val : lst) {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  for (int *ptr : vec) {
    std::cout << *ptr << " ";
  }
  std::cout << std::endl;

  return swaps;
}
