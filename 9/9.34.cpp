#include <iostream>
#include <list>
#include <vector>

typedef std::vector<bool> B;
struct Value_t {
  B::size_type Index;
  int Value;
};
typedef std::list<Value_t> T;

int g(const B &values, const T &list) {
  int sum = 0;

  for (auto it = list.rbegin(); it != list.rend(); ++it) {
    Value_t val = *it;
    std::cout << "Value " << val.Value << ": " << values[val.Index]
              << std::endl;
    if (values[val.Index]) {

      sum += val.Value;
    }
  }

  return sum;
}

int main() {
  B values = {true, false, true, false, true};
  T list = {{0, 10}, {1, 20}, {2, 30}, {3, 40}, {4, 50}};

  int sum = g(values, list);
  std::cout << "Sum of significant values: " << sum << std::endl;

  return 0;
}
