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
using namespace std;
//�е�������hash  �������±�����¼ �� �������ֵ������Ƕ���ʽ��ϵ��

double p[2080];
struct N{
	double co;
	int ex;
};
vector <N>v1,v2;
int main(){
	freopen("in.txt","r",stdin);
	int k;
	int ee;
	double cc;
	while (scanf("%d",&k)!=EOF){
		for(int i=0;i<2080;i++){
			p[i]=0;
		}
		v1.clear();v2.clear();
		while (k--!=0){
			scanf("%d%lf",&ee,&cc);
			N tmp;
			tmp.ex=ee;
			tmp.co=cc;
			v1.push_back(tmp);
		}
		scanf("%d",&k);
		while (k--!=0){
			scanf("%d%lf",&ee,&cc);
			N tmp;
			tmp.ex=ee;
			tmp.co=cc;
			v2.push_back(tmp);
		}
		int len1=v1.size(); int len2=v2.size();
		for(int i=0;i<len1;i++){
			for(int j=0;j<len2;j++){
				double  ccc=v1[i].co*v2[j].co;
				int eee=v1[i].ex+v2[j].ex;
				p[eee]+=ccc;
			}
		}
		int nonzero=0;
		for(int i=0;i<2080;i++){
			if(p[i]!=0)
				nonzero++;
		}
		if(nonzero==0){//����ȫ��һЩ  ����϶��ᱻ�۷�
			//pat�����Ŀ���ݽ��� �����дҲ��
			printf("0\n");
			continue;
		}
		printf("%d ",nonzero);
		int ans=0;
		for(int i=2080;i>=0;i--){
			if(p[i]!=0){
				ans++;
				if(ans!=1) printf(" ");
				printf("%d %.1lf",i,p[i]);
			}
		}
	}
	
	return 0;
}

