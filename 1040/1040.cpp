/*��һ��  21/25
���Ե�	���	��ʱ(ms)	�ڴ�(kB)	�÷�/����
0	����ȷ	1	376	13/13
1	����ȷ	2	380	2/2
2	�𰸴���	2	376	0/2
3	�𰸴���	2	256	0/2
4	����ȷ	2	376	2/2
5	����ȷ	2	256	2/2
6	����ȷ	2	256	2/2

  �Ķ���һ��  Ȼ��  AC�� 3��16�� 20:20	
  ����ȷ	25	1040	C++ (g++)	3	380
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

char  s[1008];
int main(){
	freopen("in.txt","r",stdin); 
	while (gets(s)){
	//while (scanf("%s",s)!=EOF){���д��������
		int len=strlen(s);
		int max=-1; int p,r,nlen;
		for(int i=0;i<len;i++){//�����м�һ�������
			nlen=1; p=i-1; r=i+1;
			while (p>=0&&r<=len-1){
				if(s[p]==s[r]){
					nlen+=2;
					p-=1; r+=1;
				}
				else break;
			}
			if(nlen>max) max=nlen;
		}
		for(int i=0;i<len;i++){//�м����������
			nlen=1;p=i;r=i+1;
			if(r>len-1) continue;
			if(s[p]==s[r]) nlen=2;
			else continue;
			while(true){
				p--; r++;//���ƶ�  ��nlen+2
				if(p<0||r>len-1)break;
				if(s[p]==s[r]){
					nlen+=2;
				}
				else break;
			}		
			/*
			while(p>=0&&r<=len-1){
				if(s[p]==s[r]){
					nlen+=2;
					p--;
					r++;
				}
				else break;
			}
			�����д����  �����2
			*/
			if(nlen>max) max=nlen;
		}
		printf("%d\n",max);

	}
	return 0;
}

