#define for if(0); else for
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<math.h>
#include<algorithm>

#include<stack>
#include<queue>
#include<vector>
#include<map>
using namespace std;
#define isleap(x)  (x%4==0&&x%100!=0)||x%400==0?1:0

int dofm[13][2]={
	0,0,//那么到这个点的时候怎么办啊？
	31,31,
	28,29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31
};//要加分好的 吧

struct date{
	int year,month,day;
	void creat(){
		day++;
		if(day>dofm[month][isleap(year)]){
			day=1;
			month++;
			if(month>12){
				month=1;
				year++;
			}
		}
	}
};

int buf[5001][13][32];
int ny,nm,nd;
int main(){
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	date n;
	n.year=0;  n.month=1;  n.day=1;
	int cnt=0;
	while (n.year!=5001){
		buf[0][1][1]=0;
		n.creat();
		cnt++;
		buf[n.year][n.month][n.day]=cnt;
	}
	while(scanf("%4d%2d%2d",&ny,&nm,&nd)!=EOF){
		int d1=buf[ny][nm][nd];
		scanf("%4d%2d%2d",&ny,&nm,&nd);
		int d2=buf[ny][nm][nd];
		int dif=abs(d1-d2)+1;
		printf("%d\n",dif);
	}

	return 0;

}

