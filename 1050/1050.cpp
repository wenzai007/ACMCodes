/*
	�����뷨   hashӳ��   �ַ�  һ��Ҳ��255���ַ� 
	����  ����һ���ַ���ô��������Ϊtrue  ����Ҫɾ��
	ɾ����ʱ��������  ������ģ�����е��㷨
	����  ��¼��ɾ������Ŀ���ϵ���  ��ǰɾ��k��
	Ȼ��ɾ���ӹ� û��ɾ����ǰ�ƶ�k��  �൱�ڸ����˱�ɾ����
	Ԫ��  ��ȷ����ȷ 
	����   �Բ�
	��ô�򵥵ķ�����Ϊʲôû�뵽��Ҳ��hash
	���ǰ����ڵڶ��еľ͸�������ӡ�ͺ��˰�  2b
	int main()  
{  
    string a, b;  
    getline(cin, a);  
    getline(cin, b);  
    vector<bool> existed(MAX, false);  
    for (int i = 0; i < b.size(); ++i)  
        existed[b[i]] = true;  
    for (int i = 0; i < a.size(); ++i)  
        if (!existed[a[i]]) printf("%c",a[i]);  
    printf("\n");  
    return 0;  
}  

*/#define for if(0); else for 
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>>//��cmath ����û��math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;

const  int size=10008;
char ori[size];
char sec[size];
bool del[300];
int main(){
	freopen("in.txt","r",stdin);   
	while (gets(ori)){
		gets(sec);
		int len1=strlen(ori);
		int len2=strlen(sec);
		for(int i=0;i<len2;i++){
			del[sec[i]]=true;
		}
		int k=0;
		for(int i=0;i<len1;i++){
			if(del[ori[i]]==true){
				k++;
				continue;
			}
			else{
				ori[i-k]=ori[i];
			}
		}
		ori[len1-k]=0;//������һ��'\0'����
		printf("%s\n",ori);
	}
	return 0;
}

