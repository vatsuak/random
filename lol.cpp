#include <iostream>
int* lol(){
    int x =6;
    int *p = &x;
    std::cout<<p<<std::endl;
    return p;
}
int main(){
    std::cout<<lol()<<std::endl;
    int* ptr = lol();
    std::cout<<*ptr<<std::endl;
    std::cout<<*(lol())<<std::endl;
    int* x = new int;
    *x = 5;
    int* p;
    p = x;
    x = NULL;
    std::cout<<*x;
    std::cout<<*p;
}