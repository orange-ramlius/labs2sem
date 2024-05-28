int n; // нельзя использовать внешнюю переменную как значение по умолчанию
float f(float a, int t = 3, int d = n) { return a * (float)(t % d); }
