#include <stdio.h>
#include<string>
using namespace std;
int main(){
	/*  ����Ҫ�ȷ����ڴ���ǶԵ�  �ſ��������ã�
	char *p;
    p = (char *)malloc(10);
    scanf("%s", p);
    printf("%s", p);
//*/
	char *mon;
	mon="abcd";
	//while(scanf("%s",mon)!=EOF){//ò�ƴ�������Ϊû�и�*mon
	//�����ڴ�   ����һ������Ϊ  char *mon="abcd";���ָ�ֵ�ķ�ʽ
	//�����ں��� �޸�ָ����ָ�������� ������c ���Ա�̵�����˵��
	//scanf("%s",*mon);
	char m[]="jdjdjd";
	char str[][10]={"dddad","adfdfa"};

    char* day="ttt";
	*mon='p';  //����ʱ������  ò�Ʋ��ܸ� ��  ���ܸģ�

/*#include <stdio.h>

int main()
{
    char str[12] = {'h','e','l','l','o',' ','w','o','r','l','d'};
    char* ptr = "hello world";
    str[0] = 'f';
    ptr[0] = 'f';  //���ַ�ָ��ָ����ַ����޸ģ������ֶδ�����Ϊ���ڴ��ַֻ������Ϊ���ַ������ڳ���
    return 0;
}


*/


	//strcpy(mon,day);
	
	  printf("%c",*mon);

	//}
return 0;
}