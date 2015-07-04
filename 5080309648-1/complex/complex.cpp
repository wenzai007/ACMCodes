
#include<iostream>
using namespace std;


#include "complex.h"
complex:: complex(double  x, double y)
{
	real=x; 
    imag=y;
}
complex::complex(const complex & a) 
{real=2*a.real;imag=2*a.imag;}


 complex complex::operator-(const complex & a) const
{return complex(real-a.real,imag-a.imag);


}

 complex complex::operator+(const complex & a) const
{
  return complex(real+a.real,imag+a.imag);

}

 complex complex::operator*(const complex & a) const
{
  return complex((real*a.real-imag*a.imag),(real*a.imag+imag*a.real));
}

void complex::print()
{if(imag==0)
cout<<real<<endl;
else  cout<<real<<"+"<<imag<<"i"<<endl;

}

