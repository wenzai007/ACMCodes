#include<iostream>
using namespace std;

int coutdata();

int coutdata(){
int data=50;

return data;
}

int main()
{  coutdata();
	long value1=100;
  long value2=50;
  long temp=0;
  long *valueptr=NULL;

  valueptr=&value1;
  *valueptr+=50;
  temp=*valueptr;

  cout<<"&value1:"<<valueptr<<endl;
  cout<<"value+50="<<temp<<endl;
  cout<<"***********"<<endl;
  return 0;

 
}