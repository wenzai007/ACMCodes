//第一次提交  wa
//贪心。。先加后乘为最大。先乘后加为最小。。有个注意点最多12个数。每个数最多20。所以要用long long不然WA。
//然后 改了之后一直不能ac  是wa  为什么呢   原来是因为那个 数组的问题 就是处理之后的数组我们不能用
//那个int的类型，而要改成  long long 的类型才可以的  
//还有我发现虽然最后一个是scanf("%c",&op)==EOF 但是仍然是可以写成'\n'的 也就是说我最后搞得很麻烦的
//那个特殊处理 沃勒个擦  ==EOF 其实可以不用特殊处理的直接写成=='\n' 虽然在vs里面不行，但是确实可以
//在oj上ac的所以最后一个字符也可以理解成为'\n'的字符
//也是对的  这一次是我自己先写的  然后对照网上的发现和我的思路是一样的，但是人家的那个却非常的短 因为没有必要写成两个函数  占了那么多行  我们可以写在一个函数里面的！！完全
#define for if(0); else for 
#define pf printf
#define sf  scanf
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
int n;
int id=0;
char op;

long long   ins[80];
long long  deal[80];//由int 改为long long 


long long  domax(){
	long long  sum=0;
	int nnum;
	int rnum;
	int dealid=0;
	char maxop;
	for(int i=0;i<id-1;i+=2){
		nnum=ins[i];
		if(ins[i+1]==-3){//退出的时候
			sum+=nnum;
			deal[dealid++]=sum;
			break;
		}
		else if(ins[i+1]==-1){
			sum+=nnum;
		}
		else if(ins[i+1==-2]){
			sum+=nnum;
			deal[dealid++]=sum;
			sum=0;
		}
	}
	long long  res=1;
	for(int i=0;i<dealid;i++){
		res*=deal[i];
	}
	return res;
}


long long  domin(){
	long long  sum=1;//用乘法
	int nnum;
	int dealid=0;
	char minop;
	for(int i=0;i<id-1;i+=2){
		nnum=ins[i];
		if(ins[i+1]==-3){
			sum*=nnum;
			deal[dealid++]=sum;
			break;
		}
		else if(ins[i+1]==-1){//加法
			sum*=nnum;
			deal[dealid++]=sum;
			sum=1;
		}
		else if(ins[i+1==-2]){//乘法
			sum*=nnum;
		}
	}
	long long  res=0;
	for(int i=0;i<dealid;i++){
		res+=deal[i];
	}
	return res;
}


int main(){
	freopen("in.txt","r",stdin);   
	sf("%d",&n);
	while(n--){
		while(true){
			scanf("%d",&ins[id++]);
			scanf("%c",&op);
			//if(scanf("%c",&op)!=EOF){
				if(op=='\n'){
					ins[id++]=-3;// 代表结束了
					long long  mymax=domax();
					long long  mymin=domin();
					pf("The maximum and minimum are %lld and %lld.\n",mymax,mymin);
					id=0;
					break;
				}
				else if (op=='+'){
					ins[id++]=-1;//-1 is 加法
				}
				else if(op=='*'){
					ins[id++]=-2;// -2 is 乘法
				}
			//}
			/*else{
				ins[id++]=-3;// 代表结束了
				long long  mymax=domax();
				long long  mymin=domin();
				pf("The maximum and minimum are %lld and %lld.\n",mymax,mymin);
				id=0;
				break;

			}
			*/
		}
	}
	return 0;
}

