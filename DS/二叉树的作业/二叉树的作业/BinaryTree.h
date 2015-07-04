template<class T>  class BinaryTree{
private: BinaryNode<T> *root;
		 BinaryTree(const BinaryTree<T>&);
		 void DelTree(BinaryNode<T> & *T );

public: BinaryTree(){root=NULL;}
		BinaryTree (const T &t){root=new BinaryNode<T>(t);  }
		~BinaryTree(){DelTree(root);}
		int IsEmpty(){ return root==NULL;}
		BinaryNode<T> * Getroot(){return root;}
		void makeEmpty(){DelTree(root));root=NULL; }
		const BinaryTree<T> & operator =( const BinaryTree<T> & T);
        
};

  template <class T>
  const BinaryTree<T> & operator =( const BinaryTree<T> &T){
	  if(*this!=T){
		  DelTree(root);
		  if(root!=NULL)root=T.root->duplicate();
	  }
    return *this;

  }


template<class T>
void BinaryTree<T>:: DelTree(BinaryNode<T> & *T ){
	if (T!=NULL){
           DelTree(T->left);
		  DelTree(T->right);
           delete  T;
	}
	
    
}
