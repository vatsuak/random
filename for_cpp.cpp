#include <iostream>
#include <Eigen/Dense>
#include<vector>
#include <ctime>
#include <time.h>
using namespace std;
double rad2Deg(double t_radian){
            return t_radian*180/M_PI;
		}

Eigen::Vector3f quaternionToEulerAngles(Eigen::Vector4f &q){
    float sinr_cosp = +2.0 * (q(0) * q(1) + q(2) * q(3));
    float cosr_cosp = +1.0 - 2.0 * (q(1) * q(1) + q(2) * q(2));
    float roll = atan2(sinr_cosp, cosr_cosp);
    float pitch;
    float sinp = +2.0 * (q(0) * q(2) - q(3) * q(1));
    if (fabs(sinp) >= 1)
        float pitch = copysign(M_PI / 2, sinp); // use 90 degrees if out of range
    else
        float pitch = asin(sinp);

    float siny_cosp = +2.0 * (q(0) * q(3) + q(1) * q(2));
    float cosy_cosp = +1.0 - 2.0 * (q(2) * q(2) + q(3) * q(3));  
    float yaw = atan2(siny_cosp, cosy_cosp);

    return Eigen::Vector3f(roll,pitch,yaw);
}
Eigen::Vector4f rotationMatrixToQuaternions(Eigen::Matrix3f &t_R){
    float trace = t_R(0,0) + t_R(1,1) + t_R(2,2);
    float w,x,y,z;
    if( trace > 0 ) {
        float s = 0.5f / sqrtf(trace+ 1.0f);
        w = 0.25f / s;
        x = ( t_R(2,1) - t_R(1,2) ) * s;
        y = ( t_R(0,2) - t_R(2,0) ) * s;
        z = ( t_R(1,0) - t_R(0,1) ) * s;
    } 
    else {
        if ( t_R(0,0) > t_R(1,1) && t_R(0,0) > t_R(2,2) ) {
            float s = 2.0f * sqrtf( 1.0f + t_R(0,0) - t_R(1,1) - t_R(2,2));
            w = (t_R(2,1) - t_R(1,2) ) / s;
            x = 0.25f * s;
            y = (t_R(0,1) + t_R(1,0) ) / s;
            z = (t_R(0,2) + t_R(2,0) ) / s;
        } 
        else if (t_R(1,1) > t_R(2,2)) {
            float s = 2.0f * sqrtf( 1.0f + t_R(1,1) - t_R(0,0) - t_R(2,2));
            w = (t_R(0,2) - t_R(2,0) ) / s;
            x = (t_R(0,1) + t_R(1,0) ) / s;
            y = 0.25f * s;
            z = (t_R(1,2) + t_R(2,1) ) / s;
        } 
        else {
            float s = 2.0f * sqrtf( 1.0f +t_R(2,2) -t_R(0,0) -t_R(1,1) );
            w = (t_R(1,0) -t_R(0,1) ) / s;
            x = (t_R(0,2) +t_R(2,0) ) / s;
            y = (t_R(1,2) +t_R(2,1) ) / s;
            z = 0.25f * s;
        }
    }
    return Eigen::Vector4f(w,x,y,z);
}
Eigen::Vector3f rotationMatrixToEulerAngles(Eigen::Matrix3f &t_R){
    // assert(isRotationMatrix(t_R));
    // float sy = std::sqrt(t_R(0,0) * (0,0) +  
    //                      t_R(1,0) * (1,0));
    
    // bool singular = sy < 1e-6; 
    
    float x_1, y_1, z_1;
    if (std::abs(t_R(2,1)) != 1){
        y_1 = rad2Deg(std::asin(t_R(2,0)));
        // y_2 = rad2Deg(3.14 - y_1);
        x_1 = rad2Deg(std::atan2(t_R(2,1)/cos(y_1),t_R(2,2)/cos(y_1)));
        // x_2 = rad2Deg(std::atan2(t_R(3,2)/cos(y_2),t_R(3,3)/cos(y_2));
        z_1 = rad2Deg(std::atan2(t_R(1,0)/cos(y_1),t_R(0,0)/cos(y_1)));
        // z_2 = rad2Deg(std::atan2(t_R(2,1)/cos(y_2),t_R(1,1)/cos(y_1));
    }
    else{
        z_1 = 0;
        if(t_R(2,0)==-1.0){
            y_1 = rad2Deg(M_PI/2);
            x_1 = rad2Deg(std::atan2(t_R(0,1), t_R(1,2)));
        }
        else{
            y_1 = -1*rad2Deg(M_PI/2);
            x_1 = rad2Deg(std::atan2(-t_R(0,1), -t_R(0,2)));
        }
    }

    return Eigen::Vector3f(x_1, y_1, z_1);
}

int* fun(int* arr){
    // int *p = new int[5];
    for(int i=0;i<5;i++){
        arr[i] = i+1;
    }
    cout<<arr;
    return arr;
}
int check_value(int &x){
    int* y = &x;
    return (*y)+1;
}
int main(){
    int b,c;
    // string 
    // cout<<"Enter two numbers"<<endl;
    // cin>>a;
    // cin>>b;
    // c = a+b;
    // cout<<"The addition is "<<c<<endl;
    // cout<<"hello";
    // int p[5];
    // int *q=fun(p);
    // cout<<q[0];
    // int p = 5;
    // Eigen::Vector4f qua;
    // qua(0) = 0;
    // qua(1) = 0;
    // qua(2) = 1;
    // qua(3) = 0;
    // Eigen::Matrix3f t_R = Eigen::Matrix3f::Identity();
    // // t_R(0,0) = -1.0;
    // t_R << 0.707,-.707, 0, 0.707,.707, 0,0,0,1;
    // // t_R(2,2) = -1.0;
    // Eigen::Vector3f angle = quaternionToEulerAngles(qua);
    // Eigen::Vector4f qu = rotationMatrixToQuaternions(t_R);
    // angle = rotationMatrixToEulerAngles(t_R);
    // cout<<angle<<endl;
    // std::vector<int> ints;
    // ints.push_back(10);
    // ints.push_back(20);
    // ints.push_back(30);
    int a[] = {1,2,3,4};
    const int * ptr = a;
    cout<<*(ptr)<<endl;
       time_t currentTime;

   // get and print the current time
   time (&currentTime); // fill now with the current time
   cout << "It is now " << ctime(&currentTime) << endl;

    return 0;
}
