/*
��ʼ��ʱ���ǳ�ʱ  һ��û��  �����ѷ�Χ��С 
Ȼ�����
���Ե�	���	��ʱ(ms)	�ڴ�(kB)	�÷�/����
0	����ȷ	2	496	15/15
1	����ȷ	2	504	4/4
2	����ȷ	2	384	2/2
3	�𰸴���	2	384	0/2
4	����ȷ	2	508	2/2
����һ�� ����ֵ1    AC�� 
 �ĺ���֮����  3��18�� 22:41	 ����ȷ	25	1059	
 C++ (g++)	3

*/

#define for if(0); else for 
//#define win 1
#ifdef win
#define LL _int64
#else
#define LL long long
#endif
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>>//��cmath ����û��math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;
const int size =3000000;
const int size_2=100000;
int primes[size];
bool mark[10000000];

void findp(){
	int id=0;
	for(int i=2;i<size_2;i++){
		if(mark[i]==true) 
			continue;
		//if(i>400) break;ɵ�ƣ�
		primes[id++]=i;
		if(i>400) 
			continue;
		for(int j=i*i;j<size_2;j+=i){
			mark[j]=true;
		}
	}
}

LL nn,n;
map<int,int> mp;
int main(){
	freopen("in.txt","r",stdin);   
	//memset(mark,1,sizeof(mark))
	findp();
	while (scanf("%lld",&nn)!=EOF){
		n=nn;
		mp.clear();
		LL bd=(LL)sqrt((double)n)+1;
		if(n==0)
		{printf("0=0\n");
		continue;
		}
		else if(n==1){
			printf("1=1\n");
			continue;

		}
		for(int i=0;i<bd;i++){
			if(n%primes[i]==0){
				mp[primes[i]]=0;
			}
			while (n%primes[i]==0){
				mp[primes[i]]++;
				n/=primes[i];
			}
			if(n==1) break;
		}
		if(n!=1) mp[n]=1;
		printf("%lld=",nn);
		map<int,int> ::iterator it;
		for(it=mp.begin();it!=mp.end();it++){
			if(it!=mp.begin()) printf("*");
			if(it->second==1) printf("%d",it->first);
			else printf("%d^%d",it->first,it->second);
		}
		printf("\n");
	}		

	return 0;
}

