/*  ��һ����Runtime error
 *  ��while (l<r)  �ĳ�l<=r �ͺ���  shit
 *  ����⻨��������Сʱ  ����һ�����ϰ�������  
 *  ������������InitSequenceLength  �ܺã��ܾ���
Sk�ĳ��ȣ�  
k�ķ�Χ  
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
#include<math.h>//��cmath ����û��math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
#define MAXLEN 146000  //��31270 ���ĳ��ȴ����146000
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
		sum+=d_num; //���sum��ʵ����s[k] ��һ����̬�Ķ��� �����ڱ仯
		//�������¼�����ܵĳ���
		//����112123123412345  ��sum�ֱ�Ϊ1  12  123   1234  12345 �ĳ���
		//��seqLen[1~5]Ϊ1 3 6 10 15 �ȵ�����

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
		//����string ���͵ļ��� char�������͵�;
/*����ֱ�Ӽ� ���Ҽӵ�\0Ϊֹ
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

