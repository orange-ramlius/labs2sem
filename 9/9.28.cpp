#include <iostream>
#include <vector>

int g(std::vector<int> &vec) {
  int changes = 0;
  int sum = 0;

  for (int val : vec) {
    sum += val;
  }

  double average = static_cast<double>(sum) / vec.size();

  for (int i = vec.size() - 1; i >= 0; --i) {
    if (vec[i] > average) {
      ++changes;
    }
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;

  return changes;
}
