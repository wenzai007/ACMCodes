/*
���������в���ȥ��   ��ѭ������
���ϵĴ���ü�     ֱ��a+b<b+a �ͺ��ˣ���shit 
�� 1038_2  

��ѭ�� ��ȴ���еģ���  ���ָ��   ����һ�� ix++��
Ȼ��   28/30 ���֣���
���Ե�	���	��ʱ(ms)	�ڴ�(kB)	�÷�/����
0	����ȷ	2	1024	16/16
1	����ȷ	2	1144	2/2
2	����ȷ	3	1024	2/2
3	����ȷ	2	1148	3/3
4	����ȷ	2	1024	2/2
5	�𰸴���	2	1024	0/2
6	����ȷ	40	1648	3/3

��������Ե���� ��֪��Ϊʲô  ���ˣ�
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
int n;
char instr[10];
string buf[size];

bool cmp(const string &aa, const string &bb){/*
											 ����  �˴�Ϊ�˲����ж�a��b˭���� ����ߵ��õ�ʱ��
											 �����ж�  �˴������жϣ���Ĭ��b������
	*/
	string a=aa; string b=bb;
	char first=a[0];//��һ���ַ�
	int la=a.size();int lb=b.length();
	int ix=0;
	while (ix<la&&ix<lb){//��������ѭ��
	/*
	if(strcmp(a[ix],b[ix])!=0 )
	return strcmp(a[ix],b[ix])<0;
	strcmp �Ĳ���ֻ�� ����������const char *
	��������char  ���� ������벻��ͨ���ģ���
		*/
		if(a[ix]!=b[ix]){
			return a[ix]<b[ix];
		}
		//��������һ��  ix++��������ѭ�� ����!!
		ix++;//�������������Ķ��ˣ���
	}
	if(la==lb){ return false;} //��������ȵ� ����false
	if(la>lb){//���������ַ���
		string tmp=a;
		a=b;
		b=tmp;
	}
	
	//b��a��
	while(ix<b.size()&&b[ix]==first){
		ix++;
	}
	if(ix==b.size()) return false;//�������
	else {
		if(b[ix]<first) {
			if(la<lb)
				return false;
			else 
				return true;
		}
		else{ //����b[ix]>first ��ʱ��
			if(la<lb)
				return true;
			else 
				return false;
		}
	}
}
int main(){
	freopen("in.txt","r",stdin);   
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%s",instr);
			buf[i]=instr;
		}
		sort(buf,buf+n,cmp);
		bool allzero=true;
		for(int i=0;i<n;i++){
			int ddd;
			sscanf(buf[i].c_str(),"%d",&ddd);
			if(ddd!=0)  allzero=false;
		}
		if(allzero==true){
			printf("0\n");
			continue;
		}
		else {
			int first;
			sscanf(buf[0].c_str(),"%d",&first);
			printf("%d",first);
			for(int i=1;i<n;i++){
				printf("%s",buf[i].c_str());
			}
			printf("\n");
		}

	}
	return 0;
}

