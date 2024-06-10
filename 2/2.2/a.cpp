void f(double a, int b = 0);
void f(int a, const char * = 0);

int main(void) {
  f(1);
  f('+', '+');
  f(2.3);
  f(3, "str");
}
