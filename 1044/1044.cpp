/*  21/25  �����ⷨ  

���Ե�	���	��ʱ(ms)	�ڴ�(kB)	�÷�/����
	0	����ȷ	2	380	   10/10
	1	����ȷ	1	380	    7/7
	2	���г�ʱ			    0/2
	3	����ȷ	42	2796 	2/2
	4	����ȷ	2	376	    2/2
	5	���г�ʱ			    0/2
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

const int size=100008;
int N,M;
int buf[size];
vector <pair<int,int> > v;
vector <pair<int,int> > vm;
int main(){
	freopen("in.txt","r",stdin);   
	while (scanf("%d%d",&N,&M)!=EOF){
		for(int i=1;i<=N;i++){
			scanf("%d",&buf[i]);
		}
		v.clear();
		vm.clear();
		int sum=0;
		int min=0xfffffff;
		for(int i=1;i<=N;i++){
			sum=0;
			for(int j=i;j<=N;j++){
				sum+=buf[j];//�ӵ�һ����ʼ��
				if(sum>=M){
					if(sum==M){
						v.push_back(make_pair(i,j));
					}
					else{
						if(sum<min)
							min=sum;
					}
					break;//�Ѿ������� ����һ��Ҫbreak��
				}
			}
		}
		if(v.size()!=0){
			for(int i=0;i<v.size();i++){
				printf("%d-%d\n",v[i].first,v[i].second);
			}
		}
		else{
			for(int i=1;i<=N;i++){
				sum=0;
				for(int j=i;j<=N;j++){
					sum+=buf[j];
					if(sum==min){
						vm.push_back(make_pair(i,j));
						break;//�˴����� break����һ����ʱ
					}
				}
			}
			for(int i=0;i<vm.size();i++){
				printf("%d-%d\n",vm[i].first,vm[i].second);
			}
		}
	}
	return 0;
}

