
template <class ElemType> class ListItr;
template <class ElemType> 
class List{
	
	friend class ListItr <ElemType>;   
	
private:ListNode<ElemType> *head;

public:List(){
		   head=new ListNode<ElemType>();
	   }
	
	   ~List(){MakeEmpty();delete head;}
         const List & operator=(const List & R);
		 int IsEmpty() const{return head->Next==NULL;} 
		 int IsFull()  const {return 0;}//”¿‘∂≤ªª·¬˙£ø£ø£ø
		 void MakeEmpty();
		 
		 

} ;


template<class ElemType>
void   List <ElemType>::MakeEmpty(){
	  ListNode<ElemType> *p;
	  ListNode<ElemType> *NextNode;
	  for(p=head->Next;p!=NULL;p=NextNode){
              NextNode=p->Next;
			  delete p;
	  }
}




template <class  ElemType>
const List<ElemType> &  List<ElemType>::operator=(const List<ElemType>& l){
                          
                

}