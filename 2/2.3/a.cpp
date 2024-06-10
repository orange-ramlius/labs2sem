int f(int a = 0) { return a; } // 1
int f(double a) { return a; }  // 2
int main() {
  short int s;
  int i;
  bool b;
  enum e { A, B, C };
  float f1 = 1.0f;
  f();   // 1
  f(s);  // 1
  f(f1); // 2
  f(b);  // 1
  f(A);  // 1
}
