#include<iostream>
using namespace std;
class  complex
{ 
private: double real;
        double imag;
public:    complex(double = 0.0,double =0.0);//���캯��
		   complex(const complex &a );//�������캯��
		   complex  operator+(const complex & a)const ;//���ؼӷ�����
           complex  operator-(const complex & a)	const  ;//���ؼ�������
		   complex  operator*(const complex & a) const;//���س˷�����
		   complex  operator/(const complex & a) const;//���س�������
		   complex  operator!() const;//���ص�������
		 friend ostream& operator<<(ostream &os, const complex & obj) ;//�����������
                                     
};
