// 1. Да, в языке C++ есть возможность получить информацию о типе объекта
// во время выполнения программы.  Эта возможность реализована с использованием
// RTTI (Run-Time Type Information). RTTI позволяет определить тип
// объекта во время выполнения программы.
// 2. `typeid`: Позволяет получить информацию о типе объекта во время
// выполнения программы. Возвращает объект типа `type_info`, который
// содержит информацию о типе объекта.
// 3.`typeid` имеет смысл для использования с классами, у которых
// есть хотя бы один виртуальный метод. Это позволяет иметь
// полиморфные объекты и использовать RTTI.
// 4.`std::bad_typeid`: Генерируется при использовании `typeid` для
// несуществующего типа.

#include <iostream>
#include <typeinfo>

class Base {
public:
  virtual void vvfunc() {}
};

class Derived : public Base {};

using namespace std;
int main() {
  Derived *pd = new Derived;
  Base *pb = pd;
  cout << typeid(pb).name() << endl;  // prints "P4Base"
  cout << typeid(*pb).name() << endl; // prints "7Derived"
  cout << typeid(pd).name() << endl;  // prints "P7Derived"
  cout << typeid(*pd).name() << endl; // prints "7Derived"
  delete pd;
}
// P4Base 7Derived P7Derived 7Derived
