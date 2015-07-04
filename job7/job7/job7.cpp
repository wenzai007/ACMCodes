#include<stdio.h>
#include<string.h>
#define  isleap(x)  x%3==0?1:0;


//*/

int main(){
int m=12;
int s=isleap(m);
char yes[3][12]={
"abddda",
"babababa",
"hehehe"
};
int hash[4]={9999999,121212};//默认后面的都是他妈的0！！！
char nono[4]={"123"};//大小为4的char数组 只能显示3个字符 这是为什么
//printf("%d",s);
puts(nono);
for(int i=0; i<3;i++){

//puts(yes[i]);//
printf("dddddd");
}
printf("\n");
for(int i=0;i<4;i++){
printf("%d\n",hash[i]);
}
getchar();
return 0;//  i want to change the file and save  it :
}


//*/
