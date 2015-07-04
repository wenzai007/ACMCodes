#include <stdio.h>
#include<stdlib.h>


int main(){
/*
	char str[]="aaaaa";
 char ctr[]; 
 ctr="adfd";//出错 必须直接初始化！
 */
	/*  这样也是不行的   没有初始化 运行错！
	char *p;
	printf("%c",*p);
   */

  
	/*
	char *p=  (char *)malloc(
	sizeof(char)*10);
  p="addf";
  char str[10]="aad";
*/
char *p=(char *)malloc (sizeof(char)*5);
*p='a';*(p+1)='b';
*(p+1)='h';
 
return 0;
}