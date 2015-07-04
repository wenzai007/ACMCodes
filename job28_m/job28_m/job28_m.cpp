//http://www.cskaoyan.com/viewthread.php?tid=80075&highlight=1108
//你妹的O  后面有空格的！！ fuck
//格式问题
// 怎样像读取%d  那样的读取一个字符呢？？  这样读
// scanf(" %c",cc); 先过滤所有空格回车等等 然后在读入一个字符
//但是    scanf("%c\n",cc);  的作用是先读入一个字符 再过滤所有空格回车等等
// 结合起来 scanf(" %c\n",cc); 先过滤 在读  在过滤
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
stack<int> numstack;
int n;
char cc;
int tmp;
char ppp;
int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d",&n)!=EOF&&n){
		while(!numstack.empty())
			numstack.pop();
		//getchar();//后加的 为了收到换行符号 下面接收的就是第二行第一个字符
		for(int i=0;i<n;i++){
			//scanf("%c%d",&cc,&tmp);
		//	scanf("%c",&cc);
			scanf(" %c\n",&cc);
			switch(cc){
				case 'P':
					     scanf("%d",&tmp);//忘记加了！
			             
					     numstack.push(tmp);
						 break;
				case 'O':  
							if(!numstack.empty()){
							 numstack.pop();
						 }
						 break;
				case 'A':if(numstack.empty()){
							 printf("E\n");
						 }
						 else {
							 int res=numstack.top();
							 printf("%d\n",res);
						 }
						 break;
			}
			//getchar();

		}
		printf("\n");
	}
	return 0;
}
