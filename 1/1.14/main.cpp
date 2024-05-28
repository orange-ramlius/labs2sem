#include <iostream>
using namespace std;

struct smartstr {
  int a, b;
  void *operator new(std::size_t size);
  void operator delete(void *ptr);
  void *operator new[](std::size_t size);
  void operator delete[](void *ptr);
  void *operator new(std::size_t size, void *ptr);
  void *operator new[](std::size_t size, void *ptr);
  void *operator new(std::size_t size, const std::nothrow_t &nth);
  void *operator new[](std::size_t size, const std::nothrow_t &nth);
};

int main(void) {
  smartstr test;
  smartstr test2 = new smartstr[2];
  return 0;
}
