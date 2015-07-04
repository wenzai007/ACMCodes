#include<iostream>
using namespace std;



#include "savingaccount.h"
 



 savingaccount::savingaccount(double a) 
    {AnnualInterestRate=a; }


 void  savingaccount::modifyInterestRate(double r)
  {   AnnualInterestRate=r;}

   double  savingaccount::calculateMonthlyInterest()
 {double m; m=AnnualInterestRate/12;return m; }

  double savingaccount::getBalance()
  {double b; b=Balance*(1+calculateMonthlyInterest());return b;
  }


  



