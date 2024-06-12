// для включения механизма виртуальности для метода класса
// в родительском классе метод должен быть определён
// с ключевым словом virtual, а в наследуемом классе
// переопределяемый метод должен иметь ключевое слово override
// при этом метод родительского класса должен быть protected
// либо public
#include <iostream>

class Wolf {
public:
  virtual void makeSound() { std::cout << "Auuu\n"; }
};

class Dog : public Wolf {
public:
  void makeSound() override { std::cout << "Gaf\n"; }
};

int main(void) {
  Wolf *not_dog, wolf;
  Dog dog;
  wolf.makeSound();
  dog.makeSound();
  not_dog = &dog;
  not_dog->makeSound();
  return 0;
}
