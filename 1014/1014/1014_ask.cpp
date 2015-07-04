/*  
这道题本身不难。但一直没有过，问题找了很久没没发现。看了别人的代码之后，才发现原来题目中讲的“Note that since the bank is closed everyday after 17:00, for those customers who cannot be served before 17:00, you must output "Sorry" instead.” 其实是说开始服务时间不能超过17:00而不是服务结束时间。

*/
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

queue<int> q[22];//每一个窗口一个队列  
int process[1080];//每一个人的处理时间
int origi_process[1080];//保存原来的处理时间，因为上面这个process后面会改变的
int finish[1080];//每一个人的完成时间
int query[1080];//查询的数组
int N,M,K,Q;

string  format(int x,int i){//为了输出格式
	string ret;
	char str[12];
	int hour,minute;
	/*此处大哥说了 ：
1. >=写成了> 这种错误属于边界条件错误，利用题目中给出的测试数据可以确定是>=，写>的话不能输出sorry
2. origi_process[query[i]] 写成了 origi_process[i] 这也是常见的bug
3. 题目没看仔细。题目中“At 08:00 in the morning, customer1 is served at window1”就说明所谓的“served"是指开始业务的时间，” for those customers who cannot be served before 17:00, you must output "Sorry" instead.“ 说不能在17:00之前served，也就是说不能在17:00之前开始业务的输出sorry，也就是说正好17:00开始的也要输出sorry
*/
	if(x>=540){
		if(x-origi_process[query[i]]>=540){//注意是  开始时间大于540 17:00
		ret="Sorry";
		return ret;
		}
	}

//	if(x>540){
//		if(x-origi_process[i]>540){//注意是  开始时间大于540 17:00
//		ret="Sorry";
//		return ret;
//		}
//	}
	hour=8+x/60;
	minute=x%60;
	sprintf(str,"%02d:%02d",hour,minute);//格式化字符串
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
		int idx=1;//以上为初始化    idx为当前应该进入黄线以内的下一个人!
		for(int i=1;i<=M;i++){
			for(int j=0;j<N;j++){
				if(idx>K) break;
				q[j].push(idx++);//每一个窗口对应一个队列 每个队列挨个进人
			}
		}//初试时刻 全部入队 可能全进去了 也可能没有
		//idx是下一个应该进入队中的人
		int t=0;//时间、 用时间的变化来控制每一个状态 因为t不大
		while (true){//一直循环 直到每一个队都是空的停止
			bool empty=true;//是不是所有队列都空的
			for(int i=0;i<N;i++){
				if(!q[i].empty())
					empty=false;
			}
			if(empty==true) break;//空了就停止
			t++;//时间不断流逝  以分钟作为单位
			for(int i=0;i<N;i++){//每一分钟都看每一个队列的第一个人
				if(!q[i].empty()){
					int newp=q[i].front();//每一个队列的第一个人
					process[newp]--;//时间变少
					if(process[newp]==0){
						q[i].pop();//如果是的话出队
						finish[newp]=t;//这个出队的人结束的时候的时间是t
						if(idx<=K){//每个队列只有有出队的时候才会有入队的
							q[i].push(idx);//下一个人入队
							idx++;
						}
					}
				}
			}
		}//while  true
		for(int i=1;i<=Q;i++){//用sprintf 
			string s=format(finish[query[i]],i);//处理每一个查询的结果
			printf("%s\n",s.c_str());//输出！
		}
	}



	return 0;
}

