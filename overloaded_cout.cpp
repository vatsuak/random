#include<iostream>
using namespace std;
class Namer{
    string name;
    public:                                         // constuctors are generally public unless specific tasks are required
        Namer(string name = "Hello World"){
            this->name = name;     // this is a pointer in C++ represents the object 
        }
        void get_name(){
            cout<<name;
        }
    friend ostream & operator<<(ostream &o, Namer obj){ //friend functions are not part of the class so logically should be defined outside
        o<<"Hello "<<obj.name;
        return o;
    }
};


int main(){
    Namer obj;
    cout<<obj;
    return 0;
}