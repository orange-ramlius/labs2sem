#include <iostream>
#include <list>
#include <vector>
// не написал, но задания 9.19 и 9.21 дублируются -_-
int f(const std::vector<double> &vec, std::list<double> &lst, int step) {
  int cnt = 0;
  std::vector<double>::const_iterator iv = vec.begin();
  std::list<double>::const_iterator il = lst.begin();

  while (il != lst.end()) {
    if (*il != *iv) {
      lst.insert(il, *iv);
      cnt++;
    }
    il++;
    for (int i = 0; i < step; i++) {
      iv++;
      if (iv == vec.end())
        iv = vec.begin();
    }
  }
  for (std::list<double>::const_reverse_iterator ci = lst.rbegin();
       ci != lst.rend(); ci++) {
    std::cout << *ci << " ";
  }
  std::cout << std::endl;
  return cnt;
}

int main() {
  std::vector<double> vec = {8, 7, 3, 6, 5};
  std::list<double> lst = {9, 8, 7, 6};
  f(vec, lst, 2);
  return 0;
}
