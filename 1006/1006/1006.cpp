//��ʵ���Ǽ򵥵��ַ�������������  
//Ӧ�ò��� %2d һ��һ����������   ֱ����strcmp����Ӧ�þ��ǿ��Ե���
//С��0��ʱ��ǰ��Ⱥ���С  ��Ϊʱ��ĸ�ʽ����һ���ַ���
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
struct p{
	char id[20];
	char  start[10];
	char  end[10];
}pp[1000];//��Ŀ����ȷ   û�������ֵ
bool cmp1(p p1,p p2){
	return strcmp(p1.start,p2.start)<0;
}
bool cmp2(p p1,p p2){
	return strcmp(p1.end,p2.end)<0;
}
int main(){
	freopen("in.txt","r",stdin);
	int n;
	while (scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%s%s%s",pp[i].id,pp[i].start,pp[i].end);
		}
		sort(pp,pp+n,cmp1);
		char earliest[22];
		//strcopy(earliest,pp[0].id);��������д���ˣ���
		strcpy(earliest,pp[0].id);
		sort(pp,pp+n,cmp2);
		char latest[28];
		strcpy(latest,pp[n-1].id);
		//latest=pp[n-1].id;
		printf("%s %s\n",earliest,latest);

	}
	return 0;
}

