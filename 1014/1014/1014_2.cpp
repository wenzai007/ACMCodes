/*  
这道题本身不难。但一直没有过，问题找了很久没没发现。看了别人的代码之后，才发现原来题目中讲的“Note that since the bank is closed everyday after 17:00, for those customers who cannot be served before 17:00, you must output "Sorry" instead.” 其实是说开始服务时间不能超过17:00而不是服务结束时间。

*/
//但是这里只能得到22分  还差8分
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

queue<int> q[22];
int process[1080];
int origi_process[1080];//保存原来的处理时间
int finish[1080];
int query[1080];
int N,M,K,Q;

string  format(int x,int i){
	string ret;
	char str[12];
	int hour,minute;
	if(x>540){
		if(x-origi_process[i]>540){
		ret="Sorry";
		return ret;
		}
	}
	hour=8+x/60;
	minute=x%60;
	sprintf(str,"%02d:%02d",hour,minute);
	ret=str;
	return ret;
}


int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d%d%d%d",&N,&M,&K,&Q)!=EOF){//N是窗口数目
		for(int i=0;i<N;i++){
			while (!q[i].empty()) q[i].pop();

		}
		for(int i=1;i<=K;i++){
			scanf("%d",&process[i]);
			origi_process[i]=process[i];
		}
		for(int i=1;i<=Q;i++){
			scanf("%d",&query[i]);
		}
		int idx=1;
		for(int i=1;i<=M;i++){
			for(int j=0;j<N;j++){
				if(idx>K) break;
				q[j].push(idx++);
			}
		}//初试时刻 全部入队
		//idx是下一个应该进入队中的人
		int t=0;//时间、
		while (true){//一直循环 知道队空
			bool empty=true;
			for(int i=0;i<N;i++){
				if(!q[i].empty())
					empty=false;
			}
			if(empty==true) break;//空了就停止
			t++;//时间不短流逝  以分钟作为单位
			for(int i=0;i<N;i++){
				if(!q[i].empty()){
					int newp=q[i].front();
					process[newp]--;
					if(process[newp]==0){
						q[i].pop();
						finish[newp]=t;
						if(idx<=K){//每个队列只有有出队的时候才会有入队的
							q[i].push(idx);
							idx++;
						}
					}
				}
			}
		}//while  true
		for(int i=1;i<=Q;i++){//用sprintf
			string s=format(finish[query[i]],i);
			printf("%s\n",s.c_str());
		}
	}



	return 0;
}

