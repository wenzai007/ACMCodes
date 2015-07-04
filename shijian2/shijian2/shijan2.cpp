#include<iostream>
using namespace std;//此程序为++放在变量之前和之后的区别！！
int main()
{  int i=3;
   
  int j;
   for(j=4;j>0;--j)
   {   
	   cout<<"i="<<i++<<endl;

   }
   return 0;
}