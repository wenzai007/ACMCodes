
/*
	17/20
测试点	结果	用时(ms)	内存(kB)	得分/满分
0	答案正确	2	380	8/8
1	答案正确	2	256	2/2
2	答案错误	1	256	0/3
3	答案正确	2	380	3/3
4	答案正确	2	376

  后来 因为不仅要改is  are  还要改 accounts！！ shit
  过了  20分！
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


const int size=1008;
struct  stu{
	char user[20];
	char pass[20];
	bool modi;
}buf[size];
int N;

int main(){
	freopen("in.txt","r",stdin);   
	while(scanf("%d",&N)!=EOF){
		for(int i=0;i<N;i++){
			scanf("%s",buf[i].user);
			scanf("%s",buf[i].pass);
			buf[i].modi=false;
		}
		int cnt=0;
		for(int i=0;i<N;i++){
			char *ns=buf[i].pass; //就是一个引用
			int len=strlen(buf[i].pass);
			bool &nf=buf[i].modi;
			for(int j=0;j<len;j++){
				char &c=ns[j];//实验 对了 这几个引用都起作用了！！
				switch (c){
				case '1': c='@';
						  nf=true;
						  break;
				case '0': c='%';
						  nf=true;
						  break;
				case 'l': c='L';
						  nf=true;
						  break;
			    case 'O': c='o';
						  nf=true;
						  break;
				default : break;
				}
			}
			if(nf==true){
				cnt++;
			}
		}
		if(cnt==0){
			if(N==1){
				printf("There is 1 account and no account is modified\n");
			}

			/* 这个写错了 accounts!! 竟然只有一个case没过去  难道其他case都是单数的
			else{
				printf("There are %d account and no account is modified\n",N);
			}
			*/
			else{
				printf("There are %d accounts and no account is modified\n",N);
			}
		}
		else {
			printf("%d\n",cnt);
			for(int i=0;i<N;i++){
				if(buf[i].modi==true){
					printf("%s %s\n",buf[i].user,buf[i].pass);
				}
			}
		}
		
	}//while 
	
	return 0;
}

