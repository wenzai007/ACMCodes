
#include<iostream>
using namespace std;


#include "complex.h"
complex:: complex(double  x, double y)  //构造函数
{
	real=x; 
    imag=y;
}
complex::complex(const complex & a) //拷贝构造函数
{real=2*a.real;imag=2*a.imag;}


 complex complex::operator-(const complex & a) const//重载减法函数
{return complex(real-a.real,imag-a.imag);


}

 complex complex::operator+(const complex & a) const//重载加法函数
{
  return complex(real+a.real,imag+a.imag);

}

 complex complex::operator*(const complex & a) const//重载乘法函数
{
  return complex((real*a.real-imag*a.imag),(real*a.imag+imag*a.real));
}
 complex complex::operator/(const complex & a) const//附加：  重载除法函数
{
  return complex((real*a.real+imag*a.imag)/(a.real*a.real+a.imag*a.imag),(imag*a.real-real*a.imag)/(a.real*a.real+a.imag*a.imag));
}


  complex complex::operator!() const//附加：  求倒数
  {return complex(real/(real*real+imag*imag),-imag/( real*real+imag*imag)
)  ;}
  

 ostream& operator<<(ostream&os, const complex& obj) // 输出重载函数
{ if (obj.imag>=0)  os<<obj.real<< "+"<< obj.imag<<"i"<<endl;
else os<<obj.real<< obj.imag<<"i"<<endl;
   return os;
}
