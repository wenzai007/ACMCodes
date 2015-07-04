
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
 char buf[201];
  
//vector<char> buf;
/*
bool cmp(char *a, char *b){
	int res =strcmp(a,b);
	return res 0;
}
  //*/

int main(){//看来只能用vector这个动态的char数组来做题了！no no
	

	while (scanf("%s",buf)!=EOF){//sort 可不可以对字符数组进行排序？可以的
		 #ifndef ONLINE_JUDGE
    #else
    freopen("E:\\in.txt","r",stdin);
    #endif
		int bufsize=strlen(buf);
		  sort(buf,buf+bufsize);
		  printf("%s\n",buf);
		//  for(int i=0;i<201;i++){
		//	buf[i]=NULL;此处不用清空  详见 本子上面110  说法
		//  }
	}


}







//this is for the middle effect
//*/