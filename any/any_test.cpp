#include <any>
#include <iostream>
#include <typeinfo>

template <typename Func>
void handle_any(const std::any& obj, Func handler) {
    if (obj.type() == typeid(int)) {
        handler(std::any_cast<int>(obj));
    } else if (obj.type() == typeid(uint)) {
        handler(std::any_cast<uint>(obj));
    } else if (obj.type() == typeid(double)) {
        handler(std::any_cast<double>(obj));
    } else if (obj.type() == typeid(float)) {
        handler(std::any_cast<float>(obj));
    } else if (obj.type() == typeid(std::string)) {
        handler(std::any_cast<std::string>(obj));
    } else if (obj.type() == typeid(char)) {
        handler(std::any_cast<char>(obj));
    } else {
        std::cerr << "Unknown type stored in std::any." << '\n';
    }
}

int main() {
    // std::any obj = 3.14;
    // std::any obj = 1U;
    // std::any obj = 1.f;
    // std::any obj = std::string("ABC");
    std::any obj = 'a';

    handle_any(obj, [](auto value) {
        using ValueType = decltype(value);
        std::cout << "Value: " << value << " (Type: " << typeid(ValueType).name() << ")" << '\n';
    });

    return 0;
}
