//�о��ò��鼯 �ǲ�����  ����Ū  �����뵽��dfs������ ��ͨ�����ĸ�����
//д��֮���ڿ��� ��û���ò��鼯������
//�ҵ�˼·  �þ����ʾͼ  ÿһ�� ��ȥ��һ�� �� ����ͨ�����ĸ���
//Ȼ�����  ����ٰ� ����㻹ԭ��ȥ
//ܳ��������������
//д���ˡ������������þ����  �������Ҫ���þ���Ļ����������̫��ʱ��
//���ǵ���vector  ����д����������  ��_2!!!
//
//

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
//ע�� ��������map  ��Ϊpat�����ǲ������ ���ܻ����� ��pic
int pic[1080][1080];//Ϊ�˽�ʡ�ռ���ʵ��bool�͹��˰� ÿ��Ԫ��1B
int remem[2080][2];//��¼ ɾ������Щ�㷽�㻹ԭ��ʱ����

//bool mark[1080][1080]; �� ����Ϥ�Ľ��
bool mark[1080];
int N,M,K;

using namespace std;

int main(){//��Ȼ��ÿһ��case  ֻ��һ�����ݵĻ�  ��ô�ҾͲ���while EOFʲô����
	scanf("%d%d%d",&N,&M,&K);
	for(int i=1;i<=N;i++){
		//mark[i]=false;
		for(int j=1;j<=N;j++){
			pic[i][j]=-1;
		}
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
using namespace std;

int main(){
	
	return 0;
}

	}
	int a,b;
	while (M--!=0){
		scanf("%d%d",&a,&b);
		pic[a][b]=8;
		pic[b][a]=8;
	}
	while (K--!=0){
		int del;
		for(int i=0;i<2*N;i++){
			remem[i][0]=0;
			remem[i][1]=0;
		}
		int idx=0;
		scanf("%d",&del);
		for(int i=1;i<=N;i++){
			if(true==pic[i][del]){
				remem[idx][0]=i;
				remem[idx][1]=del;
				idx++;
				pic[i][del]=false;
			}
			if(true==pic[del][i]){
				remem[idx][0]=del;
				remem[idx][1]=i;
				idx++;
				pic[del][i]=false;
			}
		}
		int ans=0;
		for(int i=1;i<=N;i++){
			if(mark[i]==false){
				dfs(i);
				ans++;
			}
		}
		printf("%d\n",ans);

	}
	return 0;
}

