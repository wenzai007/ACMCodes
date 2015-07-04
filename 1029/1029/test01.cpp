


//第一次  答案错误！0分！  原因   没有吧freopen去掉！！
// 现在是21分  差4分  两个case 运行超时！！
//原因好像是因为  不用排序 两个东西都是  递增的1！
//重新来
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

long long  buf1[1000008];
int main(){
		int idx=0;
		for(int i=0;i<6;i++){
			scanf("%lld",&buf1[idx++]);
		}
	return 0;
}
