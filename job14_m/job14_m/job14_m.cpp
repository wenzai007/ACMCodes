/*/思路是直接就用排版来做  然后每一次不要忘记清空缓冲区数组
//另外  由于最后一行的开始是第一列  所以从最后一行开始向上进行赋值
//这样才能更好的将整个图片映射进去！
//见test01 中的总结
//log 1.wrong answer 可能格式错了 不是 是数组开的太小了。。！！

*/
#include<stdio.h>
char pic[3000][3000];

int main(){
	int h;
	while(scanf("%d",&h)!=EOF){
		
		for(int i=h-1,k=0;i>=0;i--,k++){//注意我的这种写法！
			                          //一不小心将i--写成i++了造成运行时错误
			                          //数组越界了！！！！
			for(int j=0;j<=k*2-1;j++){
				pic[i][j]=' ';//注意这里是空格而不是空字符！
			}
			for(int j=k*2;j<h+2*(h-1);j++){
				pic[i][j]='*';//不能用双引号   之前出错了！
			// 无法从“const char [2]”转换为“char” 没有使该转换得以执行的上下文
			}
		}
		for(int i=0;i<h;i++){
			for(int j=0;j<h+2*(h-1);j++){
				printf("%c",pic[i][j]);
			}

			printf("\n");
			/*
			if(i==h-1){	printf("\n");
			}
			else {
				printf("\n");
				printf("\n");
			}
			*/
		}
	
	}
	return 0;
}
