class A {
    int a, b;
public:
    A (int a = 0, int b = 0) {
        this -> a = a;
        this -> b = b;
    }
};

int main(void) {
    A a;
    A b(1);
    A c(1, 2);
    A d('1', 1);
    return 0;
}
