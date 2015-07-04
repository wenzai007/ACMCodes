


//第一次  答案错误！0分！  原因   没有吧freopen去掉！！
// 刚才是21分  差4分  两个case 运行超时！！
//原因好像是因为  不用排序 两个东西都是  递增的1！
//重新来 需要排序的   不做了  这个菜6分  越改越不行
#define for if(0); else for 
//#define win32 1
#ifdef  win32
#define LL _int64
#else 
#define  LL  long long 
#endif

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

LL buf1[1000008];
LL buf2[1000008];
int   len1,len2;
int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d",&len1)!=EOF){
		int idx=0;
		for(int i=0;i<len1;i++){
			scanf("%lld",&buf1[idx++]);
		}
		/*
		for(int i=0;i<6;i++){
			scanf("%lld",&buf1[idx++]);
		}
		*/
		idx=0;
		scanf("%d",&len2);
		for(int i=0;i<len2;i++){
			scanf("%lld",&buf2[idx++]);
		}
		sort(buf1,buf1+len1);
		sort(buf2,buf2+len2);
		int i=0,j=0,p=0;LL nowp=-1;

		int mid=(len1+len2)%2==1?(len1+len2)/2:

(len1+len2)/2-1;
		mid-=1;
		while (i<len1-1&&j<len2-1){
			if(buf1[i]<=buf2[j]) {
				i++; p++; nowp=buf1[i];
			}
			else{
				j++; p++;nowp=buf2[j];
			}
			if(p==mid){
				break;
			}
		}
		if(p==mid){
			printf("%lld\n",nowp);
			continue;
		}
		while (i<len1-1){
			i++;
			p++;
			nowp=buf1[i];
			if(p==mid){
				printf("%lld\n",nowp);
			}
		}
		while (j<len1-1){
			j++;
			p++;
			nowp=buf2[j];
			if(p==mid){
				printf("%lld\n",nowp);
			}
		}
		/*
		//sort(buf,buf+len1+len2);
		//printf("%I64d\n",buf[(len1+len2)/2]);判断奇数偶

数
		if((len1+len2)%2==1){
			printf("%I64d\n",buf[(len1+len2)/2]);//

判断奇数偶数
		}
		else 
			printf("%I64d\n",buf[(len1+len2)/2-1]);

  */
	}
	return 0;
}
