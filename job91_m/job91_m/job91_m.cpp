//��һ�ַ�������  stl  ֱ�Ӽ�  online�������о͸㶨�ˡ���ͷ�ļ� algorithm��
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>

#include<algorithm>
#include<math.h>

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>
using namespace std;
char word[8];
char ans[8];
bool mark[8];
int L;
void output(){
	printf("%s\n",ans+1);
	/*TLE �˴�һ��ʼ ��Ϊ���Ӷ�̫�� Ѱַ����
	��������� printf("%s")�ͺ���  ˵��
	�Ժ������ʱ���������ʱ��Ļ������
	�ַ��������������
	for(int i=1;i<=L;i++){
		printf("%c",ans[i]);
	}
	*/
	//printf("\n");
}
void dfs(int num){
	if(num==L+1){
		output();
		return;
	}
	for(int i=1;i<=L;i++){
		if(mark[i]==false){
			mark[i]=true;
			ans[num]=word[i];
			dfs(num+1);
			mark[i]=false;
		}
	}
}
int main(){//�����˿��������û���÷ǵݹ��д�ģ���˭�õķǻ��ݷ�
	freopen("in.txt","r",stdin);
	while (scanf("%s",word+1)!=EOF){//�����Ϊ�˴��±�1��ʼ�洢
		//int L=strlen(word);����������0
		L =strlen(word+1);//���abcd�Ļ��������4 ��������Ҫ<=L
		for(int i=1;i<=L;i++){
			mark[i]=false;
		}
		//���ǳ�ʼ��ans[]���³�����
		for(int i=1;i<8;i++)
			ans[i]=0;//�ÿգ���
		dfs(1);
		printf("\n");
	}
	return 0;
}

