//感觉用并查集 是不行了  不好弄  于是想到用dfs搜索了 连通分量的个数了
//写完之后在卡看 有没有用并查集做的人
//我的思路  用矩阵标示图  每一次 先去掉一个 点 算连通分量的个数
//然后输出  最后再把 这个点还原回去
//艹！！！！！！！
//写废了。。。。不能用矩阵吧  。。这个要是用矩阵的话就让他妈的太费时间
//还是得用vector  重新写！！！！！  见_2!!!
//
//

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
//注意 矩阵不能用map  因为pat上面是不允许的 可能会重名 用pic
int pic[1080][1080];//为了节省空间其实用bool就够了吧 每个元素1B
int remem[2080][2];//记录 删除了哪些点方便还原的时候用

//bool mark[1080][1080]; 擦 不熟悉的结果
bool mark[1080];
int N,M,K;

using namespace std;

int main(){//既然是每一个case  只有一组数据的话  那么我就不用while EOF什么的了
	scanf("%d%d%d",&N,&M,&K);
	for(int i=1;i<=N;i++){
		//mark[i]=false;
		for(int j=1;j<=N;j++){
			pic[i][j]=-1;
		}
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

int main(){
	
	return 0;
}

	}
	int a,b;
	while (M--!=0){
		scanf("%d%d",&a,&b);
		pic[a][b]=8;
		pic[b][a]=8;
	}
	while (K--!=0){
		int del;
		for(int i=0;i<2*N;i++){
			remem[i][0]=0;
			remem[i][1]=0;
		}
		int idx=0;
		scanf("%d",&del);
		for(int i=1;i<=N;i++){
			if(true==pic[i][del]){
				remem[idx][0]=i;
				remem[idx][1]=del;
				idx++;
				pic[i][del]=false;
			}
			if(true==pic[del][i]){
				remem[idx][0]=del;
				remem[idx][1]=i;
				idx++;
				pic[del][i]=false;
			}
		}
		int ans=0;
		for(int i=1;i<=N;i++){
			if(mark[i]==false){
				dfs(i);
				ans++;
			}
		}
		printf("%d\n",ans);

	}
	return 0;
}

