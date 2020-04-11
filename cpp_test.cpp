#include<iostream>
using namespace std;

void main(){
    int A[] = {2,4,6,8,10};
    // int i;
    // for(i=0;i<A.size();i++){
    //     cout << A[i] << endl;
    // }
    for(int i: A){
        cout << i << endl;
    }
}