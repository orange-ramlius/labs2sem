template <double f> void funcA(double d = f) { /*...*/ }
template <float f> class A { /*...*/
};
// для первых двух
// ранее чем в C++ 20 нельзя использовать
// float и double как параметр шаблона
// вероятно это связано с вычислениями
// с плаващей точкой
template <int n> class B { /*...*/
};
template <int n> void funcB(int t = n) { /*...*/ }
template <class Cs> class C { /*...*/
};
template <class Cs> struct D { /*...*/
};
template <class Cs> void funcC(const Cs &ref) { /*...*/ }
class myclass {
public:
  myclass() {}
};
template <myclass c> class E { /*...*/
};
// myclass нельзя использовать как параметр шаблона т.к.
// шаблоны должны быть решены на этапе компиляции, а в конструкторе
// могут происходить различные действия
struct mystruct {
  int a, b;
};
template <class mystruct> void funcD(mystruct *p = 0) { /*...*/ }
// 2 последних нельзя использовать до 20-ого стандарта C++
template <mystruct a> void funcE(mystruct *p = &a) { /*...*/ }
template <struct mystruct> void funcF(mystruct *p = 0) { /*...*/ }
