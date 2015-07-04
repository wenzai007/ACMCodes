
//非常之贱 的一道题  需要自己处理四舍五入的问题！！  fuck、！
//参见网上的代码  online  只用了不到60行！！
//另外 pat貌似不用那个   while scanf  ！=eof  这个因为他每个case只给一个
//例子的
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
int N,M;
struct N{
	int id;
	int c,m,e,a;
	bool operator <(const N &B) const{
		return id<B.id;
	}
}buf[2080];
int c_score[101];
int m_score[101];
int e_score[101];
int a_score[101];

int binary(int the_id){
	int low=0;int high=N-1; int mid;
	while (low<=high){
		mid=(low+high)/2;
		if(buf[mid].id==the_id) return mid;
		if(buf[mid].id<the_id) low=mid+1;
		else high=mid-1;
	}
	return -1;
}

//int  round(double x){//不能命名为round  与pat上面的 函数有重叠  真是严格啊
//  换个名称  这个地方其实可以不用这个函数的  只是将3个数字想加就好了
//  因为只是排名而不用输出的  可以参见online
int  my_round(double x){
	double aa=x>0?x+0.5:x-0.5;
	return (int)aa;
}

int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d%d",&N,&M)!=EOF){
		for(int i=0;i<=100;i++){
			c_score[i]=m_score[i]=e_score[i]=a_score[i]=0;
		}
		for(int i=0;i<N;i++){
			scanf("%d%d%d%d",&buf[i].id,&buf[i].c,&buf[i].m,&buf[i].e);

			c_score[buf[i].c]++;
			m_score[buf[i].m]++;
			e_score[buf[i].e]++;
			int avg= my_round((buf[i].c+buf[i].m+buf[i].e)/3);
			a_score[avg]++;
			buf[i].a=avg;
		}
		//因为各个数组是hash的方式进行存储的  所以根本就不用排序的
		//直接统计前面一共有多少个就可以了！

		//在这里我如果对结构体按照学号进行排序的话 那么需要nlogn
		//然后查询的时候二分查找需要  n*logn
		//如果不排序的话  那么每一次查找都是n次 一共是n*n次 
		//所以这样看的话   我觉得还是排一下序比较好一些你说呢
		sort(buf,buf+N);
		int checkid;
		for(int i=0;i<M;i++){
			scanf("%d",&checkid);
			int flag=binary(checkid);
			if(flag==-1) {
				printf("N/A\n");
				continue;
			}
			
			int min=0xfffffff; char choose='A';
			int a_perf=buf[flag].a;
			int c_perf=buf[flag].c;
			int m_perf=buf[flag].m;
			int e_perf=buf[flag].e;
			//此处以下其实可以用数组的 不用4个if 太麻烦了 
			int rank=0;
			//尼玛 顺序写反了！！！
			//for(int i=0;i<a_perf;i++){
			/*
			for(int i=100;i>a_perf;i--){
				rank+=a_score[i]++;//尼玛这是什么啊
				//为什么要++  有病吧你！！
			}
			*/
			for(int i=100;i>a_perf;i--){
				rank+=a_score[i];//
			}
			rank+=1;
			if(rank<min){
				min=rank;
				choose='A';
			}
			rank=0;
			for(int i=100;i>c_perf;i--){
				rank+=c_score[i];
			}
			rank+=1;
			if(rank<min){
				min=rank;
				choose='C';
			}
			rank=0;
			for(int i=100;i>m_perf;i--){
				rank+=m_score[i];
			}
			rank+=1;
			if(rank<min){
				min=rank;
				choose='M';
			}
			rank=0;//忘记加上
			for(int i=100;i>e_perf;i--){
				rank+=e_score[i];
			}
			rank+=1;
			if(rank<min){
				min=rank;
				choose='E';
			}
			//printf("%d %c\n",rank,choose);//你真心是大傻b   看看这个为什么要输出rank啊！！
		  printf("%d %c\n",min,choose);

		}
	}
	return 0;
}

