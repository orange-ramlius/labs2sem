#include <iostream>
void f(int a = 0, int b = 0);
void f(int a = 0, std::string b = "");

int main(void) { f('+', "bebra"); }
