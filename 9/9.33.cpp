#include <iostream>
#include <list>
#include <vector>

typedef std::vector<double> V;

struct Signif_t {
  V::size_type Index;
  bool Signif;
};

typedef std::list<Signif_t> S;

void g(const V &vectorData, const S &signifList, std::ostream &output) {
  if (vectorData.empty() || signifList.empty()) {
    output << "Vector or signif list is empty." << std::endl;
    return;
  }

  double sumOfSignifElements = 0.0;

  for (const Signif_t &signif : signifList) {
    if (signif.Signif && signif.Index < vectorData.size()) {
      sumOfSignifElements += vectorData[signif.Index];
      output << "Index: " << signif.Index
             << " Value: " << vectorData[signif.Index] << std::endl;
    }
  }

  output << "Sum of significant elements: " << sumOfSignifElements << std::endl;
}

int main() {
  V vectorData = {1.0, 2.0, 3.0, 4.0, 5.0};
  S signifList = {
      {0, true}, {2, true}, {4, false}}; // Пример списка значимости элементов

  g(vectorData, signifList, std::cout);

  return 0;
}
