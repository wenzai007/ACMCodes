//http://www.cskaoyan.com/viewthread.php?tid=80075&highlight=1108
//���õ�O  �����пո�ģ��� fuck
//��ʽ����
// �������ȡ%d  �����Ķ�ȡһ���ַ��أ���  ������
// scanf(" %c",cc); �ȹ������пո�س��ȵ� Ȼ���ڶ���һ���ַ�
//����    scanf("%c\n",cc);  ���������ȶ���һ���ַ� �ٹ������пո�س��ȵ�
// ������� scanf(" %c\n",cc); �ȹ��� �ڶ�  �ڹ���
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
		//getchar();//��ӵ� Ϊ���յ����з��� ������յľ��ǵڶ��е�һ���ַ�
		for(int i=0;i<n;i++){
			//scanf("%c%d",&cc,&tmp);
		//	scanf("%c",&cc);
			scanf(" %c\n",&cc);
			switch(cc){
				case 'P':
					     scanf("%d",&tmp);//���Ǽ��ˣ�
			             
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
