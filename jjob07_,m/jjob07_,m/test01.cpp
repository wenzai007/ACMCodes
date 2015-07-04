#include <stdio.h>
#include<string>
using namespace std;
int main(){
	/*  看来要先分配内存才是对的  才可以这样用！
	char *p;
    p = (char *)malloc(10);
    scanf("%s", p);
    printf("%s", p);
//*/
	char *mon;
	mon="abcd";
	//while(scanf("%s",mon)!=EOF){//貌似错误是因为没有给*mon
	//分配内存   另外一点是因为  char *mon="abcd";这种赋值的方式
	//不能在后面 修改指针所指的内容了 这是在c 语言编程的书中说的
	//scanf("%s",*mon);
	char m[]="jdjdjd";
	char str[][10]={"dddad","adfdfa"};

    char* day="ttt";
	*mon='p';  //运行时出错！！  貌似不能改 是  不能改！

/*#include <stdio.h>

int main()
{
    char str[12] = {'h','e','l','l','o',' ','w','o','r','l','d'};
    char* ptr = "hello world";
    str[0] = 'f';
    ptr[0] = 'f';  //将字符指针指向的字符串修改，将出现段错误，因为该内存地址只读，因为该字符串属于常量
    return 0;
}


*/


	//strcpy(mon,day);
	
	  printf("%c",*mon);

	//}
return 0;
}