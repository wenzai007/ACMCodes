#include<iostream>
using namespace std;
int main(){
int *a=new int[5],i,sumeven=0,sumodd=0;
do {for(i=0;i<5;i++)
{cout<<"please input a["<<i<<"]"<<endl;
  cin>>*(a+i);
  if(*(a+i)%2==0) sumeven+=*(a+i);
  else  sumodd+=*(a+i);
  }
cout<<"oushu he:"<<sumeven<<"    jishuhe:"<<sumodd<<endl;} while(sumodd!=9);
  return 0;
}