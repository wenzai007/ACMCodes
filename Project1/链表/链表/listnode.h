#ifndef LISTNODE
#define LISTNODE

#include"list.h"
#include<iostream>
using namespace std;
template<class ElemType>class List;
template<class ElemType>class ListNode
{
	friend class List<ElemType>;
	private:
		ListNode<ElemType>*next;
		ElemType Element;
	public:
		ListNode (const ElemType &E,ListNode<ElemType>*N=NULL):Element(E),next(N){}
		ListNode():next(NULL){}
		~ListNode(){}
};
#endif