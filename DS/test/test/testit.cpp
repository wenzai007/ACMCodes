#include "ready.h"
#include <iostream>
using namespace std;

 
  class A {
  private:int a,b,c;
  public:  A(){}
		  A(int m):a(m){}
		   //A(int m,int n):a(m),b(n){}
		   A(int m,int n,int p):a(m),b(n),c(p){}
		   void  display(){
			   cout<<"a:     "<<a<<"b:    "<<b<<"c:     "<<c<<endl;

		   }

};

  void main(){
	  
	A  q=A();
	//A  w=A(1);
	//A   e=A(1,2);
	A r=A(1,2,3);
	A y=A(1);
	q.display();
	//w.display();
	//e.display();
	r.display();
	y.display();
	getchar();
	  
	  /*
	  double a,b;
	  a=1.0;
	  b=20.2;
	  
        testdubug(a);	

		cout<<"wait for a while!"<<endl;

		
			testdubug(b);
			  
	  getchar();
	  //*/
  }