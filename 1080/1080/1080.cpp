#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>

#include<stack>
#include<queue>
#include<vector>
#include<map>
using namespace std;
int n,m,k;
int quota[103];//每一个学校的名额是多少！！输入的时候确定的

int preferschool[40002][6];
//int admit[]=

struct node{
	int id;
	int ge;
	int gi;
	int tol;
	//bool cmp(const node &a,const node &b)const {!!你在干什么！！
	//bool operator <(const node &a,const node &b)const {这又是什么
	bool operator <(const node &b)const {
		if(tol!=b.tol)
			return tol>b.tol;
		else return ge>b.ge;
	}
}stu[40002];
vector<node> schoolenrolled[103];
//应该再加一个cmp函数用来比较vector中的不同node的id为了升序排列！
bool cmp( node a,  node b) {
	return a.id<b.id;
}

int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d%d%d",&n,&m,&k)!=EOF){
		for(int i=0;i<m;i++){
			schoolenrolled[i].clear();
		}
		for(int i=0;i<m;i++){
			scanf("%d",&quota[i]);// the quota  of each school 
		}
		for(int i=0;i<n;i++){
			scanf("%d%d",&stu[i].ge,&stu[i].gi);
			stu[i].id=i;
			stu[i].tol=stu[i].ge+stu[i].gi;
			for(int j=0;j<k;j++){
				scanf("%d",&preferschool[i][j]);// the prefered school of each one
			}
		}
		sort(stu,stu+n);//忘记了有点  是不是这样写的
		for(int i=0;i<n;i++){
			node np=stu[i];//now the current node after sort 
			for(int j=0;j<k;j++){
				int nowschool=preferschool[np.id][j];//当前的这个学校的id
				if(quota[nowschool]>0){//当前学校有名额的话

					schoolenrolled[nowschool].push_back(np);
					quota[nowschool]--;
					break;
				}
				else{
					//end() 应该是vector的最后一个元素吧？
					node pre=schoolenrolled[nowschool].back();//可以看下6月4号的总结 about vector
					if(pre.tol==np.tol&&pre.ge==np.ge){
						schoolenrolled[nowschool].push_back(np);
						quota[nowschool]--;
						break;
					}
				}

			}
		}//for
		for(int i=0;i<m;i++){
			if(schoolenrolled[i].size()==0){
				printf("\n");//反斜杠。。。换行
				continue;
			}
			sort(schoolenrolled[i].begin(),schoolenrolled[i].end(),cmp);//这个吧？
			for(int j=0;j<schoolenrolled[i].size();j++){
				if(j==0)
					printf("%d",schoolenrolled[i][j]);
				else
					printf(" %d",schoolenrolled[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
