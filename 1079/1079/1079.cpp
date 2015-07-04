/*
�ɹ�A��   ԭ����¼������ʱ������ô�ļ���ȥ
��ǰ̫ɵ����  �Ǹ������Ȳ�������ʲô���Ȱѵ�ǰ��
�ڵ�Ķ�����ȫ�����ڶ�����ȥ  Ȼ���� ���ڿ���ǰ�Ľڵ��ǲ��Ǳ�������һ����endoflevel�� ����ǵĻ���ô��endoflevel�������������Ϊqueue.back()�������Ҳ�ܵ�  ��Ȼ���Է��ʶ����е��������Ԫ�ء�
���˸�ȥ ���õİ� ���� ���Ժܼ򵥵ĺ��¸����Ѱ�

*/
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

const int num=100008;
vector <int> v[num];
int n;
double price,rate;
int  amo[num];
bool isleaf[num];
queue<int> q;
//����visit���� û�б�Ҫ��  ��Ϊ��α�����������ͼ��������

double bfs(){
	double total=0;
	int level=0;
	q.push(0);
	int np,endoflev;
	endoflev=0;
	while (!q.empty()){
		np=q.front();
		q.pop();
		for(int i=0;i<v[np].size();i++){
			q.push(v[np][i]);
		}
		if(isleaf[np]==true){
			total+=amo[np]*price*pow(double(1+rate/100),level);
		}
		if(np==endoflev){//�˴�����һ���ж�����
			//����˵��������ǿյ�ʱ����ô���endoflev=q.back();�Ļ����ڴ���� ����Ҫ�жϵģ�
			if(q.empty())break;//�������ͺ���
			level++;
			endoflev=q.back();
		}
	}
	return total;
}
int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%d",&n)!=EOF){
		scanf("%lf%lf",&price,&rate);
		memset(isleaf,false,sizeof(bool)*num);
		memset(amo,0,sizeof(int)*num);
		while(!q.empty()) q.pop();
		for(int i=0;i<n;i++){
			v[i].clear();
		}
		int tn,tson,tamo;
		for(int i=0;i<n;i++){
			scanf("%d",&tn);
            if(tn==0){
				isleaf[i]=true;
				scanf("%d",&tamo);
				amo[i]=tamo;
				continue;
			}
			for(int j=0;j<tn;j++){
				scanf("%d",&tson);
				v[i].push_back(tson);
			}
		}
		double res=bfs();
		printf("%.1lf\n",res);
	}
	return 0;
}
