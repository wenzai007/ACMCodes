
//------------此程序测试  主调函数   实参形参之间的单向值传递问题！！！

  #include<iostream>
using namespace std;

void main(){
  int c;
	void chang(int m, int n) ;
	cout<<"haha"<<endl;
     cout<<"ni mei a "<<endl;
	 /*
	 cin>>c;
	 getchar();
	 //*/
    int a=1;
	int b=2;
//
  chang(a,b);

/*	
	int tmp;
	tmp=b;
		 b=a;
	  a=tmp;
	//*/

	  cout<<"a:  "<<a<<endl;
	cout<<"b:  "<<b<<endl;
//	cout<<"c  "<<c<<endl;
    getchar();


}
  //*/
   void chang(int m,int n){
	int tmp;
	tmp=n;
	 n=m;
	  m=tmp;
}//*/