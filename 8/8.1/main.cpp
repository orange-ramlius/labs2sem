#include <iostream>

template <typename T> T max(T a, T b) { return (a > b) ? a : b; }

int main() {
  int max_int = max(5, 10);
  double max_double = max(3.14, 6.28);

  std::cout << "Максимальное значение для int: " << max_int << std::endl;
  std::cout << "Максимальное значение для double: " << max_double << std::endl;

  return 0;
}
