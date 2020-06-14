#include "Node.h"
#include <iostream>

int main(){
    Node end;
    Node mid(5,end);
    Node start(1,mid);

    std::cout<<"value of mid "<<mid<<std::endl;
    std::cout<<"value of end "<<end<<std::endl;
    std::cout<<"value of start "<<start<<std::endl;
    std::cout<<"value of child of start ie mid "<<start.get_child()<<std::endl;
    // int *ptr, x=3;
    // ptr = &x;
    // std::cout<<*ptr;
}