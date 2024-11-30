#include <any>
#include <iostream>
#include <typeinfo>

using hiddenAny_t = std::any;

class MemProviders {
   public:
    MemProviders(int int_val, float float_val) : i_val(int_val), f_val(float_val) {};

    void printVals() { std::cout << "Memproviders values " << i_val << " and " << f_val << std::endl; }

   private:
    int i_val{};
    float f_val{};
};

void registerBuffersWrapper(hiddenAny_t& mem_providers_any) {
    std::cout << "register function called via function pointer" << std::endl;
    MemProviders& mem_providers = std::any_cast<MemProviders&>(mem_providers_any);
    mem_providers.printVals();
}

void stage1_object_receiver(hiddenAny_t& mem_providers_any) {
    std::cout << "Stage1 receives hidden any object, no clue about this object.." << std::endl;
    registerBuffersWrapper(mem_providers_any);
}

int main() {
    MemProviders myClass{22, 1234.f};

    std::any a_object = myClass;
    stage1_object_receiver(a_object);

    return 0;
}
