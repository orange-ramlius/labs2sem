#include <iostream>
#include <list>
#include <vector>

int f(const std::vector<int> &vec, std::list<int> &lst, int step) {
  int cnt = 0;
  std::vector<int>::const_iterator iv = vec.begin();
  std::list<int>::const_iterator il = lst.begin();

  while (il != lst.end()) {
    lst.insert(il, *iv);
    il = lst.erase(il);
    cnt++;
    for (int i = 0; i < step; i++) {
      iv++;
      if (iv == vec.end())
        iv = vec.begin();
    }
  }
  for (std::list<int>::const_reverse_iterator ci = lst.rbegin();
       ci != lst.rend(); ci++) {
    std::cout << *ci << " ";
  }
  std::cout << std::endl;
  return cnt;
}

int main() {
  std::vector<int> vec = {1, 2, 3, 4, 5};
  std::list<int> lst = {9, 8, 7, 6};
  f(vec, lst, 2);
  return 0;
}
