#include <iostream>
#include <list>
#include <vector>

struct Value_t {
  bool Signif;
  int Value;
};

typedef std::vector<Value_t> B;
typedef std::list<B::size_type> T;

int g(const B &vectorB, const T &listT) {
  int sum = 0;

  auto it = listT.rbegin();
  while (it != listT.rend()) {
    if (*it < vectorB.size() && vectorB[*it].Signif) {
      sum += vectorB[*it].Value;

      std::cout << "Value: " << vectorB[*it].Value
                << " Significance: " << (vectorB[*it].Signif ? "True" : "False")
                << std::endl;
    }

    it++;
  }

  return sum;
}

int main() {
  B vectorB = {{true, 10}, {false, 20}, {true, 30}};
  T listT = {2, 1, 0};

  int result = g(vectorB, listT);
  std::cout << "Sum of significant values: " << result << std::endl;

  return 0;
}
