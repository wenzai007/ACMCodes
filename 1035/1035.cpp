
/*
	17/20
���Ե�	���	��ʱ(ms)	�ڴ�(kB)	�÷�/����
0	����ȷ	2	380	8/8
1	����ȷ	2	256	2/2
2	�𰸴���	1	256	0/3
3	����ȷ	2	380	3/3
4	����ȷ	2	376

  ���� ��Ϊ����Ҫ��is  are  ��Ҫ�� accounts���� shit
  ����  20�֣�
*/


#define for if(0); else for 
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>>//��cmath ����û��math

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
			char *ns=buf[i].pass; //����һ������
			int len=strlen(buf[i].pass);
			bool &nf=buf[i].modi;
			for(int j=0;j<len;j++){
				char &c=ns[j];//ʵ�� ���� �⼸�����ö��������ˣ���
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

			/* ���д���� accounts!! ��Ȼֻ��һ��caseû��ȥ  �ѵ�����case���ǵ�����
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

