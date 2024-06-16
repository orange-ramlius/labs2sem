#include <iostream>
#include <list>
#include <vector>

template <typename Container> void printSecondToLast(const Container &cont) {
  if (cont.size() < 2) {
    std::cout << "Container is too small to have a second to last element\n";
  } else {
    auto it = cont.end();
    std::advance(it, -2);
    std::cout << "Second to last element: " << *it << "\n";
  }
}

int main() {
  // Создаем контейнер-список из 5 целых чисел
  std::vector<int> vec = {1, 2, 3, 4, 5};

  // Применяем функцию-шаблон для печати предпоследнего элемента
  printSecondToLast(vec);

  // Попробуем на контейнере, где предпоследнего элемента нет
  std::list<int> lst = {1};
  printSecondToLast(lst);

  return 0;
}
