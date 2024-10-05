#include <iostream>

class Base {
   private:
    int64_t a{};
    int64_t b{};

   public:
    Base() {};
    void printSomething() const { std::cout << "class Base function" << std::endl; };
};

class BaseWithVirtual {
   private:
    int64_t a{};
    int64_t b{};

   public:
    BaseWithVirtual() {};
    virtual void printAnything() const { std::cout << "class BaseWithVirtual function" << std::endl; };
};

class Derived : public Base {
   public:
    void printSomething() const { std::cout << "class Derived function" << std::endl; };
};

class DerivedAndOverride : public BaseWithVirtual {
   public:
    virtual void printAnything() const override { std::cout << "class DerivedAndOverride function" << std::endl; };
};

int main() {
    Base base = Base();
    Derived derived = Derived();

    BaseWithVirtual baseWithVirtual = BaseWithVirtual();
    DerivedAndOverride derivedAndOverride = DerivedAndOverride();

    std::cout << "size Base\t\t= " << sizeof(base) << std::endl;
    std::cout << "size Derived\t\t= " << sizeof(derived) << std::endl;
    std::cout << "*********************************" << std::endl;
    std::cout << "size BaseWithVirtual\t= " << sizeof(baseWithVirtual) << std::endl;
    std::cout << "size DerivedAndOverride\t= " << sizeof(derivedAndOverride) << std::endl;
    std::cout << std::endl << "-> Difference in size due to the virtual pointer which points to the vtable." << std::endl << std::endl;

    std::cout << "*********************************" << std::endl;
    std::cout << "*********************************" << std::endl << std::endl;

    std::cout << "derived.printSomething():" << std::endl << "\t";
    derived.printSomething();
    Base* basePointer = &derived;
    std::cout << "Base* basePointer = &derived:" << std::endl << "\t";
    basePointer->printSomething();

    std::cout << "derivedAndOverride.printSomething():" << std::endl << "\t";
    derivedAndOverride.printAnything();
    BaseWithVirtual* baseVirtualPointer = &derivedAndOverride;
    std::cout << "BaseWithVirtual* baseVirtualPointer = &derivedAndOverride:" << std::endl << "\t";
    baseVirtualPointer->printAnything();

    return 0;
}
