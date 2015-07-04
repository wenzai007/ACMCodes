// 之后可以看看用sort直接排序的话会不会超时
#include<stdio.h>
int buf[1000008];//你妹的啊 看错数字了 不是100008而应该写成1000008 
//结果查了半个小时的时间  提交的时候就是runtime error
int n;// the  total num
int n_out;
int main(){
	int tmp;
	while (scanf("%d%d",&n,&n_out)!=EOF){
		if(n==0)break;
		for(int i=0;i<1000008;i++)
			buf[i]=0;
		while (n--!=0){
			scanf("%d",&tmp);
			buf[tmp+500000]=1;
		}
		int outcnt=n_out;
		for(int i=1000000;i>=0&&n_out!=0;i--){//这样的写法一定要会 停止条件
			//用逗号还是&&都可以么???
			if(buf[i]==1){
				if(n_out==outcnt){
					printf("%d",i-500000);
					n_out--;
				}
				else{
					printf(" %d",i-500000);
					n_out--;
				}
			}
		}
		printf("\n");
	}
}
