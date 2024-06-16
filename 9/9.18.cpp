#include <iostream>
#include <list>
#include <vector>

int f(const std::vector<float> &vec, std::list<float> &lst, int step) {
  int cnt = 0;
  std::vector<float>::const_iterator iv = vec.begin();
  std::list<float>::const_reverse_iterator il = lst.rbegin();
  float buff;
  while (il != lst.rend()) {
    if (*il >= 0 && *iv >= 0 || *il < 0 && *iv < 0) {
      buff = *il;
      std::cout << *iv << " " << *il << std::endl;
      lst.insert(std::next(il).base(), -buff);
      lst.erase(std::next(il).base());
    } else {
      il++;
    }
    for (int i = 0; i < step; i++) {
      iv += 1;
      if (iv == vec.end())
        iv = vec.begin();
    }
  }
  for (std::list<float>::const_iterator i = lst.begin(); i != lst.end(); i++) {
    std::cout << *i << " ";
    if (*i > 0)
      cnt++;
  }
  std::cout << std::endl;
  return cnt;
}

int main(void) {
  const std::vector<float> vec = {1, -4, 6, 7};
  std::list<float> lst = {2, 3, 4, -5};
  //-3 -4 2 -5
  f(vec, lst, 2);
}
