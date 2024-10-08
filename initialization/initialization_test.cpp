#include <array>
#include <iostream>

class TrivialClassDefaultConstr {
   public:
    int a;
    float b;
    char c;
    TrivialClassDefaultConstr() = default;
};

class TrivialClassDefaultConstr2 {
   public:
    int a;
    float b;
    char c;
    TrivialClassDefaultConstr d;
    TrivialClassDefaultConstr2() = default;
};

class TrivialClassDefaultConstr3 {
   public:
    int a{};
    float b{};
    char c{};
    TrivialClassDefaultConstr3() = default;
};

class TrivialClassNoDefaultConstr {
   public:
    int a;
    float b;
    char c;
    TrivialClassNoDefaultConstr() {};
};

class ComplexClass {
   public:
    std::array<int, 3> vec_i;
    ComplexClass() = default;
};

template <class T>
void printAllElementsABC(T t) {
    std::cout << "\ta = " << t.a << "\n";
    std::cout << "\tb = " << t.b << "\n";
    std::cout << "\tc = char(" << int(t.c) << ")\n";
}

void printAllElementsTCDC2(TrivialClassDefaultConstr2 t) {
    std::cout << "\ta = " << t.a << "\n";
    std::cout << "\tb = " << t.b << "\n";
    std::cout << "\tc = char(" << int(t.c) << ")\n";
    std::cout << "\td.a = " << t.d.a << "\n";
    std::cout << "\td.b = " << t.d.b << "\n";
    std::cout << "\td.c = char(" << int(t.d.c) << ")\n";
}

template <class T>
void printArray(T t) {
    for (const auto& element : t) {
        std::cout << "\t" << element << "\n";
    }
}

int main() {
    TrivialClassDefaultConstr tc_1;
    TrivialClassDefaultConstr tc_2{};
    TrivialClassDefaultConstr tc_3{1, 1, '1'};
    TrivialClassDefaultConstr tc_4{5};

    std::cout << "Trivial class with default constructor:\n\n";

    std::cout << "tc_1;";
    std::cout << "\t\t\t\t-> garbage values\n";
    printAllElementsABC(tc_1);

    std::cout << "tc_2{};";
    std::cout << "\t\t\t\t-> zero values, default constructor initializes to zero\n";
    printAllElementsABC(tc_2);

    std::cout << "tc_3{1, 1, '1'};";
    std::cout << "\t\t-> user defined values, constructor generated by compile which accepts values\n";
    printAllElementsABC(tc_3);

    std::cout << "tc_4{5};";
    std::cout << "\t\t\t-> constructor generated by compiler to fill values as defined by user or zero values\n";
    printAllElementsABC(tc_4);

    std::cout << "\n///////////////////////////////////////////////////////\n\n";

    TrivialClassDefaultConstr2 tc2_1;
    TrivialClassDefaultConstr2 tc2_2{};
    TrivialClassDefaultConstr2 tc2_3{1, 1, '1', 2, 2, '2'};

    std::cout << "Trivial class (containing an object of another trivial class) with default constructor:\n\n";

    std::cout << "tc2_1;";
    std::cout << "\t\t\t\t-> garbage values\n";
    printAllElementsTCDC2(tc2_1);

    std::cout << "tc2_2{};";
    std::cout << "\t\t\t-> zero values, default constructor initializes to zero\n";
    printAllElementsTCDC2(tc2_2);

    std::cout << "tc2_3{1, 1, '1', 2, 2, '2'};";
    std::cout << "\t-> constructor generated by compiler to fill values as defined by user\n";
    printAllElementsTCDC2(tc2_3);

    std::cout << "\n///////////////////////////////////////////////////////\n\n";

    TrivialClassNoDefaultConstr tcn_1;
    TrivialClassNoDefaultConstr tcn_2{};
    // TrivialClassNoDefaultConstr tcn_3{1, 1, '1'};
    // does not compile, since user defined a constructor -> no default constructor with values is generated

    std::cout << "Trivial class with a user defined empty constructor:\n\n";

    std::cout << "tcn_1;";
    std::cout << "\t\t\t\t-> garbage values\n";
    printAllElementsABC(tcn_1);

    std::cout << "tcn_2{};";
    std::cout << "\t\t\t-> garbage values, user defined constructor doesn't do anything\n";
    printAllElementsABC(tcn_2);

    std::cout << "tcn_3{1, 1, '1'};";
    std::cout << "\t\t-> does not compile since user only defined constructor without any arguments. Compiler doesn't generate any other "
                 "constructor once user defined one.\n";

    std::cout << "\n///////////////////////////////////////////////////////\n\n";

    std::cout << "Trivial class with default constructor and members zero initialized\n\n";

    TrivialClassDefaultConstr3 tc3_1;
    std::cout << "tc3_1;";
    std::cout << "\t\t\t\t-> zero values, since the trivial members of the class are zero initialized (via \"memberA{};\")\n";
    printAllElementsABC(tc3_1);

    std::cout << "\n///////////////////////////////////////////////////////\n\n";

    std::cout << "Class containing an array and default constructor\n\n";

    ComplexClass cc_1;
    ComplexClass cc_2{};
    ComplexClass cc_3{1, 1};

    std::cout << "cc_1;";
    std::cout << "\t\t\t\t-> garbage values in array\n";
    printArray(cc_1.vec_i);

    std::cout << "cc_2{};";
    std::cout << "\t\t\t\t-> zero values in int array\n";
    printArray(cc_2.vec_i);

    std::cout << "cc_3{1, 1};";
    std::cout << "\t\t\t-> values are provided to array and first elements are filled with provided values, rest is zero\n";
    printArray(cc_3.vec_i);

    return 0;
}