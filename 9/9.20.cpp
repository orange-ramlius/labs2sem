#include <iostream>
#include <list>
#include <vector>

int f(std::vector<long int> &vec, std::list<long int> &lst, int step) {
  int cnt = 0;
  std::vector<long int>::iterator iv = vec.begin();
  std::list<long int>::iterator il = lst.begin();

  while (il != lst.end()) {
    if (*il < 0) {
      iv = vec.insert(iv, 1, *il);
      cnt++;
      for (int i = 0; i < step; i++) {
        if (iv == vec.end())
          iv = vec.begin();
        else
          iv++;
      }
    }
    il++;
  }
  for (std::vector<long int>::const_iterator ci = vec.begin(); ci != vec.end();
       ci++) {
    std::cout << *ci << " ";
  }
  std::cout << std::endl;
  return cnt;
}
int main() {
  std::vector<long int> vec = {1, 2, 3, 4, 5};
  std::list<long int> lst = {-9, 8, -7, 6};
  f(vec, lst, 2);
  return 0;
}
