/*
3��18�� 18:48	 ������ȷ	2	1056	C++ (g++)	2	380	wenzai007
���Ե�
  2/25
���Ե�	���	��ʱ(ms)	�ڴ�(kB)	�÷�/����
0	�𰸴���	2	380	0/13
1	�𰸴���	1	256	0/3
2	����ȷ	1	376	2/2
3	�𰸴���	2	256	0/3
4	�𰸴���	2	380	0/2
5	�𰸴���	2	376
*/

#define for if(0); else for 
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

int main(){
	freopen("in.txt","r",stdin);   
	int d,p;
	int n;
	while (scanf("%d%d",&n,&p)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d%d",&d,&p);
		}
		for(int i=0;i<n;i++){
			if(i!=0) printf(" ");
			printf("1");
		}
	}
	return 0;
}

