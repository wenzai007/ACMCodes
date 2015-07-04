

#include<iostream>
using namespace std;
 
#include "complex.h"


int main()
{  complex a(6.5,2.5),b(a),c=a,d(5.5,1.5),e,f,g;
e=a+d;f=a-d;g=a*d;
a.print(); 
b.print(); 
c.print();
e.print();
f.print();
g.print();
return 0;
}