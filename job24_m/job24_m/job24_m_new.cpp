#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;
int L,N;
int buf[660];
bool used[660];
bool  cmp(int a,int b){
	return a>b;
}
int totaltmp=0;//�洢���ǵ�ǰ�� ��
// the most important function!
void DFS(int num){
	if(totaltmp+buf[num]==L){
		used[num]=true;
		totaltmp+=buf[num];
		return;
	}
	else if(totaltmp+buf[num]>L){
		return ;
	}
	else{
		for(int i=num;i<N;i++){
			used[i]=true;
			totaltmp+=buf[i];
			//for(int j=num+1;j<N;j++){//������j=i+1 ��ƫƫд��j=num+1
				     //�߼�������  ��ô���ԵĴ���û���ְ�����
			for(int j=i+1;j<N;j++){
				DFS(j);
				if(totaltmp==L)return ;
			    if(totaltmp>L) continue;
			}
			//�����е�����Ĵ���Ļ�˵��û�е��ڵ�����
			//����ʧ��
			used[i]=false;
			totaltmp-=buf[i];
		}
	}
}


int main(){
	//freopen ("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while (scanf("%d%d",&L,&N)!=EOF){
		int total=0;
		for(int i=0;i<N;i++){
			used[i]=false;
		}
		for(int i=0;i<N;i++){
			scanf("%d",&buf[i]);
			total+=buf[i];
		}
		sort(buf,buf+N,cmp);
		if(total<L){
			printf("impossible\n");
			//break;//������������� ��Ϊ��������ڵĻ�����
			      //���ڼ����һ��������  ���Բ���Ӧ�øĳ�continue
			continue;
		}
		if(total==L){
			printf("%d\n",N);
			//break;
			continue;
		}
	
		
 		int px;
		totaltmp=0;//֮ǰ���ǳ�ʼ��
		/*
		for(px=0;
			px<=N&&totaltmp<L;
			px++){//px�����Ʋ���̫�� 
			totaltmp+=buf[px];
		}
		*/
		for(px=0;px<N;px++){
			if(totaltmp>=L)break;
			totaltmp+=buf[px];
			
		}
		if(totaltmp==L){
			printf("%d\n",px);
		}
		else {
			//printf("%d\n",px+1);//����ط�������px+1����px����wa
			printf("%d\n",px);
		}
	//	DFS(0);
		//int minUse;//����û�г�ʼ��  ���������minuse++ ��������ʱ����
	//	int minUse=0;
	//	for(int i=0;i<N;i++){
	//		if(used[i]==true) minUse++;
	//	}
		//�������˴����� ��Ϊ���Ǽ�minuseΪ0�Ļ� ��ӡ��impossible ���Բ���
		// Ӧ�ü��������� �����Ȼ��wa
	/*	if(minUse==0){
			printf("impossible\n");
			continue;
		}
		printf("%d\n",minUse);
			*/
	}


	return 0;
}














//effect
