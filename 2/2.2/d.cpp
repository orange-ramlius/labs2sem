struct X {
  X(int);
  operator int();
} x(0);

void f(const char * = 0);
void f(int a, const char * = 0);

int main(void) {
  f("p");
  f(x, 0);
  f(0, 0);
  f(x, "q");
  f(1, "r");
}
