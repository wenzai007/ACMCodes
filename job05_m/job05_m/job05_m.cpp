
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
 char buf[201];
  
//vector<char> buf;
/*
bool cmp(char *a, char *b){
	int res =strcmp(a,b);
	return res 0;
}
  //*/

int main(){//����ֻ����vector�����̬��char�����������ˣ�no no
	

	while (scanf("%s",buf)!=EOF){//sort �ɲ����Զ��ַ�����������򣿿��Ե�
		 #ifndef ONLINE_JUDGE
    #else
    freopen("E:\\in.txt","r",stdin);
    #endif
		int bufsize=strlen(buf);
		  sort(buf,buf+bufsize);
		  printf("%s\n",buf);
		//  for(int i=0;i<201;i++){
		//	buf[i]=NULL;�˴��������  ��� ��������110  ˵��
		//  }
	}


}







//this is for the middle effect
//*/