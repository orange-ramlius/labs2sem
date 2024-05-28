struct mystr {
  int a, b;
  mystr() {
    a = 0;
    b = 0;
  }

public:
  mystr(const mystr &)=delete;            // noncopyable
  mystr &operator=(const mystr &)=delete; // noncopyable
};
int i = sizeof(mystr);
int f(mystr s) { return 0; }

int main(void) {
  mystr ms;
  f(ms);
}

//при таком коде комплиятор ругается, что конструктор удален
