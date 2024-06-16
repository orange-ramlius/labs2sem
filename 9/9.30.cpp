#include <iostream>
#include <list>
#include <numeric>
#include <vector>

template <typename Container> void printSumOfLastThree(const Container &cont) {
  if (cont.size() < 3) {
    std::cout << "Container is too small to have three last elements\n";
  } else {
    auto it = cont.end();
    std::advance(it, -3);
    auto sum = std::accumulate(it, cont.end(), 0);
    std::cout << "Sum of last three elements: " << sum << "\n";
  }
}

int main() {
  // Создаем контейнер-вектор из 5 целых чисел
  std::vector<int> vec = {1, 2, 3, 4, 5};

  // Применяем функцию-шаблон для печати суммы трех последних элементов
  printSumOfLastThree(vec);

  // Попробуем на контейнере, где трех последних элементов нет
  std::list<int> lst = {1, 2};
  printSumOfLastThree(lst);

  return 0;
}
