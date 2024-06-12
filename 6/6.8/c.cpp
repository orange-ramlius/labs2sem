class A {
public: // делаем публичным, для обращения к полям
  static int m; // чтобы работать с m в статических методах
  static void m1() {
    if (m < 0)
      m2(m);
  }
  static int m2(int n) {
    return m1(), n;
  } // нельзя по ссылке временное значение
  static void m3(int n) { m = m2(n); } // и тут тоже
}; // методы статические т.к. их нужно вызывать без создания объекта класса
int A::m = 1;

int main() {
  A::m3(2013);
  A mm;
  return mm.m2(3);
}
