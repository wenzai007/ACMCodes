/*

#include<stdio.h>
void main(){
	int   n;
	int buf[100];
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&buf[i]);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n-i-1;j++){
				if(buf[j]>buf[j+1]){
					int temp=buf[j];
					buf[j]=buf[j+1];
					buf[j+1]=temp;
				}
			}
		}
		for(int  i=0;i<n;i++){
			printf("%d ",buf[i]);
		}
		printf("\n");

	
	}
	
}
  //*/
/*程序总结：  
 * 1.在有输入进入的时候一定
 * 要要用空格讲不同的数字进行分割，用空格 否则他会认为
 * 这些是一个数字  而不能分隔
 * 2.scanf（）函数一定要用正确，第一个参数是读入的数，
 * 第二个参数是要被赋值的变量 前面要加&符号 ，否则内存出错！
 * 除了指针和数组的首地址名称例外 其他都要加&符号！
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * */
