#include<iostream>
using namespace std;
void add1()
{ int i=0;
cout<<"i of add1()="<<++i<<endl;
}

void add2()
{ static int j=3;
cout<<"now the j="<<++j<<endl;
}


int x=123;

int main()
{int i=5;int j;
add1();
cout<<"qingshuru   j"<<endl;
cin>>j;
getchar();
cout<<"i of main is "<<i+j<<endl;
add1();
add1();
add2();
add2();
add2();
add2();
extern int x,y;
cout<<"x="<<x<<",y="<<y<<endl;
getchar();
return 0;
   }

int y=321;


