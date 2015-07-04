

#include<iostream>
using namespace std;
 
#include "complex.h"


int main()
{  complex a(6.5,2.5),b(a),c=a,d(5.5,1.5),e,f,g,x(2,3),y(1,1),h,w;
e=a+d;f=a-d;g=a*d;h=x/y;w=!x;
cout<<a; 
cout<<b; 
cout<<c; 
cout<<d; 
cout<<e; 
cout<<f; 
cout<<g;
cout<<h;
cout<<w;
getchar();
return 0;
}