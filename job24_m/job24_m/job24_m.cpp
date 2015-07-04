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
	while (scanf("%d%d",&L,&N)!=EOF&&L){
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
			printf("%d",N);
			break;
		}
		totaltmp=0;//֮ǰ���ǳ�ʼ��
		DFS(0);
		//int minUse;//����û�г�ʼ��  ���������minuse++ ��������ʱ����
		int minUse=0;
		for(int i=0;i<N;i++){
			if(used[i]==true) minUse++;
		}
		//�������˴����� ��Ϊ���Ǽ�minuseΪ0�Ļ� ��ӡ��impossible ���Բ���
		// Ӧ�ü��������� �����Ȼ��wa
		if(minUse!=0){
			printf("%d\n",minUse);
			continue;
		}
		else {   //���ﲻ�����벻���ܶ���Ҫ����ͳ��  ��Ϊ���Ծ�ϵģ�����
			int px;
			int anototaltmp=0;//֮ǰ���ǳ�ʼ��
			for(px=0;
				px<=N&&anototaltmp<L;
				px++){//px�����Ʋ���̫�� 
					anototaltmp+=buf[px];
			}
			if(anototaltmp==L){
				printf("%d\n",px);
			}
			else {
				printf("%d\n",px+1);
			}

		}

	}
	return 0;
}














//effect
