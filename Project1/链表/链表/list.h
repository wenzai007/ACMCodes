#ifndef LIST
#define LIST

#include"listnode.h"
#include<iostream>
using namespace std;
template <class ElemType>class List
{
	private:
		ListNode<ElemType>*head;
		  ListNode<ElemType>*Current;     
		
	public:
        List(){head=new ListNode<ElemType>();Current=IsEmpty()?head:head->next;}
		~List(){MakeEmpty();delete head;}
		void Insert(const ElemType&x);
		int Remove(const ElemType&x);
		int IsEmpty()const {return head->next==NULL;}
		void MakeEmpty();
			void Travels();
};


template <class ElemType> 
void List<ElemType> :: MakeEmpty( ) 
{ 
	ListNode<ElemType> * Ptr; 
	ListNode<ElemType> * NextNode;
	for ( Ptr = head->next; Ptr != NULL; Ptr=NextNode ) 
 	{	NextNode = Ptr->next;
		delete Ptr;
 	}
	head->next = NULL;
}


template <class ElemType> 
void List<ElemType> ::Insert(const ElemType & x )//在current结点后插入值为x的结点,插入成功返回，否则返回.
{	

	if (!Current) cout<<"the location is illegal!"<<endl;
    ListNode<ElemType> * tmp;
   	tmp=new ListNode<ElemType>(x,Current->next);  
    	Current=Current->next=tmp;

}


template <class ElemType> 
int List<ElemType>::Remove(const ElemType & x )//删除current结点后的一个结点，值放入x内。删除成功返回，否则返回
{	
	ListNode<ElemType>*Ptr=head;
	while (Ptr->next!=NULL&&!(Ptr->next->Element==x)) Ptr=Ptr->next;
	if(Ptr->next==NULL) return 0;
	ListNode<ElemType>*P=Ptr->next;
	Ptr->next=Ptr->next->next;
	delete P;
	Current=head;
	return 1;

}
template <class ElemType> 
void List<ElemType> :: Travels( )
{ 
	ListNode<ElemType> * Ptr; 
	Ptr=head->next;
	while (Ptr)
	{ 	cout<<Ptr->Element<<"   ";
		Ptr=Ptr->next;
	}
}


#endif


				
