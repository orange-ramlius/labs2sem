#include <iostream>
#include <list>

template <typename T> void printEverySecondFromEnd(const T &container) {
  typename T::const_reverse_iterator it = container.rbegin();
  bool print = false;
  while (it != container.rend()) {
    if (print) {
      std::cout << *it << " ";
    }
    print = !print;
    ++it;
  }
  std::cout << std::endl;
}

int main() {
  std::list<int> myList = {1, 2, 3, 4, 5};
  printEverySecondFromEnd(myList);

  return 0;
}
