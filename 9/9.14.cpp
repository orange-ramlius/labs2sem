#include <iostream>
#include <vector>

void f(const std::vector<bool> &vec) {
  int ones_cnt = 0;
  int zero_cnt = 0;
  for (std::vector<bool>::const_iterator i = vec.begin(); i != vec.end(); i++) {
    if (!(*i)) {
      zero_cnt++;
    } else {
      ones_cnt++;
    }
  }
  std::cout << "zeroes count: " << zero_cnt << " ones count: " << ones_cnt
            << std::endl;
}

int main() {
  const std::vector<bool> vec = {false, true, true, false, false};
  f(vec);
  return 0;
}
