//use the 哨兵！！
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

		}//跳出的时候i不是0，而是-1  sb！！ 
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
	return 0;// 好习惯！！！  别忘了！
}













// for the middle effect
