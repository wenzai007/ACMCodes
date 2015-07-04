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

struct rich{
	string name;
	int age;
	int w;
	bool operator <(const rich &b)const{
		if(w!=b.w){
			return w>b.w;
		}
		else if(age!=b.age){
			return age<b.age;
		}
		else {
			return name<b.name;
		}
	}
}buf[100080];

int n,k;
char instr[12];
int m,a1,a2;
int minage,maxage;
int main(){
	freopen("in.txt","r",stdin);   
	while (scanf("%d%d",&n,&k)!=EOF){
		minage=0xffffff;maxage=-1;
		for(int i=0;i<n;i++){
			scanf("%s%d%d",instr,&buf[i].age,&buf[i].w);
			buf[i].name=instr;
			if(buf[i].age<minage) minage=buf[i].age;
			if(buf[i].age>maxage) maxage=buf[i].age;
		}
		sort(buf,buf+n);
		for(int i=1;i<=k;i++){
			printf("Case #%d:\n",i);
			scanf("%d%d%d",&m,&a1,&a2);
			int que=m;
			if(a1>maxage||a2<minage) {
				printf("None\n");
				continue;
			}
			for(int i=0;i<n;i++){
				if(!que) break;
				if(buf[i].age>=a1&&buf[i].age<=a2){
					que--;
					printf("%s %d %d\n",buf[i].name.c_str(),buf[i].age,buf[i].w);
				}
			}
			//	if(que==m){
			//	printf("None\n");
			//	}
		}
	}	
	return 0;
}

