//这道题的话 我觉得用三个指针的就好
//总结 ：思路是对的但是仍然很马虎
//忘记吧 重定向的东西给改过来
//数组85 一开始竟然能写成25  真是nb的一塌糊涂
//另外n-- 和--n  如果只有这一句的话还好
//但是只要和其他的符号结合 就要考虑好是n--还是--n
//要想进行n次循环的话就要用while (n--!=0)  
#include<stdio.h>
#include<string.h>
#include <algorithm>
using namespace std;
int buf[85];
int n;
int k;
int i;
int tmp;
int main(){
	//freopen("in.txt","r",stdin);  ！！！又一次忘记了注释 
	//freopen("out.txt","w",stdout);
	while (scanf("%d",&n)!=EOF&&n){
		//while(--n!=0){//n--出错了  n-- 和 --n完全是不同的啊！！
						// 前面的是先减再判断 后面的是先判断再减 
						//尼玛 明显应该先判断再减啊！！
		while(n--!=0){	
			scanf("%d",&k);
			for(i=0;i<k;i++){
				scanf("%d",&tmp);
				buf[i]=tmp;
			}
			int pre=0,work=1,rear=2;//题面一直已经给出了k也就是数组的
									//个数大于4  所以不用考虑特殊情况
			int cnt=0;//用于计数  控制空格的输出
			if(buf[0]!=buf[1]){
				cnt++;
				printf("0");
			}
			while(rear!=k){
				if((buf[work]>buf[pre]&&buf[work]>buf[rear])||buf[work]<buf[pre]&&buf[work]<buf[rear]){
					if(cnt==0)printf("%d",work);
					else printf(" %d",work);
					cnt++;
				}
				pre++;work++;rear++;
               
			}
			//跳出时候rear为k
			if(buf[work]!=buf[pre])printf(" %d",work);
			printf("\n");
		}
	}
	return 0;
}
























//for the middle effect
