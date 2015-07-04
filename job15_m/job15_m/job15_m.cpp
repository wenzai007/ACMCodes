//叠筐  必须从中心开始搞 因为开始的时候不知道最外层是什么字符
//这里面我们试着从下标一开始搞  不去理会0下标
#include <stdio.h>
char pic[85][85];
int num;
char inin,out;
int main(){
	//FILE * tmpout=stdout;
	freopen("CON","r",stdin);
	//freopen("out.txt","w",stdout);
	int middle_x,middle_y;
	while(scanf("%d %c %c",&num,&inin,&out)!=EOF){
		if(num==0)break;
		middle_x=middle_y=num/2+1;//can i write like this
		bool flag=(num==1)?true:false;
		pic[middle_x][middle_y]=inin;
		char c;// restore the char;
		for(int i=1;i<=num/2;i++){
			c=(i%2==0)? inin:out;
			int left=middle_x-i;
			int up=middle_x-i;
			int rihgt=middle_x+i;
			int down=middle_x+i;
			for(int j=left;j<=rihgt;j++){
				pic[j][up]=c;
				pic[j][down]=c;
				pic[left][j]=c;
				pic[rihgt][j]=c;
			}
			
		}
		if(flag==false){
			pic[1][1]=pic[1][num]=pic[num][1]=pic[num][num]=' ';
		}
		for(int i=1;i<=num;i++){
			for(int j=1;j<=num;j++){
			printf("%c",pic[i][j]);
			}
			printf("\n");
		}
		
		printf("\n");
	}//  while 
	getchar();
}// main









// for the middle  effect
