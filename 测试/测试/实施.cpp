//this is a program that tell customers about their incom in share
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::left;
using std::right;

#include <iomanip>
using std::setw;
using std::setprecision;

int main()
{
	int money,day;
	double Quotient,currentvalue,netvalue1,netvalue2,rate,currentpayoff,sumnetvalue;
	cout <<"Please input your money(>1000, and multiple):"<<endl;
	cin >>money;
	//begin checking whether the money of the costumers is right
	while (money<=1000||money%1000!=0)
	{
    cout <<money<<" is not multiple of 1000."<<endl;
    cin>>money;
	} //end while
		cout<< "Please input everyday net value in this week:"<<endl;
       
        //make the result which costumers want to know
        for(netvalue2=1,day=1,sumnetvalue=0;day<=5;++day,netvalue2=netvalue1)
		{//netvalue1 is the Net Value of today,netvalue is the Net Value of yesterday
        cin>>netvalue1;
        
        if (day==1){
			cout<<left<<setw(11)<<"Quotient"<<left<<setw(13)<<"Net Value"<<left
				<<setw(18)<<"Increase Rate"<<left<<setw(18)<<"Current Value"<<left<<setw(13)<<"Current payoff\n";
        } //end if  
		Quotient=money*(1-0.015)/1;
		cout<<left<<fixed<<setprecision(0)<<setw(13)<<Quotient;//tell  Costumers the Quotient
		//get the result of the total of the Net Value
        
		} //end for
	    
			
		cout<<"Average Net Value in this week = "<<fixed<<setprecision(5)<<sumnetvalue/5<<endl;
		//tell the costumers the Average Net Value in this week
		
		return 0;
} //end main       		    
	