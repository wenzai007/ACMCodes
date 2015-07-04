#ifndef MYEXCEPTION_H 
#define MYEXCEPTION_H  
#include<iostream>
using namespace std;

class BalanceLessThanZeroException {
 public:
     BalanceLessThanZeroException()
              : message( "the Balance now is less than zero" ) { }//³ö´íÊ±±¨´íthe Balance now is less than zero
     const char *what() const { return message; }
 private:
     const char *message;
 };

#endif 
