#include<iostream>
using namespace std;
class  complex
{ 
private: double real;
        double imag;
public:    complex(double = 0.0,double =0.0);
		   complex(const complex &a );
		   complex  operator+(const complex & a)const ;
           complex  operator-(const complex & a)	const  ;
		   complex  operator*(const complex & a) const;
		   void  print();
};
