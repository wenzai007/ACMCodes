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

struct  stu{
	char name[18];
	char gen[2];
	char id[18];
	int grade;
	bool operator <(const stu b)const{//operator�ǹؼ���
		//��������ɫ��  ������ǵĻ�����ƴд����
		return grade>b.grade;
	}
};
vector<stu> v1,v2;
int N;

int main(){
	freopen("in.txt","r",stdin);   
	while (scanf("%d",&N)!=EOF){
		v1.clear();v2.clear();
		for(int i=0;i<N;i++){
			stu tmp;
			scanf("%s%s%s%d",tmp.name,tmp.gen,tmp.id,&tmp.grade);
			/* ��ʼ��ʱ���������
			����д���� if(tmp.gen==��M")  Ȼ����
			v1��������ִ���κε�push_backԭ����
			�����tmp.gen��һ��ָ���� �������ַ���
			����  ����ָ��ĵ�ַ��ô������� ������Զ����
			��ȵ�  ���Բ������Ǹ�  Ҫ�ĳ�strcmp�����ſ���
			ע��strcmp������д��*/
			if(strcmp(tmp.gen,"M")==0)
				v1.push_back(tmp);
			else 
				v2.push_back(tmp);
		}
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());	
		int lm=v1.size()-1,lf=v2.size()-1;
		if(v2.size()){
			printf("%s %s\n",v2[0].name,v2[0].id);
		}
		else printf("Absent\n");
		if(v1.size()){
			printf("%s %s\n",v1[lm].name,v1[lm].id);
		}
		else printf("Absent\n");
		if(v1.size()==0||v2.size()==0){
			printf("NA\n");
		}
		else {
			printf("%d\n",v2[0].grade-v1[lm].grade);
		}

	}
	return 0;
}

