#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>//��cmath ����û��math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>
using namespace std;
char sstr_c[50];
char lstr_c[100];
string lstr;
int main(){
	freopen("in.txt","r",stdin);
	gets(sstr_c);
	for(int i=0;i<strlen(sstr_c);i++){
		sstr_c[i]=tolower(sstr_c[i]);
	}//ȫ���Сд
	int len=strlen(sstr_c);
    while(gets(lstr_c)){
		string b=lstr_c;string c=lstr_c;
		for(int i=0;i<b.size();i++){
			b[i]=tolower(b[i]);//����ֱ����b[i]��Ϊ��������ƣ�
		}
		int t=b.find(sstr_c,0);
		while(t!=string::npos){
			b.erase(t,len);
			c.erase(t,len);
			t=b.find(sstr_c,0);
		}
		t=b.find(' ',0);
		while(t!=string::npos){
			b.erase(t,1);
			c.erase(t,1);
			t=b.find(' ',0);
		}
	//printf("%s\n",c);//������ôд ��Ϊ����ת����
		//const char*���Ͳſ��Ե�  ��c.c_str() 
		//����ֻ���ں������������ǿ��Ե�  ������ƵĻ�����
		//����Ҫ��strcopy�������и��Ʋſ���  ��Ϊc_str()���ص���һ����ʱ
		//ָ��  ���ܽ��в��� ò��ֻ����һ�������ķ�Χ�ڽ��в���������
		//��Ч�� ���ص���һ��Ұָ��  �� 3.7�ŵĺ����ܽ�
		printf("%s\n",c.c_str());
	}
	
	//���Ҫ��scanf("%s")�Ļ�  û��ɾ���Ǹ�\n �ķ��� �����´�scanf(%s)
	//��ʱ���������һ���ǿյ��ַ���������
	//��gets������ʱ��ͻ����һ�����ַ�������p186
	//��ʱ��A��Ҫ����\n  �Ƚ��鷳����
	return 0;
}

