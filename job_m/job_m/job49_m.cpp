#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
//第一次我用的是int 提交是wa  但是明明人家说的这个东西啊
//输出：
//For each problem instance, output a single line containing the corresponding LCM. All results will lie in the range of a 32-bit integer.

unsigned int gcd(unsigned int a ,unsigned int b){
	if(b==0)return a;
	gcd(b,a%b);//每次检验b 是否为0  因为b在%后面  必须不能为0
}
unsigned int lcm(unsigned int a,unsigned int b){
	return a*b/gcd(a,b);
}
unsigned int case_num;
unsigned int m;
unsigned int buf[5000];
int main(){
	freopen ("in.txt","r",stdin);
	while (scanf("%d",&case_num)!=EOF&&case_num){
		for(int i=0;i<case_num;i++){
			scanf("%d",&m);
			for(int i=0;i<m;i++){
				scanf("%d",&buf[i]);
			}
			unsigned int ans=buf[0];
			for(int i=1;i<m;i++){
				ans=lcm(ans,buf[i]);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
