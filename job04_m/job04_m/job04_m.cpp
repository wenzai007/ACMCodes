#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int n;//  total cases
int c;//  the type 
struct student{
	int num;
	char name[9];
	int achieve;
	bool operator < (const student &b) const{
		int res=strcmp(name,b.name);
		if(c==2&&res!=0)return res<0;
		else if(c==3&&achieve!=b.achieve) return achieve<b.achieve;
		else return num<b.num;
	}
}stu[100001];
int cnt=0;// the number of the case
int main(){
	while(scanf("%d%d",&n,&c)!=EOF){
		if(n==0&&c==0)break;// whether or not care "c"????
		printf("Case %d:\n",++cnt);// can i write like this?yes i can!!
		for(int i=0;i<n;i++){
			scanf("%d%s%d",&stu[i].num,stu[i].name,&stu[i].achieve);
		}
		sort(stu,stu+n);
		for(int i=0;i<n;i++){
			printf("%06d %s %d\n",stu[i].num,stu[i].name,stu[i].achieve);
		}
	}
}
