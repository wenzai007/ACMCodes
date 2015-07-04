#include<iostream>
using namespace std;


int main()
{ int score;
   cout<<"please input your score"<<endl;
    cin>>score;
	  switch(score/10)

	  { case 10:
	  case 9:{cout<<"your score is A"<<endl;
			 break;}

	  case 8: {cout<<"your score is B"<<endl;
			  break;}
	  case 7:  {cout<<"your score is C"<<endl;
			   break;}
			   
	  default: cout<<"your score is d....oh..."<<endl;
		      



	  }  return 0;

}