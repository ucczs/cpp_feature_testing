#include<iostream>
#include<limits>

int main(){
    int i_max = std::numeric_limits<int>::max();
    float f_max = std::numeric_limits<float>::max();
    int c_mini = 0;
    int c_middle = 0;
    int c_big = 0;

    int c_nan = 0;

    const float lower_border = 1.f;
    const float upper_border = 1.0E18f;

    for(int i_val = 0; i_val < i_max; i_val++){

        float* f_val = reinterpret_cast<float*>(&i_val);

        if(*f_val > 0.f && *f_val <= lower_border){
            c_mini++;
        }
        else if(*f_val > lower_border && *f_val <= upper_border){
            c_middle++;
        }
        else if(*f_val > upper_border && *f_val <= f_max){
            c_big++;
        }
        else {
            c_nan++;
        }
    }

    std::cout << "mini:\t\t" << c_mini << std::endl;
    std::cout << "middle:\t\t" << c_middle << std::endl;
    std::cout << "big:\t\t" << c_big << std::endl;
    std::cout << "nan:\t\t" << c_nan << std::endl;

}