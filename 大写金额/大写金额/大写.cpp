 /*
 
 #include<iostream>
#include<math.h>
using namespace std;
void main()
{  int j=0;
  double x,i=10000000;
  unsigned int quotient,remainder;
bool beginflag=0,zeroflag=0;
  cout<<"please  input your count(С��һ��)"<<endl;
cin>>x;
while(x>=100000000)
{if(j>=2){ cout<<"�������� sb�� ���������������"<<endl;return;}
    cout<<"�������Ӧ�����������Ӧ��С��һ�ڣ�֪������"<<endl;
    cin>>x;
	j++;
     }
if (x<=0){cout<<"��"<<endl;  
return;}

x=floor(x*100+0.5)/100;

while (i>0.001){

if (i>0.9)
quotient=(unsigned int) floor(x/i);
else 
{if(i>0.099)
quotient=(unsigned int) floor(x*10);
else 
quotient=(unsigned int) floor(x*100);}

remainder=quotient%10;

if(remainder!=0)
beginflag=1;

if ((zeroflag=1)&&(beginflag=1)&&(i>1000) &&(remainder>0))
    cout<<"��";

switch(remainder)
{			
			case 0:	
				break;
			case 1:	
				cout<<"Ҽ";
				break;	
			case 2:		
				cout<<"��";
				break;	
			case 3:		
				cout<<"��";	
				break;		
			case 4:			
				cout<<"��";	
				break;		
			case 5:		
				cout<<"��";	
				break;		
			case 6:		
				cout<<"½";	
				break;		
			case 7:		
				cout<<"��";	
				break;		
			case 8:			
				cout<<"��";	
				break;		
			case 9:			
				cout<<"��";	
				break;	
		}	

if (remainder>0)
zeroflag=0;
else if (beginflag=1)
zeroflag=1;

if (beginflag=1)
{if( (i=10000000)&&(remainder>0))cout<<"Ǫ";
if ((i=1000000)&&(remainder>0))cout<<"��";
if ((i=100000)&&(remainder>0))cout<<"ʮ";
if ((i=10000)&&(remainder>0))cout<<"��";
if ((i=1000)&&(remainder>0))cout<<"Ǫ";
if ((i=100)&&(remainder>0))cout<<"��";
if ((i=10)&&(remainder>0))cout<<"ʮ";
if ((i=1)&&(remainder>0))cout<<"Ԫ";
if ((i=0.1)&&(remainder>0))cout<<"��";
if ((i=0.01)&&(remainder>0))cout<<"��";
}

  i=i/10;}

}
  
