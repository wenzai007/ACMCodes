
#include<iostream>
using namespace std;


#include "complex.h"
complex:: complex(double  x, double y)  //���캯��
{
	real=x; 
    imag=y;
}
complex::complex(const complex & a) //�������캯��
{real=2*a.real;imag=2*a.imag;}


 complex complex::operator-(const complex & a) const//���ؼ�������
{return complex(real-a.real,imag-a.imag);


}

 complex complex::operator+(const complex & a) const//���ؼӷ�����
{
  return complex(real+a.real,imag+a.imag);

}

 complex complex::operator*(const complex & a) const//���س˷�����
{
  return complex((real*a.real-imag*a.imag),(real*a.imag+imag*a.real));
}
 complex complex::operator/(const complex & a) const//���ӣ�  ���س�������
{
  return complex((real*a.real+imag*a.imag)/(a.real*a.real+a.imag*a.imag),(imag*a.real-real*a.imag)/(a.real*a.real+a.imag*a.imag));
}


  complex complex::operator!() const//���ӣ�  ����
  {return complex(real/(real*real+imag*imag),-imag/( real*real+imag*imag)
)  ;}
  

 ostream& operator<<(ostream&os, const complex& obj) // ������غ���
{ if (obj.imag>=0)  os<<obj.real<< "+"<< obj.imag<<"i"<<endl;
else os<<obj.real<< obj.imag<<"i"<<endl;
   return os;
}
