//1.开始的时候17分  然后把1不是质数的判定条件加入
//过了一个点  变成了20分 还差5分
//2.找到了一个原因  就是我的处理冲突的规则是不正确的  首先+1  然后是在
//起点+4  而不是在+1的基础上进行+4  所以其实是+1 再+3
//3 另外  是可以循环进行处理的  不断的循环 只要满足循环的过程中有空位就可以的 知道j*j中的j等于tsize
//为止！！！所以就是需要%一个msize
//4 另外我找素数的过程太耗时间 其实从开始的地方开始判断、
//然后不断的递增其实就是可以的了   
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>

#include<stack>
#include<queue>
#include<vector>
#include<map>

#include<time.h>
using namespace std;

const int size =100800;
bool mark[size];
int primes[size];
int id;
void init(){
	for(int i=0;i<size;i++){
		mark[i]=true;
	}
	mark[0]=mark[1]=false;
 	id=0;
	for(int i=2;i<size;i++){
		if(mark[i]==false)
			continue;
		primes[id++]=i;
		if(i>400)
			continue;
		for(int j=i*i;j<size;j+=i){
			mark[j]=false;
		}
	}
}

bool judge(int x){
	int bound=(int)sqrt((double)x)+1;
	//下面加一句
	if(x<=1)return false;
	for(int i=2;i<bound;i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}
//bool flag[10001];//第一个大于10000的素数是10007
bool flag[10010];
int tsize,N;

int main(){
	init();
	freopen("in.txt","r",stdin);
	while(scanf("%d",&tsize)!=EOF){
		scanf("%d",&N);
		while(judge(tsize)==false){
			tsize++;
		}
		/*
		if(judge(tsize)==false){//if it is not prime ,make it prime 
			for(int i=0;i<id;i++){// not a good solution  shoud start 
				// from tsize and plus one by one 
				if(primes[i]>tsize){
					tsize=primes[i];
					break;
				}
			}
		}
		*/
		for(int i=0;i<tsize;i++){
			flag[i]=false;
		}
		int nn;
		for(int i=0;i<N;i++){
			scanf("%d",&nn);
			int pos=nn%tsize;
			if(flag[pos]==false){//attention of the last character no space
				if(i==0){
					printf("%d",pos);
				}
				else {
					printf(" %d",pos);
				}
				flag[pos]=true;
				continue;
			}
			int findit=false;
			for(int j=0;j<tsize;j++){// the j is smaller than the tsize
				pos=(nn%tsize+j*j)%tsize;
				if(flag[pos]==false){
					flag[pos]=true;
					findit=true;
					printf(" %d",pos);
					break;
				}
			}
			if(findit==false){
				printf(" -");
			}
			/*原来的是这个 但是方法和移动的步骤完全是错误的
			for(int j=1;pos<tsize&&flag[pos]==true;j++){
				pos+=j*j;
			}
			if(pos>=tsize){
				printf(" -");
			}
			else{
				printf(" %d",pos);
				flag[pos]=true;//！！这里忘记了
			}
			*/
		}
		printf("\n");
	}
	return 0;
}



