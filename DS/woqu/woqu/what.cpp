#include <iostream>
using namespace std;

template<typename T>  
void exchange(T a,T b){  //��������һ��С��Ϸ   ��a b�ĵ�ַ������һ��
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