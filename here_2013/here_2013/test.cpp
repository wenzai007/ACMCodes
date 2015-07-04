#include<iostream>
#include<Exception>
#include<stdio.h>//这句话其实加不加都可以因为C++默认支持C

using namespace std;
//void show();

int i,j,k;
void main(){
	void dfs();
    
	i=3;
	dfs();
    cout<<i<<endl;
	 cout<<j<<endl;
	  cout<<k<<endl;
	  getchar();

}

	/*
	int a=12;
	int *p=&a;
	int *q;
	cout<<a<<endl;
	cout<<endl;
	Exception(!(q=&a),"it is a null!");
	getchar();

	*/
	/*
	void addNum(int,int) ;
		void show(int);
	int k=1;while(k++<10);
	//cout<<k<<endl;
	int i,j;
	i=2;j=5;
	addNum(i,j);
	printf("%1d",j);
	for(int i=0;i<2;i++){
		printf("\n");
	}
	for(int i=0;i<5;i++){
		cout<<i<<endl;
	}
	getchar(); 
	
}

//*/


   void   dfs(){
	   if(i==3){
		     j=10;
			return;
	   }
	     k=10;  //k will not be proceeded!!
}







