#include <iostream>
using namespace std;

class Base{
    public:
        virtual void func1() = 0;
};

class Derived: public Base{   // publicly inherited 
    public:
        void func1();
        void func2();
};

void Derived::func1(){        // must be declared to implement inhertance 
    cout<<"overridden Func 1 in derived"<<endl;
}
void Derived::func2(){
    cout<<"Func 2 in derived"<<endl;
}

int main(){
    Base *b;
    Derived d;    // c cannot create object unless virtual functions(fun1) are overridden
    b = &d;    //base class pointer to derived class obj
    b->func1();  // call to polymorphed/overridden fuction 
    // d.func1();
    d.func2();   // cannot be called using base class object/pointer
    return 0;
}