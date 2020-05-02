#include<iostream>
using namespace std;

int main(){
    int A[] = {2,4,6,8,10};
    // int i;
    // for(i=0;i<A.size();i++){
    //     cout << A[i] << endl;
    // }
    int sum = 0;
    for(int i: A){
        sum += i;
    }
    cout<<sum;
    return 0;
}