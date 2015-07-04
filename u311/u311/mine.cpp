//开始的时候完全没有任何思路！
//没有任何办法啊，那么只能看答案了啊！a
//贪心策略 先搞大的，大的搞完了 然后再开始搞小的啊！
//第一次是wa  然后发现three定义的不对开始的定义是这样的饿
//int three[4][2]={（0,0）,（5,7）,（3,6）,（1,5）};然后three[0][1]居然是7 
//改成 {0,0,5,7,3,6,1,5}就对了 three[0][1] 变为了0
//然后 把小括号改成大括号也是对的了！！！
//所以记住哦 千万不能在多维数组里面出现小括号哦 我发现全都乱套了有木有！！

#define for if(0); else for 
#define pf printf
#define sf  scanf
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

int num[7];
int sum;
//int three[4][2]={(0,0),(5,7),(3,6),(1,5)}; 
int three[4][2]={0,0,5,7,3,6,1,5};
//十分的有效地减少了if else的语句 第一个如果乘除那么

//的确应该是(0,0) 0个2 0个 1 ！！
//直接导致代码量的减少哦 很好的技巧

int main(){
	freopen("in.txt","r",stdin);   
	while(true){
		for(int i=1;i<=6;i++){
			sf("%d",&num[i]);
		}
		bool flag=false;
		for(int i=1;i<=6;i++){
			if(num[i])
				flag=true;
		}
		if(flag==false)
			break;
		sum=0;
		sum+=num[6]+num[5]+num[4]+(num[3]+3)/4;//开始的总的个数
		//下面处理2*2
		int leftfor_2=num[4]*5+three[(num[3]%4)][0];//3，4，5可以给2插的总数
		//进行分类讨论
		if(num[2]<=leftfor_2){
			num[2]-=leftfor_2;
			num[1]-=num[5]*11;
			num[1]-=three[(num[3]%4)][1];
			num[1]-=(0-num[2])*4;//如果num[2]变成了负数
			if(num[1]>0){
				sum+=(num[1]+35)/36;
			}
		}
		else{
			num[2]-=leftfor_2;
			num[1]-=num[5]*11;
			num[1]-=three[(num[3]%4)][1];
			sum+=(num[2]+8)/9;
			int rem=num[2]%9;
			if(rem!=0)
				num[1]-=(9-rem)*4;
			if(num[1]>0)
				sum+=(num[1]+35)/36;
		}
		pf("%d\n",sum);
	}
	return 0;
}

