#include <iostream>
#include <vector>

int g(std::vector<int> &vec) {
  int swaps = 0;
  int n = vec.size();

  for (int i = 0; i < n / 2; i++) {
    std::swap(vec[i], vec[n - i - 1]);
    swaps++;
  }

  return swaps;
}
int main(void) {
  std::vector<int> vec = {1, 2, 3, 4};
  g(vec);
  return 0;
}
