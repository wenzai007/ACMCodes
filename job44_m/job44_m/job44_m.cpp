#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
char instr[100];
char ans[100];
int a,b;

int main(){
	freopen ("in.txt","r",stdin);
	while (scanf("%d%s%d",&a,instr,&b)!=EOF){
		long sum=0;
		for(int i=strlen(instr)-1;i>=0;i--){
			char c=instr[i];
			int c_int;
			if (c<='9'){
				c_int=c-'0';
				//	sum+=(long) (c-'0')*pow((double)a,strlen(instr)-1-i);
			}
			else {
				switch (c){//！！不用switch啊
					//大家的处理方法是一样的啊。。。
					// 2b   
					case 'A':c_int=c-'A'+10;
							 break;
					case 'B':c_int=c-'A'+10;
							 break;
					case 'C':c_int=c-'A'+10;
							 break;
					case 'D':c_int=c-'A'+10;
							 break;
					case 'E':c_int=c-'A'+10;
							 break;
					case 'F':c_int=c-'A'+10;
							 break;
					case 'a':c_int=c-'a'+10;
							 break;
					case 'b':c_int=c-'a'+10;
							 break;
					case 'c':c_int=c-'a'+10;
							 break;
					case 'd':c_int=c-'a'+10;
							 break;
					case 'e':c_int=c-'a'+10;
							 break;
					case 'f':c_int=c-'a'+10;
							 break;
				}
			}
			sum+=(long) ((c_int)*(long)pow((double)a,(int)strlen(instr)-1-i));
//这个地方不要用pow函数  要用 c=1 然后每一次都c*=a;增加权重
		}
		int idx=0;
		do{
			int sum_digit=sum%b;
			char dig_char;
			if(sum_digit<=9)
				dig_char=sum_digit+'0';
			else {
				switch (sum_digit){
					case 10: dig_char='A';
							 break;
					case 11: dig_char='B';
							 break;
					case 12: dig_char='C';
							 break;
					case 13: dig_char='D';
							 break;
					case 14: dig_char='E';
							 break;
					case 15: dig_char='F';
							 break;
				}
			}
			ans[idx++]=dig_char;
			sum/=b;
		}
		while(sum);
		for(int i=idx-1;i>=0;i--){
			printf("%c",ans[i]);
		}
		printf("\n");
	}
	return 0;
}
