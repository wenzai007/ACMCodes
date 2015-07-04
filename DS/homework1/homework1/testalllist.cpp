
#include <iostream>

#include "ListNode.h"

#include "List.h"

#include "ListItr.h"
//*/
 using namespace std;


void main(){

    List<double> a1;
	 List<double> a2;
   ListItr<double> atr1(a1);
     ListItr<double> atr2(a2);
   double a=4.2;double b=5.3;
   atr1.Insert(2.5);
   atr1.Insert(1.2);
   atr1.Insert(4);
   atr1.Insert(45);
   atr1.Insert(8);
   atr1.Insert(9);
   
	atr1.First();//归位头指针！
    
	
    
	atr2.Insert(2.5);
	atr2.Insert(1.2);
	atr2.Insert(4);
	atr2.Insert(12);
	atr2.Insert(1);
	atr2.Insert(22);
	atr2.Insert(9);
        atr2.First();
    
	//getchar();
  // ListItr<double> mixh(mixhehe);
   atr1.First();
   atr2.First();
   cout<<" element of  a1"<<endl;
   for(;+atr1;atr1++){
		cout<<atr1()<<"   "<<endl;
   }
    cout<<" element of  a2"<<endl;
	for(;+atr2;atr2++){
		cout<<atr2()<<"   "<<endl;
	}

    List<double> kong;
	List<double>  mixlist;
	ListItr<double>  mixh(mixlist);
   atr1.mixofthem(atr2,mixh);
   	
	cout<< " a1 是不是空的"<< a1.IsEmpty()<<endl;
	cout<< " mixlist 是不是空的"<< mixlist.IsEmpty()<<endl;//  it says mixlist is not empty!!!!!!
	cout<< " kong 是不是空的"<< kong.IsEmpty()<<endl;
	
       cout<<" mix elements of  them"<<endl;

     
	  mixh.First();
	  for(;+mixh;mixh++){
		  cout<<mixh()<<"   "<<endl;
	  }
	   /*
	  mixh++;
	  cout<<mixh()<<endl;
	
	  mixh++;
	
	  cout<<mixh()<<endl;
	     
	  mixh++;
	  cout<<mixh()<<endl;
 
   //*/
	  /*
	   for(;+mixh;mixh++){
		   cout<<mixh()<<"   "<<endl;
	   }
       //*/
   getchar();

  
}

