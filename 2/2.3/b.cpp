int f(double a = 1.0) { return a; }      // 1
int f(long double a = 5.0) { return a; } // 2
int main() {
  float f1 = 1.0f;
  double d = 2.0;
  long double ld = 3.0l;
  f(); // ай яй яй, а вот тут анализатор предупреждает, что
       // компилятор не уверен, какую из
  // перегрузок запускать, ведь обе подходят
  f(4);  // тут то же самое
  f(f1); // 1
  f(d);  // 1
  f(ld); // 2
}
