//use the �ڱ�����
#include <stdio.h>
int buf[201];
int num;
int main(){
	int tmp;
	int i;
	while (scanf("%d",&num)!=EOF){
		for(i=1;i<=num;i++){
			scanf("%d",&tmp);
			buf[i]=tmp;
		}
		scanf("%d",&tmp);
		/*
		for(i=num;i>=0;i--){
			if(buf[i]==tmp)break;

		}//������ʱ��i����0������-1  sb���� 
		if(i==0){
			printf("-1\n");
		}
		*/
		for(i=num;i>0;i--){
			if(buf[i]==tmp)break;
		}
		if(i==0)printf("-1\n");
		else {
			printf("%d\n",i-1);
		}
	}
	return 0;// ��ϰ�ߣ�����  �����ˣ�
}













// for the middle effect
