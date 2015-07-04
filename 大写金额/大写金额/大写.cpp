 /*
 
 #include<iostream>
#include<math.h>
using namespace std;
void main()
{  int j=0;
  double x,i=10000000;
  unsigned int quotient,remainder;
bool beginflag=0,zeroflag=0;
  cout<<"please  input your count(小于一亿)"<<endl;
cin>>x;
while(x>=100000000)
{if(j>=2){ cout<<"超过三次 sb， 不能他妈的输入了"<<endl;return;}
    cout<<"你他妈的应该输入的数字应该小于一亿，知道不？"<<endl;
    cin>>x;
	j++;
     }
if (x<=0){cout<<"零"<<endl;  
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
    cout<<"零";

switch(remainder)
{			
			case 0:	
				break;
			case 1:	
				cout<<"壹";
				break;	
			case 2:		
				cout<<"贰";
				break;	
			case 3:		
				cout<<"叁";	
				break;		
			case 4:			
				cout<<"肆";	
				break;		
			case 5:		
				cout<<"伍";	
				break;		
			case 6:		
				cout<<"陆";	
				break;		
			case 7:		
				cout<<"柒";	
				break;		
			case 8:			
				cout<<"捌";	
				break;		
			case 9:			
				cout<<"玖";	
				break;	
		}	

if (remainder>0)
zeroflag=0;
else if (beginflag=1)
zeroflag=1;

if (beginflag=1)
{if( (i=10000000)&&(remainder>0))cout<<"仟";
if ((i=1000000)&&(remainder>0))cout<<"百";
if ((i=100000)&&(remainder>0))cout<<"十";
if ((i=10000)&&(remainder>0))cout<<"万";
if ((i=1000)&&(remainder>0))cout<<"仟";
if ((i=100)&&(remainder>0))cout<<"百";
if ((i=10)&&(remainder>0))cout<<"十";
if ((i=1)&&(remainder>0))cout<<"元";
if ((i=0.1)&&(remainder>0))cout<<"角";
if ((i=0.01)&&(remainder>0))cout<<"分";
}

  i=i/10;}

}
  
