#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>

#include<algorithm>
#include<math.h>

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>
using namespace std;

const int size=2080;
map<string,int> m;
int idx;

vector<int> v[size];
queue <int> q;
int n;
int a,b;
char c[100],d[100];
int indegree[size];
int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d",&n)!=EOF&&n){//n�� ��ô������2n���ڵ�
		idx=1;
		for(int i=1;i<=2*n;i++){
			v[i].clear();
			indegree[i]=0;
		}
		m.clear();// right???? yes����
		while (!q.empty()) q.pop();
		for(int i=1;i<=n;i++){
			scanf("%s%s",c,d);
			if(m.find(c)==m.end()){
				a=idx;
				m[c]=a;
				idx++;
			}
			else a=m[c];
			if(m.find(d)==m.end()){
				b=idx;
				m[d]=b;
				idx++;
			}
			else b=m[d];
			indegree[b]++;
			//ɵ�� vector[a].push_back(b);
			v[a].push_back(b);
		}
		for(int i=1;i<idx;i++){
			if(indegree[i]==0) q.push(i);
		}
		//�˴�����������������Ϊ0 ���������йھ�
	//���Դ˴���Ҫ�жϣ�������
		if(q.size()!=1) {
			printf("No\n");
			continue;
		}
		int cnt=0;
		while (!q.empty()){
			int newp=q.front();
			q.pop();
			cnt++;
			for(int i=0;i<v[newp].size();i++){
				indegree[v[newp][i]]--;
				if(indegree[v[newp][i]]==0)
					q.push(v[newp][i]);
			}
		}
		if(cnt==idx-1) printf("Yes\n");
		//else printf("No\n");;
	}
	return 0;
}

