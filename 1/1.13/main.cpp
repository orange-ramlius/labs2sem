struct mystr {
  int a, b;
  mystr() {
    a = 0;
    b = 0;
  }

private:
  mystr(const mystr &);            // noncopyable
  mystr &operator=(const mystr &); // noncopyable
};
int i = sizeof(mystr);
int f(mystr s) { return 0; }

int main(void) {
  mystr ms;
  f(ms);
}
