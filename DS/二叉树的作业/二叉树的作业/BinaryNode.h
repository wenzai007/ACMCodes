template<class T> class BinaryTree;   // post declaration of tree

template<class  T> class BinaryNode {
 friend class BinaryTree<T>;
private:  T data;
		  BinaryNode<T> *left;
		  BinaryNode<T> *right;

public: BinaryNode<T> ():left(NULL),right(NULL){}
		BinaryNode<T>(T x,BinaryNode<T> *p=NULL,BinaryNode<T>*q=NULL):data(x),left(p),right(q){}
		~BinaryNode<T>(){}
		T getdata() const{return data ;}
		BinaryNode<T> *  getleft() const{return left;}
        BinaryNode<T> *  getright() const {return right;}
		void setdata(T  t){data=t;}
		void setleft(BinaryNode<T> *p){left=p; }
        void setright(BinaryNode<T> *p){right=p; } 
		int Size(const BinaryNode<T> *T){} const;
        int Height(const BinaryNode<T> *T) const;
		void printpreorder(){};
		void printinorder(){};
		void printpostorder(){};
		BinaryNode<T>* duplicate()const{};
		T Max(T a,T b);

		}
}

template<class T>
BinaryNode<T> *  BinaryNode<T>::duplicate()const{
            BinaryNode<T>* root=new BinaryNode<T>(data);
			if(left!=NULL)root->left=left->duplicata();
            if(right!=NULL)root->right=right->duplicata();
			return root;
}


template<class T>
T BinaryNode<T> ::Max(T a,T b){

	if(a>b)return a;
	return b;
}

template<class T>
int BinaryNode<T>:: Size(BinaryNode<T> *T){
      if(T==NULL)  return 0;

       return 1+Size(T->left)+Size(T->right);

}
template<class T>
int BinaryNode<T> ::Height(const BinaryNode<T> *T) const{
     if(T==NULL)return 0;
	 else  return 1+Max(Height(T->left),Height(T->right));

}

