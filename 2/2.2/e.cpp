void f(const char *);
void f(long a = 0, const char * = 0);

int main(void) {
  f(1000000000000);
  f(1);
  f();
  f(0, 0);
  f("t");
  f(1, "u");
}
