#include <iostream>
#include <vector>

void f(std::vector<char> &vec) {
  std::vector<char>::iterator it = vec.begin();
  while (it != vec.end()) {
    it++;
    vec.erase(it);
  }
  for (std::vector<char>::reverse_iterator i = vec.rbegin(); i != vec.rend();
       i++) {
    std::cout << *i << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::vector<char> vec = {'h', 'e', 'l', 'o'};
  f(vec);
  return 0;
}
