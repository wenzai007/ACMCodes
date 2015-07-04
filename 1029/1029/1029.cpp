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

LL buf[2000008];
int   len1,len2;
int main(){
  freopen("in.txt","r",stdin);
  while (scanf("%d",&len1)!=EOF){
    int idx=0;
    for(int i=0;i<len1;i++){
      scanf("%lld",&buf[idx++]);
    }
    scanf("%d",&len2);
    for(int i=0;i<len2;i++){
      scanf("%lld",&buf[idx++]);
    }
    sort(buf,buf+len1+len2);
    if((len1+len2)%2==1){
			printf("%lld\n",buf[(len1+len2)/2]);//判断奇数偶数
		}
		else 
			printf("%lld\n",buf[(len1+len2)/2-1]);
  }
  return 0;
}