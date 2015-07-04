//用的暴力方法！！但是只得了18分 7分没得
// 因为考虑不全  见_2
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
using namespace std;

int nums[10008];

int main(){
	freopen("in.txt","r",stdin);
	int n;
	int sum,max;
	int first,last;
	while (scanf("%d",&n)!=EOF){
		max=-1;
		sum=0;
		bool flag=false;
		for(int i=0;i<n;i++){
			scanf("%d",&nums[i]);
			if(nums[i]>=0) flag=true;
		}
		if(flag==false){
			printf("0 %d %d\n",nums[0],nums[n-1]);
			continue;
		}
		first=nums[0],last=nums[1];
		for(int i=0;i<n-1;i++){
			sum=nums[i];
			for(int j=i+1;j<=n-1;j++){
				sum+=nums[j];
				if(sum>max){
					max=sum;
					first=i;
					last=j;
				}
			}
		}
		//printf("%d %d %d\n",max,first,last);输出的是数字不是下标！！
		printf("%d %d %d\n",max,nums[first],nums[last]);
	}
	return 0;
}

