#include<stdio.h>
void main(){
 int buf[100];
int a=12;
buf[0]=10;
buf[1]=14;
printf("%d ",buf[0]);
printf("hehehe");
int *p=buf;
*++p=12;
 //*p++=12;
 printf("-----");
  printf("%d ",buf[0]);
   printf("&&&&");
 printf("%d ",*p);
getchar();
}