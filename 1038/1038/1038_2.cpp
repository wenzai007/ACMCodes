/*
�ο���  ����    28  / 30 
���Ե�	���	��ʱ(ms)	�ڴ�(kB)	�÷�/����
0	����ȷ	2	1024	16/16
1	����ȷ	2	1148	2/2
2	�𰸴���	2	1144	0/2
3	����ȷ	3	1144	3/3
4	����ȷ	2	1024	2/2
5	����ȷ	2	1144	2/2
6	����ȷ	47	1656	3/3
���    1038_2    ��ȥ  so easy

�ٿ�����һ�ּ��޵���� ����ȫ����0��ʱ��
��Ŀ��˵����  non negetive 
����
yes
3��16�� 14:46	 ����ȷ	30	1038	C++ (g++)	51	1536	wenzai007
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

const int size=100008;
int n;
char instr[10];
string buf[size];

bool cmp(const string &aa, const string &bb){
	string t1=aa+bb;
	string t2=bb+aa;
	return t1<t2;
}
int main(){
	freopen("in.txt","r",stdin);   
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%s",instr);
			buf[i]=instr;
		}
		sort(buf,buf+n,cmp);
		bool allzero=true;
		for(int i=0;i<n;i++){
			int ddd;
			sscanf(buf[i].c_str(),"%d",&ddd);
			if(ddd!=0)
				allzero =false;
		}
		if(allzero==true){
			printf("0\n");
			continue;
		}
		for(int i=0;i<n;i++){
			if(i==0){
				int dd;
				sscanf(buf[0].c_str(),"%d",&dd);
				printf("%d",dd);
			}
			else{
				printf("%s",buf[i].c_str());
			}
		}
		printf("\n");
	}
	return 0;
}

