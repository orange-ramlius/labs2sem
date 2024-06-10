void f(int a = 0, const char * = 0);
void f(const char * = 0, int b = 0);

int main(void) {
  f(0, 1);
  f(1, 0);
  f(0, "m");
  f("n", 0);
}
