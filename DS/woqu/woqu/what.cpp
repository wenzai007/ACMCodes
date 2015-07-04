#include <iostream>
using namespace std;

template<typename T>  
void exchange(T a,T b){  //就是玩了一个小游戏   把a b的地址交换了一下
	*a=*a+*b;  
	*b=*a-*b;  
	*a=*a-*b;  
}  
void main(){
	cout<<"hello world!"<<endl;
	
	int a=12;
   int b=9;
   cout<<a<<endl;
   cout<<b<<endl;
   exchange(&a,&b);
  
   cout<<a<<endl;
   cout<<b<<endl;
   getchar();

}