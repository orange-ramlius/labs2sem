// статические и динамические виды операций преобразования типов
// статические выполняются компилятором, используются когда
// программист знает, что точно всё будет хорошо при преобразовании
// может использоваться для апкаста, явного преобразования типов
// и других вариантов(но не всегда), когда можно использовать сишный
// вариант. можно для преобразования так же в такой ситуации:
// есть 2 класса, родительский(1) и дочерний(2)
// есть указатель на класс 1
// мы присваиваем ему значения адреса класса 2
// и хотим произвести обратное преобразование(от класса 1 к классу2)
// в таком случае это возможно
//
// динамические происходят во время работы программы
// они применяются для ссылок и указателей на полиморфные классы
//(один из методов которых является виртуальным)
// в случае неудачи преобразования возвращает nullptr
// типы при dynamic_cast должны находиться в одной иерархии класса
// возможен upcast(приведение к родителю) и downcast(приведение
// родительского класса к дочернему)

#include <iostream>
class Book {
public:
  virtual int getID() { return 0; }
};

class File : public Book {
public:
  virtual int getID() { return 5; }
};

int main() {
  double sum{100.2};
  unsigned int hours{8};
  unsigned int revenuePerHour{static_cast<unsigned int>(sum / hours)};
  std::cout << "Revenue per hour = " << revenuePerHour << std::endl;
  Book b;
  File f;
  Book *pb = &b;
  std::cout << b.getID() << f.getID();
  if (!dynamic_cast<File *>(pb))
    std::cout << " error: nullptr";
  else
    std::cout << dynamic_cast<File *>(pb)->getID();
  return 0;
}
