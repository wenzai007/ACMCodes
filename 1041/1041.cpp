/*
��ʼ��ʱ������  map  ���Ǻ����������� ��Ϊ
map�Ĵ����Ƕ�̬�仯��  �Զ����� key�����������
���Ի�һ�ַ��� ��  hash��˼��  �����ͺ���

  ������󣡣���������  ȡ��������ֵ�ʱ������hash����
  ��Ϊgcc++ ������ �������ظ������л�������
  ���Ի�һ������
*/

#define for if(0); else for 
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>>//��cmath ����û��math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;
//map<int,string> mp;
int buf[100008];
int mhash[10008];
int main(){
	freopen("in.txt","r",stdin);
	int N;
	while (scanf("%d",&N)!=EOF){
		for(int i=0;i<10008;i++){
			mhash[i]=0;
		}
		for(int i=0;i<N;i++){
			scanf("%d",&buf[i]);
			mhash[buf[i]]++;
		}
		int ans=0;bool  find=false;
		for(int i=0;i<N;i++){
			if(mhash[buf[i]]==1){
				find=true;
				ans=buf[i];
				printf("%d\n",ans);
				break;//֮ǰû�м���仰 �˷��˺ܶ��ʱ��
			}
		}
		if(find==false)
			printf("None\n");
	}
	/*
	freopen("in.txt","r",stdin);   
	mp.insert(make_pair(10,"hehe"));
	mp.insert(make_pair(5,"uuu"));
	mp.insert(make_pair(6,"yeyi"));
	*/
	return 0;
}

