//�����  ���õģ� �������Ҫ100���ַ��ſ���  ������г����������ģ�

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

#include<time.h>
using namespace std;
int n;
char tmp[100];
string buf[60];
bool cmp(string a, string b){
	return (a+b)>(b+a);
}
int main(){
	freopen("in.txt","r",stdin);   
	while(scanf("%d",&n)!=EOF&&n){
		for(int i=0;i<n;i++){
			scanf("%s",tmp);
			buf[i]=tmp;
		}
		sort(buf,buf+n,cmp);
		string output;
		for(int i=0;i<n;i++){
			output+=buf[i];
		}
		printf("%s\n",output.c_str());

	}
	/*
	string a="aaaa",b="bbbb";
	string c=a+b;
	int p=a<b?111:222;
	printf("%s\n",c.c_str());
	//*/
	return 0;
}


