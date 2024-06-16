#include <iostream>
#include <vector>

int g(std::vector<int> &vec) {
  int changes = 0;

  for (int i = vec.size() - 1; i > 0; --i) {
    if (i % 2 == 1 && vec[i] > vec[i - 1]) {
      std::swap(vec[i], vec[i - 1]);
      ++changes;
    }
  }

  for (int val : vec) {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  return changes;
}
