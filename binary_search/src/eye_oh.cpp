#include "eye_oh.h"

EYE_OH::EYE_OH(std::string start): start(start){      // note the use of initilizer lists for the constructor
    std::cout<<start<<std::endl;
}

EYE_OH::~EYE_OH(){                                    // destructor
    std::cout<<"End of I/O"<<std::endl;
}
void EYE_OH::get_start(){
    std::cout<<start;
}
int EYE_OH::get_num(std::string prompt){             // user input for a single digit
    std::cout<<prompt;
    int value;
    std::cin>>value;
    return value;
}
int* EYE_OH::get_array(int l){                       // user input for an array created in the heap, remember to delete after use for preventing leak
    int* arr = new int [l];
    // static int arr[5];
    // int arr[l];

    std::cout<<"Enter elements :"<<std::endl;
    for(int i=0; i<l; i++){
        std::cin>>arr[i];
        // std::cin>>*(arr+i);
        std::cout<<std::endl; 
    }
    // std::cout<<"Address of array while creating "<<arr<<std::endl;
    return arr;
}
void EYE_OH::print_array(int* arr, int len){     // print array
    // std::cout<<"Address of array while reading "<<arr<<std::endl;
    std::cout<<"Displaying array....."<<std::endl;
    for(int i=0; i<len; i++){
        std::cout<<arr[i]<<std::endl;
        // std::cout<<*(arr + i)<<std::endl;
    }
}