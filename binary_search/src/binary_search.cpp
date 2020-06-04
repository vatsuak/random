#include <iostream>
#include "eye_oh.h"


int binary_search(int* arr, int val, int lp,int up){
    int mp = (lp+up)/2;
    if(lp>up)
        return -1;
    if(arr[mp] == val)
        return mp;
    if(arr[mp]>val)
       return binary_search(arr, val, lp, mp-1);
    if(arr[mp]<val)
       return binary_search(arr, val, mp+1, up);
}

int main(){
    EYE_OH ioh("Starting....");
    int len = ioh.get_num("Enter length of array: ");
    int* array = ioh.get_array(len);
    ioh.print_array(array, len);
    int val = ioh.get_num("Enter value to search: ");
    int pos = binary_search(array, val, 0, len-1);
    std::cout<<"found at pos "<<(pos+1)<<std::endl;
    array = NULL; // deacllocating heap memory to prevent leak
    return 0;
}