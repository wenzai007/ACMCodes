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
int quota[103];//ÿһ��ѧУ�������Ƕ��٣��������ʱ��ȷ����

int preferschool[40002][6];
//int admit[]=

struct node{
	int id;
	int ge;
	int gi;
	int tol;
	//bool cmp(const node &a,const node &b)const {!!���ڸ�ʲô����
	//bool operator <(const node &a,const node &b)const {������ʲô
	bool operator <(const node &b)const {
		if(tol!=b.tol)
			return tol>b.tol;
		else return ge>b.ge;
	}
}stu[40002];
vector<node> schoolenrolled[103];
//Ӧ���ټ�һ��cmp���������Ƚ�vector�еĲ�ͬnode��idΪ���������У�
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
		sort(stu,stu+n);//�������е�  �ǲ�������д��
		for(int i=0;i<n;i++){
			node np=stu[i];//now the current node after sort 
			for(int j=0;j<k;j++){
				int nowschool=preferschool[np.id][j];//��ǰ�����ѧУ��id
				if(quota[nowschool]>0){//��ǰѧУ������Ļ�

					schoolenrolled[nowschool].push_back(np);
					quota[nowschool]--;
					break;
				}
				else{
					//end() Ӧ����vector�����һ��Ԫ�ذɣ�
					node pre=schoolenrolled[nowschool].back();//���Կ���6��4�ŵ��ܽ� about vector
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
				printf("\n");//��б�ܡ���������
				continue;
			}
			sort(schoolenrolled[i].begin(),schoolenrolled[i].end(),cmp);//����ɣ�
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
