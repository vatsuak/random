#include <iostream>
#include <queue>
#include <string>
using namespace std;

void pusher(std::queue<int*> &collec, int &a, int &b, int &c){
    collec.push(&a);
    collec.push(&b);
    collec.push(&c);
    a = 100;
}

int main(){
    int a = 5, b=3, c=4;
    queue<int*> que;
    cout<<"a"<<a<<endl;
    pusher(que,a,b,c);
    while(!(que.empty())){
        cout << que.front() <<endl;
        cout << *que.front() <<endl;
        que.pop();
    }
    cout<<"a"<<a<<endl;
    return 0;
}