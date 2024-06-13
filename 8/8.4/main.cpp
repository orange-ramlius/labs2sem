#include <cstring>
#include <iostream>
using namespace std;

template <class T> T max(T &x, T &y) { return x > y ? x : y; }
template <> char *max<char *>(char *&x, char *&y) {
  int min = 0;
  if (strlen(x) > strlen(y))
    min = strlen(y);
  else
    min = strlen(x);

  for (int i = 0; i < min; i++) {
    if (x[i] > y[i]) {
      return x;
    }
  }
  return y;
}

int main() {
  double x = 1.5, y = 2.8, z;
  int i = 5, j = 12, k;
  char *s1 = "abft";
  char *s2 = "abxde", *s3;
  z = max(x, y);
  cout << "z = " << z << endl;
  k = max<int>(i, j);
  cout << "k = " << k << endl;
  z = max(x, (double &)i);
  cout << "z = " << z << endl;
  z = max(y, (double &)j);
  cout << "z = " << z << endl;
  s3 = max(s1, s2);
  cout << "s3 = " << s3 << endl;
  cout << "Выбор сделан!" << endl;

  return 0;
}

/* output
z = 2.8
k = 12
z = 1.5
z = 2.8
s3 = abft
Выбор сделан!
*/
