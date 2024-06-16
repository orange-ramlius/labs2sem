#include <iostream>
#include <list>
#include <vector>

typedef std::vector<int> V;

struct Weight_t {
  V::size_type Index;
  float Weight;
};

typedef std::list<Weight_t> L;

void g(const V &vectorData, const L &weightList, std::ostream &output) {
  if (vectorData.empty() || weightList.empty()) {
    output << "Vector or weight list is empty." << std::endl;
    return;
  }

  float weightedSum = 0.0;
  float totalWeight = 0.0;

  for (const Weight_t &weight : weightList) {
    if (weight.Index < vectorData.size()) {
      weightedSum += vectorData[weight.Index] * weight.Weight;
      totalWeight += weight.Weight;
      output << "Value: " << vectorData[weight.Index]
             << " Weight: " << weight.Weight << std::endl;
    }
  }

  if (totalWeight != 0.0) {
    float result = weightedSum / totalWeight;
    output << "Weighted average result: " << result << std::endl;
  } else {
    output << "Total weight is zero, cannot calculate weighted average."
           << std::endl;
  }
}

int main() {
  V vectorData = {1, 2, 3, 4, 5};
  L weightList = {{1, 0.1}, {3, 0.2}, {4, 0.3}};

  g(vectorData, weightList, std::cout);

  return 0;
}
