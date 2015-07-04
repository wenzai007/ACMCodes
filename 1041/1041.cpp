/*
开始的时候想用  map  但是好像这样不行 因为
map的次序是动态变化的  自动按照 key来进行排序的
所以换一种方法 用  hash的思想  计数就好了

  编译错误！！！！！！  取数组的名字的时候不能用hash名字
  因为gcc++ 不允许 这样是重复命名有混淆！！
  所以换一个名字
*/

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
//map<int,string> mp;
int buf[100008];
int mhash[10008];
int main(){
	freopen("in.txt","r",stdin);
	int N;
	while (scanf("%d",&N)!=EOF){
		for(int i=0;i<10008;i++){
			mhash[i]=0;
		}
		for(int i=0;i<N;i++){
			scanf("%d",&buf[i]);
			mhash[buf[i]]++;
		}
		int ans=0;bool  find=false;
		for(int i=0;i<N;i++){
			if(mhash[buf[i]]==1){
				find=true;
				ans=buf[i];
				printf("%d\n",ans);
				break;//之前没有加这句话 浪费了很多的时间
			}
		}
		if(find==false)
			printf("None\n");
	}
	/*
	freopen("in.txt","r",stdin);   
	mp.insert(make_pair(10,"hehe"));
	mp.insert(make_pair(5,"uuu"));
	mp.insert(make_pair(6,"yeyi"));
	*/
	return 0;
}

