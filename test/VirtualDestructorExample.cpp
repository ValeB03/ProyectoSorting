#include <iostream>

class Base {
public:
    Base() { std::cout << "Base constructor\n"; }
    virtual ~Base() { std::cout << "Base destructor\n"; } // Virtual - SOLUTION!
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
    } // This won't be called!
};

int main() {
    Base* ptr = new Derived(); // Creates Derived object
    delete ptr; // Calls Derived destructor (virtual)
    // No MEMORY LEAK: Derived's data array is properly freed!
    return 0;
}
