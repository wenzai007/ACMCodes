#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;
int L,N;
int buf[660];
bool used[660];
bool  cmp(int a,int b){
	return a>b;
}
int totaltmp=0;//存储的是当前的 和
// the most important function!
void DFS(int num){
	if(totaltmp+buf[num]==L){
		used[num]=true;
		totaltmp+=buf[num];
		return;
	}
	else if(totaltmp+buf[num]>L){
		return ;
	}
	else{
		for(int i=num;i<N;i++){
			used[i]=true;
			totaltmp+=buf[i];
			//for(int j=num+1;j<N;j++){//明明是j=i+1 你偏偏写成j=num+1
				     //逻辑不清晰  这么明显的错误都没发现啊！！
			for(int j=i+1;j<N;j++){
				DFS(j);
				if(totaltmp==L)return ;
			    if(totaltmp>L) continue;
			}
			//能运行到这里的代码的话说明没有等于的条件
			//遍历失败
			used[i]=false;
			totaltmp-=buf[i];
		}
	}
}


int main(){
	//freopen ("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while (scanf("%d%d",&L,&N)!=EOF){
		int total=0;
		for(int i=0;i<N;i++){
			used[i]=false;
		}
		for(int i=0;i<N;i++){
			scanf("%d",&buf[i]);
			total+=buf[i];
		}
		sort(buf,buf+N,cmp);
		if(total<L){
			printf("impossible\n");
			//break;//！！！这里错了 因为如果不存在的话就是
			      //不在检测下一组数据了  明显不对应该改成continue
			continue;
		}
		if(total==L){
			printf("%d\n",N);
			//break;
			continue;
		}
	
		
 		int px;
		totaltmp=0;//之前忘记初始化
		/*
		for(px=0;
			px<=N&&totaltmp<L;
			px++){//px的限制不能太多 
			totaltmp+=buf[px];
		}
		*/
		for(px=0;px<N;px++){
			if(totaltmp>=L)break;
			totaltmp+=buf[px];
			
		}
		if(totaltmp==L){
			printf("%d\n",px);
		}
		else {
			//printf("%d\n",px+1);//这个地方不管是px+1还是px都是wa
			printf("%d\n",px);
		}
	//	DFS(0);
		//int minUse;//这里没有初始化  所以下面的minuse++ 导致运行时错误
	//	int minUse=0;
	//	for(int i=0;i<N;i++){
	//		if(used[i]==true) minUse++;
	//	}
		//！！！此处出错 因为忘记加minuse为0的话 打印出impossible 所以不对
		// 应该加上这个语句 否则必然是wa
	/*	if(minUse==0){
			printf("impossible\n");
			continue;
		}
		printf("%d\n",minUse);
			*/
	}


	return 0;
}














//effect
