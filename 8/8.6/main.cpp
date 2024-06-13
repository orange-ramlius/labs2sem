#include <iostream>
using namespace std;

template <class T> int gcd(T a, T b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

template <class T> int lcm(T a, T b) { return a * b / gcd(a, b); }

/*
  int divisor = gcd(r.numerator, r.denominator);
  r.numerator /= divisor;
  r.denominator /= divisor;
*/

// будем думать что знак будет только у n
template <class T> class fr {
public:
  T n; // для удобства тестирования сделал публичными
  T d; // поля
  T getFraction() { return n / d; }

  fr operator+() {
    fr other = fr();
    int divisor = gcd(n, d);
    other.n = n / divisor;
    other.d = d / divisor;
    return other;
  }
  fr operator+(const fr &other) {
    fr result = fr();
    if (d == other.d) {
      result.d = d;
      result.n = n + other.n;
    } else {
      result.d = lcm(d, other.d);
      result.n = n * result.d / d + other.n * result.d / other.d;
    }
    return result;
  }
  fr operator-() {
    fr other = fr();
    other = *this;
    other.n *= -1;
    return other;
  }
  fr operator-(const fr &other) {
    fr result = fr();
    if (d == other.d) {
      result.d = d;
      result.n = n - other.n;
    } else {
      result.d = lcm(d, other.d);
      result.n = n * result.d / d - other.n * result.d / other.d;
    }
    return result;
  }
  fr operator*(T number) {
    fr result = fr();
    result.d = d;
    result.n = n * number;
    return result;
  }
  fr operator/(T number) {
    fr result = fr();
    result.n = n;
    result.d = d * number;
    return result;
  }
  fr &operator=(const fr &other) {
    this->n = other.n;
    this->d = other.d;
    return *this;
  }
  fr &operator+=(T number) {
    this->n += this->d * number;
    return *this;
  }
  fr &operator-=(T number) {
    this->n -= this->d * number;
    return *this;
  }
  fr &operator*=(T number) {
    this->n *= number;
    return *this;
  }
  fr &operator/=(const fr &other) {
    this->n *= other->d;
    this->d *= other.n;
    return *this;
  }
  bool operator==(const fr &other) {
    if (this->n == other.n && this->d == other.d)
      return true;
    else
      return false;
  }
  bool operator!=(const fr &other) {
    if (this->n != other.n || this->d != other.d)
      return true;
    else
      return false;
  }
  bool operator<(const fr &other) {
    if (this->getFraction() < other.getFraction())
      return true;
    else
      return false;
  }
  bool operator>(const fr &other) {
    if (this->getFraction() > other.getFraction())
      return true;
    else
      return false;
  }
  bool operator<=(const fr &other) {
    if (this->getFraction() <= other.getFraction())
      return true;
    else
      return false;
  }
  bool operator>=(const fr &other) {
    if (this->getFraction() >= other.getFraction())
      return true;
    else
      return false;
  }
  fr &operator++() { // prefix
    this->n += this->d;
    return *this;
  }
  fr &operator++(int) { // postfix
    fr old = *this;
    this->n += this->d;
    return old;
  }
  fr &operator--() { // prefix
    this->n -= this->d;
    return *this;
  }
  fr &operator--(int) { // postfix
    fr old = *this;
    this->n -= this->d;
    return old;
  }
  template <class U>
  friend std::ostream &operator<<(std::ostream &os,
                                  const fr<U> &obj); // её не
                                                     // сделать как метод класса
  template <class U> friend fr<U> &normalize(const fr<U> &self); // унарный плюс
  template <class U>
  friend fr<T> add(const fr<U> &self, const fr<U> &other);   // a+b
  template <class U> friend fr<U> invert(const fr<U> &self); // -a
  template <class U>
  friend fr<T> sub(const fr<U> &self, const fr<U> &other);          // a-b
  template <class U> friend fr<U> mul(const fr<U> &self, U number); // a*b
  template <class U> friend fr<U> div(const fr<U> &self, U number); // a/b
  template <class U>
  friend fr<T> &assign(fr<U> *self, const fr<U> &other);             // a=b
  template <class U> friend fr<U> &assignAdd(fr<U> *self, U number); // a+=b
  template <class U> friend fr<U> &assignSub(fr<U> *self, U number); // a-=b
  template <class U> friend fr<U> &assingMul(fr<U> *self, U number); // a*=b
  template <class U>
  friend fr<T> &assingDiv(fr<U> *self, const fr<U> &other); // a/=b
  template <class U>
  friend bool equal(const fr<U> self, const fr<U> &other); // a==b
  template <class U>
  friend bool notEqual(const fr<U> self, const fr<U> &other); // a!=b
  template <class U>
  friend bool less(const fr<U> self, const fr<U> &other); // a<b
  template <class U>
  friend bool bigger(const fr<U> self, const fr<U> &other); // a>b
  template <class U>
  friend bool lessOrEqual(const fr<U> self, const fr<U> &other); // a<=b
  template <class U>
  friend bool biggerOrEqual(const fr<U> self, const fr<U> &other); // a>=b
  template <class U> friend fr<U> &preIncrement(fr<U> *self);      // ++a
  template <class U> friend fr<U> &posIncrement(fr<U> *self);      // a++
  template <class U> friend fr<U> &preDecrement(fr<U> *self);      // --a
  template <class U> friend fr<U> &posDecrement(fr<U> *self);      // ++a
};

template <class T>
std::ostream &operator<<(std::ostream &os, const fr<T> &obj) {
  os << obj.n << '/' << obj.d;
  return os;
}

template <class T> fr<T> &normalize(const fr<T> &self) {
  fr other = fr<T>();
  int divisor = gcd(self.n, self.d);
  other.n = self.n / divisor;
  other.d = self.d / divisor;
  return other;
}

template <class T> fr<T> add(const fr<T> &self, const fr<T> &other) {
  fr result = fr<T>();
  if (self.d == other.d) {
    result.d = self.d;
    result.n = self.n + other.n;
  } else {
    result.d = lcm(self.d, other.d);
    result.n = self.n * result.d / self.d + other.n * result.d / other.d;
  }
  return result;
}

template <class T> fr<T> invert(const fr<T> &self) {
  fr other = fr<T>();
  other = self;
  other.n *= -1;
  return other;
}

template <class T> fr<T> sub(const fr<T> &self, const fr<T> &other) {
  fr result = fr<T>();
  if (self.d == other.d) {
    result.d = self.d;
    result.n = self.n - other.n;
  } else {
    result.d = lcm(self.d, other.d);
    result.n = self.n * result.d / self.d - other.n * result.d / other.d;
  }
  return result;
}

template <class T> fr<T> mul(const fr<T> &self, T number) {
  fr result = fr<T>();
  result.d = self.d;
  result.n = self.n * number;
  return result;
}

template <class T> fr<T> div(const fr<T> &self, T number) {
  fr result = fr<T>();
  result.n = self.n;
  result.d = self.d * number;
  return result;
}

template <class T> fr<T> &assign(fr<T> *self, const fr<T> &other) {
  self->n = other.n;
  self->d = other.d;
  return *self;
}

template <class T> fr<T> &assignAdd(fr<T> *self, T number) {
  self->n += self->d * number;
  return *self;
}

template <class T> fr<T> &assignSub(fr<T> *self, T number) {
  self->n -= self->d * number;
  return *self;
}

template <class T> fr<T> &assingMul(fr<T> *self, T number) {
  self->n *= number;
  return *self;
}

template <class T> fr<T> &assingDiv(fr<T> *self, const fr<T> &other) {
  self->n *= other->d;
  self->d *= other.n;
  return *self;
}

template <class T> bool equal(const fr<T> self, const fr<T> &other) {
  if (self->n == other.n && self->d == other.d)
    return true;
  else
    return false;
}

template <class T> bool notEqual(const fr<T> self, const fr<T> &other) {
  if (self->n != other.n || self->d != other.d)
    return true;
  else
    return false;
}

template <class T> bool less(const fr<T> &self, const fr<T> &other) {
  if (self->getFraction() < self.getFraction())
    return true;
  else
    return false;
}

template <class T> bool bigger(const fr<T> &self, const fr<T> &other) {
  if (self->getFraction() > other.getFraction())
    return true;
  else
    return false;
}

template <class T> bool lessOrEqual(const fr<T> &self, const fr<T> &other) {
  if (self->getFraction() <= other.getFraction())
    return true;
  else
    return false;
}

template <class T> bool biggerOrEqual(const fr<T> &self, const fr<T> &other) {
  if (self->getFraction() >= other.getFraction())
    return true;
  else
    return false;
}

template <class T> fr<T> &preIncrement(fr<T> *self) { // prefix
  self->n += self->d;
  return *self;
}

template <class T> fr<T> &posIncrement(fr<T> *self) { // postfix
  fr old = *self;
  self->n += self->d;
  return old;
}

template <class T> fr<T> &preDecrement(fr<T> *self) { // prefix
  self->n -= self->d;
  return *self;
}

template <class T> fr<T> &posDecrement(fr<T> *self) { // postfix
  fr old = *self;
  self->n -= self->d;
  return old;
}

// просто немного тестов
int main() {
  fr<int> test, proba;
  test.n = 1;
  test.d = 5;
  preDecrement(&test);
  std::cout << test << std::endl;
  proba.n = 2;
  proba.d = 4;
  std::cout << +proba << std::endl;
  return 0;
}
