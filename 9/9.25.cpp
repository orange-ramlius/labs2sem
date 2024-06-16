#include <iostream>
#include <list>

int g(std::list<long *> &lst) {
  int changes = 0;
  int count = lst.size();

  auto it = lst.end();
  for (int i = count - 1; i >= 0; i--) {
    --it;
    if (i % 2 == 0) {            // Четный номер
      if (**std::prev(it) < 0) { // Нечетный номер предыдущий
        **it = -(**it);
        changes++;
      }
    }
  }

  for (auto ptr : lst) {
    std::cout << *ptr << " ";
  }
  std::cout << std::endl;

  return changes;
}
