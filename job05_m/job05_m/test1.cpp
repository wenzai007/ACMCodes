#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;


int main(){//����ֻ����vector�����̬��char�����������ˣ�1
	char str[]="fadcegb";
	int len=strlen(str);
	sort(str,str+strlen(str));//������sizeof ��������ռ�ö����ֽڣ�Ӧ����strlen
	for(int i=0;i<strlen(str);i++)
	{
		printf("%c ",str[i]);
	}
	system("pause");
	return 0;
}