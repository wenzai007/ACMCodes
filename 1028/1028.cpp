#define for if(0); else for 
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>>//有cmath 但是没有math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;


struct stu {
	int id;
	string name;
	int grade;
}buf[100008];
int N,C;
bool  cmp1(const  stu &a,const stu &b){
	return a.id<b.id;
}
bool  cmp2(const  stu &a,const stu &b){
	if(a.name!=b.name){
		return a.name<b.name;
	}
	else {
		return a.id<b.id;
	}
}
bool  cmp3(const  stu &a,const stu &b){
	if(a.grade!=b.grade){
		return a.grade<b.grade;
	}
	else {
		return a.id<b.id;
	}
}

char namestr[10];
int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%d",&N)!=EOF){
		scanf("%d",&C);
		for(int i=0;i<N;i++){
			scanf("%d%s%d",&buf[i].id,namestr,&buf[i].grade);
			buf[i].name=namestr;
		}
		switch (C){
		case 1: sort(buf,buf+N,cmp1);
				break;
		case 2: sort(buf,buf+N,cmp2);
				break;
		case 3: sort(buf,buf+N,cmp3);
				break;
		}
		for(int i=0;i<N;i++){
			stu t=buf[i];
			printf("%06d %s %d\n",t.id,t.name.c_str(),t.grade);
		}

	}
	return 0;
}

