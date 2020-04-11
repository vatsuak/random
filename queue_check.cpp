#include <iostream>
#include <queue>
#include <string>
using namespace std;

void pusher(std::queue<int*> &collec, int &a, int &b, int &c){
    a = 8;
    collec.push(&a);
    collec.push(&b);
    collec.push(&c);
}

int main(){
    int a = 5, b=3, c=4;
    queue<int*> que;
    pusher(que,a,b,c);
    while(!(que.empty())){
        cout << que.front() <<endl;
        cout << *que.front() <<endl;
        que.pop();

    }
    cout<<a<<b<<c;
    return 0;
}