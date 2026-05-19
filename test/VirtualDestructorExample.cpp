#include <iostream>

class Base {
public:
    Base() { std::cout << "Base constructor\n"; }

    virtual ~Base() { std::cout << "Base destructor\n"; } // destructor virtual
};

class Derived : public Base {
private:
    int* data;

public:
    Derived() : data(new int[1000]) {
        std::cout << "Derived constructor\n";
    }

    ~Derived() {
        delete[] data;
        std::cout << "Derived destructor\n";
    } // destructor de Derived
};

int main() {
    Base* ptr = new Derived();

    delete ptr; // llama destructor correcto (virtual)

    // evita memory leak (se libera Derived)
    return 0;
}