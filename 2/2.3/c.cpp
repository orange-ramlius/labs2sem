int f(int a = 1) { return a; } // 1
int f(long double a = 5.0) { return a; }
int main() {
  short int s;
  int i;
  bool b;
  float f1 = 1.0f;
  double d = 2.0;
  f(s);  // 1
  f(i);  // 1
  f(b);  // 1
  f(f1); // тут снова прикол с неопределённостью, в теории перегрузка
         // с лонг дабл включиться
  f(d);  // как и тут
}
