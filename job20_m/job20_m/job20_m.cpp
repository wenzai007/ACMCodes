#include<stdio.h>
#include<string.h>
#include<algorithm>
//#include<math>  //!!!!c++中是cmath  c中是math.h  根本没有math头文件
#include<math.h>
using namespace std;
int buf[105];
int binarySearch(int x,int low,int high ){
	int middle=(low+high)/2;
	while (low <=high){
		if(buf[middle]==x)return middle;
		else if(buf[middle]<x) low=middle+1;
		else high=middle-1;
		middle=(low+high)/2;
	}
	if(low>high)return -1;
}
int main(){
	//freopen("in.txt","r",stdio); //!!意思是file  re  open  文件重定向
	 //看看自己的拼写  还stdio......
	//  freopen("in.txt","r",stdin);
	int n;
	int m;
	int tmp;
	while (scanf("%d",&n)!=EOF&&n){
		for(int i=0;i<n;i++){
			scanf("%d",&tmp);
			buf[i]=tmp;
		}
		sort(buf,buf+n);
        scanf("%d",&m);
		while (m--!=0){
			//scanf("%d",tmp);//又一次   这个错误很多次了  运行时停止
			scanf("%d",&tmp);
			int find=binarySearch(tmp,0,n-1);
			if(find>=0)printf("YES\n");
			else printf("NO\n");
		}
	}
    return 0;//  ！！！ 又忘了
}
