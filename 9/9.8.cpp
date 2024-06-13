/*
Для двунаправленных итераторов допустимы следующие операции сравнения:
Сравнение на равенство (== и !=): два итератора могут быть сравнены на
равенство или неравенство.
*/
#include <iostream>
#include <list>

int main() {
  std::list<int> myList = {1, 2, 3, 4, 5};

  auto it1 = myList.begin();
  auto it2 = myList.end();

  // Ошибка: попытка сравнить итераторы разных контейнеров
  if (it1 < it2) {
    std::cout << "it1 меньше it2" << std::endl;
  }

  return 0;
}
