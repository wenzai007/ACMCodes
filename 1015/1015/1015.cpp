//1  得到18分   差两分 
//原因 ！！！  因为没读好题意给你18分算你捡到大便宜了！
//人家说原来的数字和发转的数字都是  素数的话 才是对的！！！
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
int N,D;
const int size =1000008;
bool nums[size];//多一点

void sift(){
	for(int i=2;i<size;i++){
		nums[i]=true;//
	}
	nums[0]=nums[1]=false;
	for(int i=2;i<size;i++){
		if(nums[i]==false)
			continue;
		//加上判断
		if(i>2000)continue;
		for(int j=i*i;j<size;j+=i){//又一次忘记了j的溢出
			nums[j]=false;
		}
	}
} //筛素数  不用存储！
int  str[20];
int main(){
	freopen("in.txt","r",stdin);
	sift();
	srand(time(0));
	int mm=rand();
	while (scanf("%d%d",&N,&D)!=EOF){
		if(N<0) break;
		int idx=0;
		int ori_N=N;//开始读错题意了 这里补上！
		int sum=0;int weigh=1;
		do{
			str[idx++]=N%D;
			N/=D;
		}
		while(N);
		for(int i=idx-1;i>=0;i--){
			sum+=str[i]*weigh;
			weigh*=D;
		}
		//if(nums[sum]==true)//这里错了
		if(nums[sum]==true&&nums[ori_N]==true)
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

