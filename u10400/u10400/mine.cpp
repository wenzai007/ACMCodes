//��ʼ��ʱ��TLE��  ԭ����Ҫһ��vis �����ж��ظ� ���н�һ���ļ�֦
//Ȼ�� ��ac��  ֻ��Ҫ������   ��ʵ���ǽ�����еĲ����ܼ���������ȥ��
//���ų���

#define for if(0); else for 
#define pf printf
#define sf  scanf
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>//��cmath ����û��math

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

int  vis[108][64008];//�ж��Ƿ��ظ��˰���   
void dfs(int len){//��֦�Ļ�������������֦�����Խ�һ����
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
		v.pop_back();//�������� ����Ϊ��һ����  �л�ԭ�Ĳ���
		res-=buf[len+1];//  next number;
		v.push_back('-');
		dfs(len+1);
		if(flag) return;
		res+=buf[len+1];//
		v.pop_back();//�������� ����Ϊ��һ����  �л�ԭ�Ĳ���
		res*=buf[len+1];//  next number;
		v.push_back('*');
		dfs(len+1);
		if(flag) return;
		res/=buf[len+1];//
		v.pop_back();//�������� ����Ϊ��һ����  �л�ԭ�Ĳ���
		if(res%buf[len+1]!=0) return;//�������� ��ô����
		res/=buf[len+1];//  next number;
		v.push_back('/');
		dfs(len+1);
		if(flag) return;
		res*=buf[len+1];//
		v.pop_back();//�������� ����Ϊ��һ����  �л�ԭ�Ĳ���
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
		res=buf[0];//��һ������
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



