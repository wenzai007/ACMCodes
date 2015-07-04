#include<iostream>
using namespace std;

int sum(int *a,int elementnum)
{int count=0;
int result=0;
for (count=0;count<elementnum;count++)
result+=a[count];
return result;
}

float sum1(float *b,int elementnum){float result=0;
int count;
for(count=0;count<elementnum;count++)
result+=b[count];
return result;
}

int main()
{int a[5]={1,4,5,7,9};
float b[8]={1.31,4.51,2.41,5.61,2.51,1.31,4.51,6.81};
cout<<"sum  of a is "<<sum(a,5)<<endl;
cout<<"sum of b is "<<sum1(b,5)<<endl;

return 0;
}