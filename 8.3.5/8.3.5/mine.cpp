#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>//有cmath 但是没有math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;

int book[508];//books

bool cansplit(int n,int m,int x){
	int sum=0;
	int t=0;//  the numbers of  split line 
	for(int i=0;i<n;i++){
		sum+=book[i];
		if(sum>x){
			sum=book[i];
			t++;
			if(t>m-1){
				return false;
			}
		}
	}
	return true;
}//  feel i miss sth...



int main(){
	freopen("in.txt","r",stdin);   
	int cnum,n,m;
	
	while(scanf("%d",&cnum)!=EOF){
		for(int i=0;i<cnum;i++){
			scanf("%d%d",&n,&m);
			for(int j=0;j<n;j++){
				scanf("%d",&book[j]);
			}
			int maxsum=0;
			int maxofthem=0;// 和最大值最小也不可能是小于其中最大的一个数
			for(int j=0;j<n;j++){
				maxsum+=book[j];
				if(book[j]>maxofthem){
					maxofthem=book[j];
				}
			}
			int l=maxofthem;
			int r=maxsum;
			int mid;
			while(l<r){
				mid=(l+r)/2;
				if(cansplit(n,m,mid)){// 说明mid太大了
					r=mid;//当r可以的时候 不一定非要r=mid-1 因为l与r接近
					//的时候（但不相等的时候，l+1==r的时候） 其二者中点可能为l 不可能为r，所以等于mid相当于减了1
					//所以无所谓减不减1,但是要考虑到l=199不可以 r=200可以的时候  mid=199  不可以  然后
//就是说二者中要有一个能够相互靠近的趋势才行的！
//挺有学文的这一段代码  ，因为r=mid 所以这个循环中 跳出的时候l的值一定是
//满足cansplit（l）的！！  因为cansplit（mid）的时候 r变成mid，可能等于l
//而推出，如果cansplit（mid）为假的话，那么l=mid+1 这时候如果跳出的话
//那么说明l+1==r   在整个循环中r的值一直是cansplit的！！！   
				}
				else{
					//l=mid; 不可以这样写 因为l r的mid可能等于l
					//而当不可以分割的时候 l必须要增大，所以l=l+1
					//否则可能l =mid 始终不可以 那么就会陷入死循环中！
					//
					l=mid+1;
				}
			}
			//下面输出结果
			if(cansplit(n,m,mid)){
				printf("%d\n",mid);
			}
			else{
				printf("%d\n",l);
			}
			//擦  其实不用写这么多的直接输出l的值就对了
			//因为退出循环只有两种情况，一种是r=mid 也就是r=l 退出
			//另外一种是l=mid+1 是的l=r退出 两种都是写成l就对了
		}
	}
	
	return 0;
}

