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
//���ڽӱ����洢  �����Ϊֻ�洢�ڵ��žͿ����� ����û�б�Ҫ�ýṹ��
//���� ������������Ļ� һ�㶼��Ҫ��һ���������������е� �ڵ����ȵ�
//���֮����Ҫ����һ�� �ǲ����е�һЩindgree�������е�ֵ����˸�������
//Ҫע��ڵ��Ǵ�0��ʼ��ŵ�
int indegree[180];
vector <int> v[180];
queue <int> qq;
int n,m; int a,b;
int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d",&n)!=EOF&&n){
		scanf("%d",&m);
		for(int i=0;i<n;i++){
			indegree[i]=0;
			v[i].clear();
		}
		while (!qq.empty()) qq.pop();
		for(int i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			indegree[b]++;
			//v[a].push_back[b];:push_back��: ��������ȱ�ٲ����б���ʹ�á�&std::
			v[a].push_back(b);
		}
		for(int i=0;i<n;i++){
			if(indegree[i]==0)
				qq.push(i);
		}
		int cnt=0;
		//while (!qq.empty){��!��: �󶨳�Ա�������ʽ�ϵķǷ�����
		while (!qq.empty()){
			int newp=qq.front();
			qq.pop();
			cnt++;
			for(int i=0;i<v[newp].size();i++){//�˴�һ���һ�����
				//Ȼ��һ��Ч����
				indegree[v[newp][i]]--;//��Ȼ�ǿ��ܳ�Ϊ������������Ǳ�
				//����� ��Ϊ������� �����ÿһ��������0����� ��ô����
				//����ѭ���ˣ�����ȻҲ�����ں���� �ȵȡ�Ӧ�ò�����ָ�
				//��  ��Ϊ��Ȼ��0�����  ��ô����ı߲�������ָ�����˰�
				//���� �������پ���0�ˣ�
				if(indegree[v[newp][i]]==0) 
					qq.push(v[newp][i]);
			}
		}
		if(cnt==n) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

