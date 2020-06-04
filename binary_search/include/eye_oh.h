#ifndef EYE_OH_H
#define EYE_OH_H
#include <iostream>

class EYE_OH{
    private:
        std::string start;
    public:
        EYE_OH(std::string prompt);
        ~EYE_OH();
        void get_start();
        int get_num(std::string prompt);
        int* get_array(int len);
        void print_array(int* arr, int len);
};
#endif