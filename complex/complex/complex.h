#include<iostream>
using namespace std;
class  complex
{ 
private: double real;
        double imag;
public:    complex(double = 0.0,double =0.0);//构造函数
		   complex(const complex &a );//拷贝构造函数
		   complex  operator+(const complex & a)const ;//重载加法函数
           complex  operator-(const complex & a)	const  ;//重载减法函数
		   complex  operator*(const complex & a) const;//重载乘法函数
		   complex  operator/(const complex & a) const;//重载除法函数
		   complex  operator!() const;//重载倒数函数
		 friend ostream& operator<<(ostream &os, const complex & obj) ;//重载输出函数
                                     
};
