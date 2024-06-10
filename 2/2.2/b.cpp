void f(int a, int b = 0);
void f(const char * = 0);
int main(void) {
  f();
  f("abc");
  f(2);
  f('+', 3);
}
