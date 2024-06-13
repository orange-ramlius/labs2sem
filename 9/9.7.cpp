// Прямые итераторы (Forward Iterators) позволяют перемещаться только
// вперед по контейнеру, тогда как обратные итераторы (Bidirectional
// Iterators) позволяют перемещаться как вперед, так и назад по контейнеру.

// Пример использования обратного итератора:
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec = {1, 2, 3, 4, 5};

  // Используем обратный итератор для вывода элементов вектора в обратном
  // порядке
  for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
    std::cout << *it << " ";
  }

  return 0;
}

// В этом примере мы используем методы rbegin() и rend(), чтобы
// получить обратные итераторы, указывающие на последний элемент и
// перед началом контейнера соответственно. Затем мы используем
// обратный итератор для вывода элементов вектора в обратном порядке.

// Обратные итераторы допускают двунаправленные итераторы
//(Bidirectional Iterators), так как они могут перемещаться как впере
// д, так и назад по контейнеру