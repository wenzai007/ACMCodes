#define for if(0); else for 
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

struct node{
	int x,y;
}buf[1500];
int mymax;
int nsum;
void justdoit(int tol){
	mymax=2;
	//nsum=2;  不是在这里初始化 大哥 应该再每一条直线的开始处 初始化！！
	for(int i=0;i<tol;i++){
		for(int j=i+1;j<tol;j++){//因为任意两个点确定一条直线，所以要遍历所有的点 这样才能找到
			//所有的直线，然后把所有的直线上的点都统计出来反正求出最大的值就可以了是不是
			nsum=2;
			for(int k=j+1;k<tol;k++){
				if((buf[j].y-buf[i].y)*(buf[k].x-buf[i].x)==(buf[j].x-buf[i].x)*(buf[k].y-buf[i].y)){//  将除法变成乘法的技巧  这个是很常见的
					nsum++;
					if(nsum>mymax)
						mymax=nsum;
				}
			}
			
		}
	
	}
	printf("%d\n",mymax);
}

int main(){
	freopen("in.txt","r",stdin);   
	int cnum;
    char ins[100];
	scanf("%d",&cnum);
	gets(ins);
	gets(ins);//第一个空行
	int cnt;
	while (cnum--){
		cnt=0;
		while(gets(ins)){
			// 出错了 ""不是空if(ins==NULL&&cnt!=0){// 就是一个case的最后一行的空格
			if(ins[0]=='\0'&&cnt!=0){
				break;
			}
			sscanf(ins,"%d%d",&buf[cnt].x,&buf[cnt].y);
			cnt++;

		}
		/*if(cnt==1){
			printf("1\n");
			return 0;
		}
		题目已经说了大于1  所以不用
		*/  
	    justdoit(cnt);
		if(cnum){
			printf("\n");
		}


	}
	return 0;
}

