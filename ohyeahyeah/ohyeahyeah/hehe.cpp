/*
#include "another.cpp"
#include <iostream>
using namespace std;







template<class ElemType>
ElemType  chan(ElemType &a, ElemType &b);    //此时发生错误   在main函数之前没有进行声明

void main(){
	int *p=new int[3];
	 int m=2;	 
	 int b=3333;
	 

	 int cc;
	 cc=chan(m,b);
	 cout<<"c:   --"<<cc<<endl;
	  delete p;//错了我   之前不是new  出来的不可以delet  new 与delet对应！！	 
	
	 if(p==NULL){
	 cout<<a<<endl;
	 }else cout<<b<<endl;
     

	

   
	  cout<<"p  adress"<<p<<endl;
	// cout<<"p指向的:    "<<*p<<endl;
	getchar();

	/*
	void  change(int a,int b);
	int a,b,c;
	a=1;b=2;c=3;
	cout<<"asdfasfsadfasdf   "<<a<<endl;
	cout<<"b:   "<<b<<endl;
	cout<<"c:   "<<c<<endl;
	getchar();
	change(a,b);
	cout<<"a:   "<<a<<endl;
	cout<<"b:   "<<b<<endl;
	getchar();

    
//*/


    //}
 /*  void  change(int a,int b){
	int tmp;
	tmp=b;
	b=a;
	a=tmp;

}
//*/

/*
template<class ElemType>
ElemType   chan(ElemType &a, ElemType &b){
	return (a+b);


}

//*/


 
//*/-----