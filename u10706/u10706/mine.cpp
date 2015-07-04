/*  第一次是Runtime error
 *  将while (l<r)  改成l<=r 就好了  shit
 *  这道题花了我三个小时  就是一个晚上啊！！！  
 *  下面的这个函数InitSequenceLength  很好，很精巧
Sk的长度：  
k的范围  
[1  , 9  ]: k  
[10 , 99 ]: 9 + (k-9)*2  
[100, 999]: 9 + 90*2 + (k-99)*3  
...  

*/  

#define for if(0); else for 
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>//有cmath 但是没有math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
#define MAXLEN 146000  //第31270 个的长度大概是146000
using namespace std;
long long num[100000];
string bstr;
int rr;
void  initnum(){
	int c=10;int d_num=1;int sum=0;num[0]=0;
	for(rr=1;num[rr-1]<=2147483647;rr++){
		if(rr==c){
			d_num++;
			c*=10;
		}
		sum+=d_num; //这个sum其实就是s[k] 是一个动态的东西 不断在变化
		//而数组记录的是总的长度
		//例如112123123412345  中sum分别为1  12  123   1234  12345 的长度
		//而seqLen[1~5]为1 3 6 10 15 等等依次

		num[rr]=num[rr-1]+sum;
	}
}

void initbigstring(){
		bstr.reserve(MAXLEN+20);
	   	char tmp[10];
		for(int i=1;bstr.length()<=MAXLEN;i++){
			sprintf(tmp,"%d",i);
			bstr+=tmp;
		}
}
		//可以string 类型的加上 char数组类型的;
/*可以直接加 而且加到\0为止
			string (1)	
	string& operator+= (const string& str);
	c-string (2)	
	string& operator+= (const char* s);
	character (3)	
	string& operator+= (char c);
	initializer list (4)	
	string& operator+= (initializer_list<char> il) 

	*/



/*this example reserves enough capacity in the string object to store an entire file, which is then read character by character. By reserving a capacity for the string of at least the size of the entire file, we try to avoid all the automatic reallocations that the object str could suffer each time that inserting a new character would make its length surpass its capacity.
 *
 */
long long  findit(int cv){
	int l=1,r=rr;
	int mid;
	while(l<=r){
		mid = (l+r)/2;
		if(num[mid]==cv)
			return num[mid-1];
		else if(num[mid]<cv){
			l=mid+1;
		}
		else 
			r=mid-1;
	}
	return num[r];
}
int main(){
	freopen("in.txt","r",stdin);  
	initnum();
	initbigstring();
	int c_num;
	scanf("%d",&c_num);
	long long  nv;
	while(c_num--){
		scanf("%lld",&nv);
		long long  res=findit(nv);
		res=nv-res;//pos of bstr
		char ans=bstr[res-1];
		int ans_i=ans-'0';
		printf("%d\n",ans_i);
	}
	return 0;
}

