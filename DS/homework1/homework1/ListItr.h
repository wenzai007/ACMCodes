
#include <iostream>
using namespace std;
template<class ElemType> class ListItr{
private:ListNode<ElemType> * const  head;
		 ListNode<ElemType> *Current;
          

public:   ListItr(const List<ElemType> &m):head(m.head){
           
		  Current=m.IsEmpty()?m.head:m.head->Next;     
		  }     
		   ~ListItr(){}
           int Find(const ElemType &x);
		   int IsFind(const ElemType &x) const;
		   void Insert(const ElemType &x);
		   int Remove (const ElemType &x);
		   int operator +()const{
			   return Current&&Current!=head;  //就是  说当前的current不为空且不是头指针！
		   }
		   const ElemType & operator() () const; // current listnode's data
		   void operator ++(); //make the next node  current node
		   void operator ++(int ){operator++(); }
		   void Zeroth(){Current=head;}
		   void First();
          // const ListItr<ElemType>& operator=(const ListItr<ElemType>&L); 
		//   List< ElemType>   mixofthem(List<ElemType> & a, List< ElemType>& b);
		  //  List< ElemType>   mixofthem(ListItr<ElemType> & a);
			void   mixofthem(ListItr<ElemType> & a,ListItr<ElemType> & Ctr);
          void  sort(List <ElemType> &m);

};	

    
      template <class ElemType> 
	  void ListItr<ElemType>:: Insert(const ElemType &x){
				  ListNode<ElemType>*p;
				  p=new ListNode<ElemType>();
				  p->Element=x;
		          if(Current==NULL)
					  cout<<"the location is illegal!"<<endl;
				  //*
                      
					   if(Current->Next=NULL){
						       Current->Next =p;
							   Current=Current->Next;
					   }
						  p->Next=Current->Next;
					   Current->Next=p;
					   Current=p;
                    //*/

              /*   
				  ListNode<ElemType>*p;
				   p=new ListNode<ElemType>(x,Current->Next);
                   Current=Current->Next;
                //*/
	  }

	  template <class ElemType> 
	  int  ListItr<ElemType>:: Find(const ElemType &x){
		      ListNode<ElemType> *p;
			  p=head->Next;
			  while(p!NULL&&(p->Element!=x)){p=p->Next;}
			  if (p==NULL){cout<<" not  found!!"<<endl;return 0;}
			  Current=p;
			  return 1;
	  }

	  template <class ElemType>
	  int ListItr<ElemType>::IsFind(const ElemType &x) const{
                 ListNode<ElemType> *p;
				 p=head->Next;
				 while (p!=NULL&&(p->Element!=x))p=p->Next;
				 return p!=NULL;

	  }

      template <class ElemType>
	  int ListItr<ElemType> :: Remove(const ElemType &x){
                     ListNode<ElemType>  *p;     //  p is not a pointer pointing anything  new ,so we can't delete p!! 
					 p=head;
					 while(p->Next!=NULL&&(p->Next->Element!=x)){p=p->Next;}
					 if (p->Next==NULL){cout<<" not  found!!"<<endl;return 0;}
					 p->Next=p->Next->Next;
                    
					 
					 //test whether mine is right!
					 p=p->Next;
					 delete p;
					 Current=head;
					 return 1;
                   /*                   //this is from the book!
                     ListNode<ElemType>*pp;
					 pp=p->Next;
					 delete pp;
                     Current=head;
					 return 1;
					 //*/
	  }
	  

	  template< class ElemType>
	  const ElemType & ListItr<ElemType>::operator ()  ()const{
		  if (Current==head) {cout<<"this is head !!  sorry,  location wrong!"<<endl;}
		  return Current->Element;

	  }
	   template <class  ElemType>

	   void ListItr< ElemType>:: operator ++() { 
                 if (Current->Next==NULL)cout<<"no no, next is null!"<<endl;
                  Current=Current->Next;

	   }

	   /*
	   template <class  ElemType>
	   const ListItr< ElemType>&  ListItr< ElemType>::operator =(ListItr<ElemType> &R){
                           if (this ==&R) return *this;
                           else if(head!=R.head)cout<<"no    another lsit  error!"<<endl;
						Current=R.Current;	  
                          return *this;
	   }

	   //*/

     
	   template <class ElemType>
	   void ListItr <ElemType>::First(){
		   if (head->Next==NULL)cout<<"it is empty!"<<endl;
           Current=head->Next;
	   }




	   /*
 template<class ElemType>
 List< ElemType>  ListItr< ElemType>:: mixofthem(List<ElemType> & a, List< ElemType>& b){//求a和b的交集  存在c里面
                       ListNode< ElemType>* ptr;
					   List< ElemType> C ;
					   ListItr<ElemType> Ctr(C);
					   ListItr<ElemType> atr(a);
 					   ListItr<ElemType> btr(b);
					   double mm=1.3;
					   atr.Zeroth();btr.Zeroth();
					 //  if(atr.head->Next==NULL||btr.head->Next==NULL)cout<<"error"<<endl;  //！！抛出异常了 注意接收！
					   for(ptr=atr.head->Next;ptr->Next!=NULL;ptr=ptr->Next){
                               ElemType ee= ptr->Element;
							   if( btr.IsFind(ee)  )
								   Ctr.Insert(ee);

					   }
					   Ctr.First();
                  return C;

 } 
//*/
 template<class ElemType>
void  ListItr< ElemType>:: mixofthem(ListItr<ElemType> & a,ListItr<ElemType> & Ctr){//求a和b的交集  存在c里面
	 
	 
	 
	 
	
	 int count=1;
	 a.Zeroth();
	 //  if(atr.head->Next==NULL||btr.head->Next==NULL)cout<<"error"<<endl;  //！！抛出异常了 注意接收！
	 for(Current=head->Next;Current!=NULL;Current=Current->Next){
		
		
		 
		 if( a.IsFind(Current->Element)  )
		 {  cout<<count++<<endl;
             
		  Ctr.Insert(Current->Element);
		   cout<<Ctr()<<endl;
		   
		 }


	
//*/
	 }
	// getchar();

	// Ctr.First();
	// return C;

 } 
 template <class ElemType >
 void ListItr<ElemType>:: sort(List <ElemType> &m){                //选择排序！！！
            ListItr<ElemType> mtr (m);
            if(mtr.head->Next==NULL)cout<<"this is a empty list"<<endl;
			ListNode<ElemType> *p1;
			ListNode<ElemType>*p2;
			
			
			for(p1=mtr.head->Next;p1!=NULL;p1=p1->Next){
				ElemType minimal=p1->Element;
				       ListNode<ElemType >*pmin=p1;
				for(p2=p1->Next;p2!=NULL;p2=p2->Next){
					if(p2->Element<minimal){ 
						minimal=p2->Element;
						pmin=p2;

					}
      					
				}
				if(minimal!=p1->Element){
				ElemType tmp=p1->Element;
				p1->Element=minimal;
				pmin->Element=tmp;
				}
			}

 }


