/*
  �������ϵ�  ˵
  �㷨�ܼ򵥾��������㷨, �����ֳɵ�sort֮��Ŀ������, ע�����㡱
(1) ������node��һ��������ͬһ�������� (�����Ϊʲô������Ҫhead node 
��address)
(2) head node address ����Ϊ-1,С��segment fault.
(3) ��������ǿգ�Ӧ�������0 -1��.

��������key�������Զ��׼��ġ�Ҫע��input����ĵ㣬��һ��
����list�ϡ���Ŀ�С� total number of nodes in memory������
total number of nodes in list.�����������Ĵ��񽫡�where 
N is the total number of nodes in the list �������е�N ��Ϊ
M ������Ŀ��˼��Ϊ������
�����Ŀ��˼����ˣ��Ǿ�ʹ��father list arrayȥ��¼list��
�Ϳ����ˡ�����Ҫ���������ˣ��ᳬʱ��

  ��ô�ҿ��Ͱ� ���е���list�ϵ��������ͺ��˰�����_2
24/25
���Ե�	���	��ʱ(ms)	�ڴ�(kB)	�÷�/����
	0	����ȷ	2	372	15/15
	1	����ȷ	2	256	3/3
	2	����ȷ	2	376	3/3
	3	����ȷ	93	4580	3/3
	4	�ڴ泬��			0/1

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
struct node{
	int addr;
	int v;
	int next;
	bool operator<(const node &b) const{//���ʼ��ʱ������
		//һ��const  pat����  vc û�б���
		return v<b.v;
	}
}buf[100080];
vector <node> vec;
int va,ad,ne;
int n;
int first;
int main(){
	freopen("in.txt","r",stdin);   
	while (scanf("%d%d",&n,&first)!=EOF){
		node tmp;
		vec.clear();
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&ad,&tmp.v,&tmp.next);
			tmp.addr=ad;
			buf[ad]=tmp;
		}

		tmp=buf[first];
		while (tmp.next!=-1){
			vec.push_back(tmp);
			tmp=buf[tmp.next];
		}
		vec.push_back(tmp);
		sort(vec.begin(),vec.end());
		
		
		for(int i=0;i<vec.size()-1;i++){
			vec[i].next=vec[i+1].addr;
		}
		vec[vec.size()-1].next=-1;
		int ss=vec.size();
		printf("%d %05d\n",vec.size(),vec[0].addr);
		for(int i=0;i<vec.size()-1;i++){
			printf("%05d %d %05d\n",vec[i].addr,vec[i].v,vec[i].next);
		}
		printf("%05d %d %d\n",vec[ss-1].addr,vec[ss-1].v,vec[ss-1].next);
	}
	return 0;
}

