//开始的时候TLE了  原来需要一个vis 数组判断重复 进行进一步的剪枝
//然后 就ac了  只需要加两行   其实就是解答树中的不可能继续进行下去的
//给排除掉

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

int c_num;
int p_num;
int buf[108];
int ans;
vector<char> v;
int res;
bool flag;
bool can(int x){
	if(x>=-32000&&x<=32000)
		return true;
	else 
		return false;
}

int  vis[108][64008];//判断是否重复了啊！   
void dfs(int len){//剪枝的还不够给力，剪枝还可以进一步的
	if(!can(res))
		return;
	if(len==p_num-1){
		if(res==ans)
			flag=true;
		return;
	}
	if(!vis[len][res+32000]){
		vis[len][res+32000]=1;
		res+=buf[len+1];//  next number;
		v.push_back('+');
		dfs(len+1);
		if(flag) return;//
		res-=buf[len+1];//
		v.pop_back();//最后的跳出 以上为第一部分  有还原的操作
		res-=buf[len+1];//  next number;
		v.push_back('-');
		dfs(len+1);
		if(flag) return;
		res+=buf[len+1];//
		v.pop_back();//最后的跳出 以上为第一部分  有还原的操作
		res*=buf[len+1];//  next number;
		v.push_back('*');
		dfs(len+1);
		if(flag) return;
		res/=buf[len+1];//
		v.pop_back();//最后的跳出 以上为第一部分  有还原的操作
		if(res%buf[len+1]!=0) return;//不能整除 那么返回
		res/=buf[len+1];//  next number;
		v.push_back('/');
		dfs(len+1);
		if(flag) return;
		res*=buf[len+1];//
		v.pop_back();//最后的跳出 以上为第一部分  有还原的操作
	}
}

int main(){
	freopen("in.txt","r",stdin);   
	sf("%d",&c_num);
	while (c_num--){
		v.clear();
		memset(vis,0,sizeof(vis));
		sf("%d",&p_num);
		for(int i=0;i<p_num;i++){
			sf("%d",&buf[i]);
		}
		sf("%d",&ans);
		res=buf[0];//第一个数字
		flag=false;
		dfs(0);
		if(flag){
			for(int i=0;i<p_num-1;i++){
				pf("%d",buf[i]);
				pf("%c",v[i]);
			}
			pf("%d=",buf[p_num-1]);
			pf("%d\n",ans);
		}
		else{
			pf("NO EXPRESSION\n");
		}
	}
	return 0;
}



