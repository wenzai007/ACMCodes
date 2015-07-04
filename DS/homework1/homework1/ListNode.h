template <class ElemType> class List;
template <class ElemType> class ListItr;

template <class ElemType> class ListNode{

 friend class List<ElemType>;
 friend class ListItr<ElemType>;

private: ListNode<ElemType> *Next;
		  ElemType  Element;
public:ListNode(const ElemType &E,ListNode<ElemType> *N=NULL):Element(E),Next(N){}
	   ListNode():Next(NULL){}
	   ~ListNode(){};

};