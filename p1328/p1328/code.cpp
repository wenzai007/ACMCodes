//@1 wa 看不出来什么原因。。。 
//@2	Main.cpp
//F:\temp\12976163.31208\Main.cpp(71) : fatal error C1071: unexpected end of ///file found in comment 妈蛋  把最下面的注释删掉 就好了  AC ！ 不能再最后有注释shit  以后注释都写在最上面

#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>
 
#include<queue>
#include<stack>
#include<vector>
#include<map>
using namespace std;


struct node{
	double a,b;
	bool operator <(const node bb)const{
		return a<bb.a;
	}
	
}buf[1008];

int n,d,x,y;
int cnt=0;
bool flag;
int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%d%d",&n,&d)!=EOF){
		if(!n&&!d)
			break;
		cnt++;
		flag=false;

		for(int i=0;i<n;i++){
			scanf("%d%d",&x,&y);
			if(d<abs(y)){
				flag=true;
				//break;!!!@1这里的原因所以wa了 擦  因为不可以break的
//否则的话就会出现问题的，break之后后面的数据不读了 然后直接读下一个n 和d//的值但是却把 x y的坐标读成了n和d的值了。。！！  所以不能break
			}
			double yy=abs(y);
			buf[i].a=(double)x-sqrt(d*d-yy*yy);
			buf[i].b=(double)x+sqrt(d*d-yy*yy);

		}
		if(flag==true){
			printf("Case %d: -1\n",cnt);
			continue;//@!但是这里是可以continue的！
		}
		int ans=1;//至少当前的这个要建立 然后从第二个开始检测 
		sort(buf,buf+n);
		double right=buf[0].b;
		for(int i=1;i<n;i++){
			if(buf[i].a>right){//right 是当前情况下所能建立的雷达的最靠右边的点
				ans++;
				right=buf[i].b;
				continue;
			}
			if(buf[i].b<right){
				right=buf[i].b;//因为只能这样才能够使得当前的雷达覆盖到所有的点
			}
		}
		printf("Case %d: %d\n",cnt,ans);
	}

	return 0;
}
//@1 wa 看不出来什么原因。。。 
//@2	Main.cpp
//F:\temp\12976163.31208\Main.cpp(71) : fatal error C1071: unexpected end of ///file found in comment 妈蛋  把最下面的注释删掉 就好了  AC ！ 不能再最后有注释shit