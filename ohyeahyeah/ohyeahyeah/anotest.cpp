#include <iostream>
using namespace std;



  int & lala(int &a ,int & b,int & c){
             c=a+b;
			
          return c;
}


void main(){
	int a=1;int b=2;
 //  int &c=lala(a,b);
 
int &c=a;
 cout<<lala(a,b, c)<<endl;
 
 getchar();
}
