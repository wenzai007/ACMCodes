#define for if(0); else for 
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>//��cmath ����û��math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;

struct node{
	int x,y;
}buf[1500];
int mymax;
int nsum;
void justdoit(int tol){
	mymax=2;
	//nsum=2;  �����������ʼ�� ��� Ӧ����ÿһ��ֱ�ߵĿ�ʼ�� ��ʼ������
	for(int i=0;i<tol;i++){
		for(int j=i+1;j<tol;j++){//��Ϊ����������ȷ��һ��ֱ�ߣ�����Ҫ�������еĵ� ���������ҵ�
			//���е�ֱ�ߣ�Ȼ������е�ֱ���ϵĵ㶼ͳ�Ƴ��������������ֵ�Ϳ������ǲ���
			nsum=2;
			for(int k=j+1;k<tol;k++){
				if((buf[j].y-buf[i].y)*(buf[k].x-buf[i].x)==(buf[j].x-buf[i].x)*(buf[k].y-buf[i].y)){//  ��������ɳ˷��ļ���  ����Ǻܳ�����
					nsum++;
					if(nsum>mymax)
						mymax=nsum;
				}
			}
			
		}
	
	}
	printf("%d\n",mymax);
}

int main(){
	freopen("in.txt","r",stdin);   
	int cnum;
    char ins[100];
	scanf("%d",&cnum);
	gets(ins);
	gets(ins);//��һ������
	int cnt;
	while (cnum--){
		cnt=0;
		while(gets(ins)){
			// ������ ""���ǿ�if(ins==NULL&&cnt!=0){// ����һ��case�����һ�еĿո�
			if(ins[0]=='\0'&&cnt!=0){
				break;
			}
			sscanf(ins,"%d%d",&buf[cnt].x,&buf[cnt].y);
			cnt++;

		}
		/*if(cnt==1){
			printf("1\n");
			return 0;
		}
		��Ŀ�Ѿ�˵�˴���1  ���Բ���
		*/  
	    justdoit(cnt);
		if(cnum){
			printf("\n");
		}


	}
	return 0;
}

