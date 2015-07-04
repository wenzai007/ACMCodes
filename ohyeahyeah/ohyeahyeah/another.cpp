/*
#include <iostream>
using namespace std;

void main(){
	void  change(int a,int b);
	int a,b,c;
	a=1;b=2;c=3;
	cout<<"balbalablalalalal "<<a<<endl;
	cout<<"b:   "<<b<<endl;
	cout<<"c:   "<<c<<endl;
	change(a,b);
	cout<<"a:   "<<a<<endl;
	cout<<"b:   "<<b<<endl;
	getchar();

}
void  change(int a,int b){
	int tmp;
	tmp=b;
	b=a;
	a=tmp;

}
//*/
template <class ElemType> 
List<ElemType> & List<ElemType> :: operator^(List<ElemType> & B)
{
	if(head->next==NULL||B.head->next==NULL)
	{head->next=NULL;
	return *this;}
	else
	{ListNode<ElemType>*q=head;
	ListNode<ElemType>*temp=head;
	ListNode<ElemType>*p;
	ElemType x;
	while(q->next!=NULL)
	{
		p=B.head->next;
		while(p!=NULL)
		{
			if(q->next->Element!=p->Element)
				p=p->next;
			else
				break;
		}

		if(p==NULL)Remove(q,x);
		else
			q=q->next;
	}
	Arrange();
	while(temp->next!=NULL)
	{   
		temp=temp->next;
		while(temp->next!=NULL&&temp->Element==temp->next->Element)
			Remove(temp,x);
	}
	return*this;
	}
                      
}
