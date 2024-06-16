#include <iostream>
#include <vector>

int g(std::vector<double *> &vec) {
  int changes = 0;
  size_t n = vec.size();

  for (size_t i = 0; i < n; i++) {
    if (i % 2 == 0) {        // Четный номер
      if (*vec[i - 1] < 0) { // Нечетный номер предыдущий
        *vec[i] = 0;
        changes++;
      }
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    std::cout << *vec[i] << " ";
  }
  std::cout << std::endl;

  return changes;
}
