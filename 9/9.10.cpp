/*
1.InputIterator, Bidirectional iterators?, Random Access?
2.я не хочу снова перечилсять операции итераторов, выше уже было
3.
*/

#include <forward_list>
#include <iostream>

int main() {
  std::forward_list<int> vec = {1, 2, 3, 4, 5};

  // Используем однонаправленный итератор для обхода в обратном порядке
  std::forward_list<int>::iterator it = vec.end();
  while (it != vec.begin()) {
    std::cout << *(it - 1) << " "; // Ошибка! Недопустимо использовать вычитание
                                   // для однонаправленных итераторов
    --it;
  }

  return 0;
}

// двунаправленный
/*
#include <iostream>
#include <list>

int main() {
  std::list<char> lst = {'a', 'b', 'c', 'd', 'e'};

  // Используем двунаправленный итератор для обхода списка
  std::list<char>::iterator it = lst.begin();
  for (; it != lst.end(); ++it) {
    if (*it == 'c') {
      lst.erase(it); // Ошибка! Нельзя удалить элемент из списка,
                     // используя двунаправленный итератор в цикле
    }
  }

  return 0;
}
*/
