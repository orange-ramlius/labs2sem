enum { myparam = 18 };
float f(float a, int t = myparam + 5, int d = t + 8) {
  return a * (float)(t % d);
}
// невозможно использовать один из параметров как значение по умолчанию
