// ֮����Կ�����sortֱ������Ļ��᲻�ᳬʱ
#include<stdio.h>
int buf[1000008];//���õİ� ���������� ����100008��Ӧ��д��1000008 
//������˰��Сʱ��ʱ��  �ύ��ʱ�����runtime error
int n;// the  total num
int n_out;
int main(){
	int tmp;
	while (scanf("%d%d",&n,&n_out)!=EOF){
		if(n==0)break;
		for(int i=0;i<1000008;i++)
			buf[i]=0;
		while (n--!=0){
			scanf("%d",&tmp);
			buf[tmp+500000]=1;
		}
		int outcnt=n_out;
		for(int i=1000000;i>=0&&n_out!=0;i--){//������д��һ��Ҫ�� ֹͣ����
			//�ö��Ż���&&������ô???
			if(buf[i]==1){
				if(n_out==outcnt){
					printf("%d",i-500000);
					n_out--;
				}
				else{
					printf(" %d",i-500000);
					n_out--;
				}
			}
		}
		printf("\n");
	}
}
