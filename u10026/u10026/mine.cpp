//���Լ�д�� Ȼ��Ա�һ�±��˺��ҵ�˼·��ʵһ���ģ��ҵ� ����ȫ��ȷ��
//��ʵ�������Լ���˼·  ������һ��̰�ĵ��㷨

#define for if(0); else for 
#define pf printf
#define sf  scanf
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>//��cmath ����û��math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;

char ins[40];
int c_num;
int e_num;
struct node{
	int id;
	int t;
	int c;
	bool operator <(const node B)const {
		if(t*B.c!=c*B.t){
			return c*B.t>t*B.c;
		}
		else {
			return id<B.id;
		}
	}
}buf[1008];
int main(){
	freopen("in.txt","r",stdin);   
	sf("%d",&c_num);
	gets(ins);
	while(c_num--){
		sf("%d",&e_num);
		int n_id=1;
		for(int i=0;i<e_num;i++){
			buf[i].id=n_id++;
			sf("%d%d",&buf[i].t,&buf[i].c);
		}
		sort(buf,buf+e_num);
		for(int i=0;i<e_num;i++){
			if(i!=0)
				pf(" ");
			pf("%d",buf[i].id);
		}
		pf("\n");
		if(c_num!=0)
			pf("\n");
		gets(ins);//���һ�������ǿյģ�ʲôҲ������
	}
	return 0;
}

