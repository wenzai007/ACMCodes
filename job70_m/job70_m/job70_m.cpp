#include<stdio.h>
#include<string.h>
#include<string>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>// add graghs
#include<map>
using namespace std;
const int msize=2080;
map <string,int> name;
map<int,string> name_reverse;
//map <int,int> head_value;
map <string,int > out_name;

int tree[msize];

int size[msize];

int totaltime[msize];
int etime[msize];
int findroot(int x){
	if (tree[x]==-1)return x;
	else {
		int tmp=findroot(tree[x]);
		tree[x]=tmp;
		return tmp;
	}
}



int N,K;
char a[50],b[50];
int time_my;

int roots[msize];

int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%d%d",&N,&K)!=EOF){
		for(int i=1;i<msize;i++){
			tree[i]=-1;
			etime[i]=totaltime[i]=0;
			size[i]=1;
		}
		for(int i=0;i<msize;i++){
			roots[i]=-20;
		}
		name_reverse.clear();
		name.clear();
		out_name.clear();
		//int idx=0;初试的值不能是0 因为tree从1开始的
		int idx=1;//下一个被映射的数字
		string sa,sb;
		for(int i=0;i<N;i++){
			scanf("%s%s%d",a,b,&time_my);
			sa=a;sb=b;
			int ida,idb,roota,rootb;
			if(name.find(sa)==name.end()){
				ida=idx;
				name[sa]=idx++;
			}
			else ida=name[sa];
			if(name.find(sb)==name.end()){
				idb=idx;
				name[sb]=idx++;
			}
			else idb=name[sb];
			etime[ida]+=time_my;etime[idb]+=time_my;
			roota=findroot(ida);
			rootb=findroot(idb);
			if(roota==rootb){
				totaltime[roota]+=time_my;
			}
			else {
				tree[roota]=rootb;
				size[rootb]+=size[roota];
				totaltime[rootb]+=totaltime[roota]+time_my;
			}
			
		}
        //开始找
		//不对这是交换两个容器name_reverse.swap(name);

		map<string,int> ::iterator iter;
		for(iter=name.begin();iter!=name.end();iter++){
			name_reverse[iter->second]=iter->first;
		}
		int root_num=0;
		for(int j=1;j<idx;j++){
			if(tree[j]==-1&&size[j]>2&&totaltime[j]>K){
				//head_value[j]=totaltime_my[j];
				//out_name[name_reverse[j]]=j;
				roots[root_num++]=j;
			}
		}
		if(root_num==0){
			printf("0\n");
			continue;
		}
		printf("%d\n",root_num);
		for(int j=0;j<root_num;j++){
			int maxtime=-1;int pp=-1;
			for(int k=1;k<idx;k++){
				if(findroot(k)==roots[j]&&etime[k]>maxtime){
					maxtime=etime[k]; pp=k;
				}
			}
			out_name[name_reverse[pp]]=size[roots[j]];
		}
		for(iter=out_name.begin();iter!=out_name.end();iter++){
			//int ss=iter->second;
			//不可以的printf("%s",ff);
			printf("%s ",iter->first.c_str());
			printf("%d\n",iter->second);
			//printf("%s %d\n",ff,ss);
		}
	}
	return 0;
}

