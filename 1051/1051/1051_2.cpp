/*
��ȫ������  ƭ��Ҳûƭ��  h(n)=C(2n,n)/(n+1) (n=0,1,2,...)
����ǿ������� ��Ȼ�������ûʲô��ϵ  ���Ƿ�ֹ�Ժ�����
�����  ���������˲�֪����ô����  
�� 1051 _2 
����˵  ��ʼ��ʱ��
��Ȼ��ջ������1 2 3 4 5 6 7 ������n����ջ˳�� ��ô
������ǰ�ĳ�ջ����  ����˵ 3  ��ô ��֮ǰ����Ҫ��1 2 ����ջ
�ſ���  ��ǰ�����������6�Ļ� ��ô��ǰ����δ��ջ��������
����Ҫ ��δ��ջ���������� ���µ���ֱ��6������ջ��˳��
���Կ��Խ���ģ��  ����ǰ  �������  ������  4 2 1 ������ջ��
˳��Ļ� ��ô ���� 1 2 3 4 ��ջ Ȼ�����2  ��ջ����ͬ
��ô��һֱtmp++  ��ջ�϶�����ѭ�� ��Ϊtmp��ǰ��5��6,7����
����һֱ��ջ��  Ȼ���˳���  ���ִ���  ���� ά��һ��tmp����
��ʼֵ��1��  ���ϵ���


����ģ�����, ���ݸ�����pop����, ��ԭpush �� pop�Ĺ���,
��Ϊһ��pop sequence ֻ�ܶ�Ӧһ��Ψһ��push pop�Ĳ�������
, ���Ե�����ܻ�ԭ��ô���pop sequence�ǿ��е�, ���򲻿�
��, ����: 3, 2, 1, 7, 5, 6, 4. �������, ��ô���ǿ���һ
��3, Ҫpop��3, ��ô�϶�Ҫ��push 1, push 2, push 3, 
pop 3, ��������2, ��ʱջ��ȷʵ��2��ô pop 2, ������1��
��, ��������һ����7, ��ô���Ǳ���Ҫ��push 4, push 5, 
push 6, push 7, Ȼ��pop 7���Եõ�һ��7, ��������Ҫ5,
���Ǵ�ʱջ��Ԫ����6, �������sequence���ǲ������ˡ� ��
�����㷨��������һ�������㷨��



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

stack<int> s;
int M,N,K;
int p;
int buf[1080];
int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d%d%d",&M,&N,&K)!=EOF){
		while(!s.empty()) s.pop();
		while (K--){
			bool flag=true;
			int tmp=1;
			for(int i=0;i<N;i++){
				scanf("%d",&buf[i]);
			}
			for(int i=0;i<N;i++){
				int p=buf[i];
				if(flag==false) break;
				while(s.size()<=M&&flag){
					if(s.empty()||s.top()!=p){
						s.push(tmp++);
					}
					else {//Ҳ���� s������s.top==p
						s.pop();
						break;//������һ��
					}
					if(s.size()>M){//����Ψһ��
				//�հ��ϲ��Ϸ�������
						flag=false;
						break;
					}
				}
			}
			
			if(flag==false)
				printf("NO\n");
			//else if(!s.empty())����Ҳ����
		//	printf("NO\n");
			else printf("YES\n");
			while(!s.empty()) s.pop();
		}
	}
	return 0;
}