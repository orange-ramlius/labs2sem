int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

Rational simplifyRational(Rational r) {
  int divisor = gcd(r.numerator, r.denominator);
  r.numerator /= divisor;
  r.denominator /= divisor;
  return r;
}
