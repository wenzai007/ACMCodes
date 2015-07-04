//所以二分求幂法 完全是有些题目要考察的内容
//如过不这样做的话就会溢出或者是超时的！！
//这是一种必须要掌握的技巧的！！
//终于ac 了！！  关键是矩阵的乘法！！！
//  数组作为函数参数的用法   是值传递  只有指针才能传地址
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
const int  mod_value=9973;
int T;
int n,k;
int cross[12];
int map[20][20];
int map_sum[20][20];
void  muti(int map1[][20],int map2[][20]){
	int maptmp[20][20];
		int tmp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			tmp=0;
			for(int k=0;k<n;k++){
				tmp+=map1[i][k]*map2[k][j];
			}
			tmp%=mod_value;
			maptmp[i][j]=tmp;
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			map[i][j]=maptmp[i][j];
}
void  muti_sumfun(int map1[][20],int map2[][20]){
	int maptmp[20][20];
		int tmp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			tmp=0;
			for(int k=0;k<n;k++){
				tmp+=map1[i][k]*map2[k][j];
			}
			tmp%=mod_value;
			maptmp[i][j]=tmp;
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			map_sum[i][j]=maptmp[i][j];
}


int main(){
	freopen("in.txt","r",stdin);
	int sum;
	int ans;
	while (scanf("%d",&T)!=EOF&&T){
		while (T--!=0){
			sum=0;
			scanf("%d%d",&n,&k);
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					scanf("%d",&map[i][j]);
				}
			}
			//int  map_sum[20][20];
			//重复定义 运行错误
 			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++){
					if(i==j)map_sum[i][j]=1;
					else map_sum[i][j]=0;
				}
			while(k){
				if(k%2==1){
					muti_sumfun(map_sum,map);
				}
				k/=2;
				muti(map,map);
			}
			for(int i=0;i<n;i++){
				sum+=map_sum[i][i];
			}
			sum%=mod_value;
			printf("%d\n",sum);
		}
	}
	return 0;
}


