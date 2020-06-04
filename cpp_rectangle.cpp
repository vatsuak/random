#include<iostream>

class Rectangle{
     public:
	int len;
	int br;
	int area(){
	     return len*br;
        }
	int peri(){
	    return 2*(len+br);
	}
};
int main(){
     Rectangle *rect;
     Rectangle rec;
     rect = &rec;
     rect->len = 5;
     rect->br = 10;
     std::cout<<rect->area()<<std::endl;
     std::cout<<rect->peri()<<std::endl;
}     
