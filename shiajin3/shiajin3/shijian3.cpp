#include<iostream>
using namespace std;
int main()
{int a=10+5;
int x=1,y=2,z=3;
z*=(y/=2)++;
  cout<<x<<"  "<<y<<"  "<<z<<"  "<<endl;
return 0;
}