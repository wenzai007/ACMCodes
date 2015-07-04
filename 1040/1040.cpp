/*第一次  21/25
测试点	结果	用时(ms)	内存(kB)	得分/满分
0	答案正确	1	376	13/13
1	答案正确	2	380	2/2
2	答案错误	2	376	0/2
3	答案错误	2	256	0/2
4	答案正确	2	376	2/2
5	答案正确	2	256	2/2
6	答案正确	2	256	2/2

  改动了一下  然后  AC了 3月16日 20:20	
  答案正确	25	1040	C++ (g++)	3	380
*/

#define for if(0); else for 
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>>//有cmath 但是没有math

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
	//while (scanf("%s",s)!=EOF){这个写法不对了
		int len=strlen(s);
		int max=-1; int p,r,nlen;
		for(int i=0;i<len;i++){//考虑中间一个的情况
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
		for(int i=0;i<len;i++){//中间两个的情况
			nlen=1;p=i;r=i+1;
			if(r>len-1) continue;
			if(s[p]==s[r]) nlen=2;
			else continue;
			while(true){
				p--; r++;//先移动  再nlen+2
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
			上面的写错了  多加了2
			*/
			if(nlen>max) max=nlen;
		}
		printf("%d\n",max);

	}
	return 0;
}

