#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;


int main(){//看来只能用vector这个动态的char数组来做题了！1
	char str[]="fadcegb";
	int len=strlen(str);
	sort(str,str+strlen(str));//不能用sizeof 这个求的是占用多少字节，应该用strlen
	for(int i=0;i<strlen(str);i++)
	{
		printf("%c ",str[i]);
	}
	system("pause");
	return 0;
}