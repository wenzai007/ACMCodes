//其实  不用什么而其他的比较方法   存储字符串就可以了
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
struct bigInteger{
	char nums[1008];
	bool operator <(const bigInteger &b)const {
		int a_len=strlen(nums);int b_len=strlen(b.nums);
		int idx;
		if (a_len!=b_len)
			return  a_len<b_len;
		else {
			for(idx=0;idx<a_len;idx++){
				if(nums[idx]!=b.nums[idx])  break;
			}
			if(idx!=a_len)
				return nums[idx]<b.nums[idx];
			//大哥说的对 这里错了  因为如果相等的话应该返回false
			//不能说相等的话什么也不干   这样的话  直接return 那么
			//可能会返回true呢 也说不准？
			else return false;
		}
	}
}buf[200];
int N;
int main(){
	freopen ("in.txt","r",stdin);
	while (scanf("%d",&N)!=EOF){
		for(int i=0;i<N;i++){
			scanf("%s", buf[i].nums);
		}
		sort(buf,buf+N);
		for(int i=0;i<N;i++){
			printf("%s\n",buf[i].nums);
		}
	}
	return 0;
}

