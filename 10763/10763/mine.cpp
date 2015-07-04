//冥思苦想了好久  终于给搞了出来了！！！！！
//就是排序的规则是这样的  首先按照a b 的和排序 如果相等 那么按照a-b的绝对值排序
//这样就能唯一的确定是否是  完全想等的了 因为  两个方程唯一确定两个数
//比如说：a+b=x a-b=y or  a+b=x a-b=-y  那么a b 唯一确定   或者a b值互换 （无所谓的）
//然后遍历一下即可 
//但是我的做法是错误的   tle了    超时  必须是O（n）的  才行
//正确的方法：用map  到最后看是不是每个pair 个数都是0 是的话那么对
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>//有cmath 但是没有math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;
struct stu{
	int a,b;
	bool operator <(const stu &B)const{
		if((a+b)!=(B.a+B.b)){
			return (a+b)<(B.a+B.b);
		}
		else
			return abs(a-b)<abs(B.a-B.b);
	}
}buf[500008];
int n;
int main(){
	freopen("in.txt","r",stdin);   
	while(scanf("%d",&n)&&n){
		if(n%2!=0){
			printf("NO\n");
			continue;
		}
		for(int i=0;i<n;i++){
			scanf("%d%d",&buf[i].a,&buf[i].b);
		}
		sort(buf,buf+n);
		bool flag=true;
		for(int i=0;i<n;i+=2){
			if((buf[i].a+buf[i].b)!=(buf[i+1].a+buf[i+1].b)||(buf[i].a-buf[i].b)!=(buf[i+1].b-buf[i+1].a)){
				flag=false;
				break;
			}
		}
		if(flag==true){
			printf("YES\n");
		}
		else
			printf("NO\n");
	}
	return 0;
}

