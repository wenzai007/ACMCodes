//yes  ac  only in one time !!
#include<stdio.h>
#include<stdlib.h>

#include<string>
#include<string.h>
#include<ctype.h>

#include<math.h>
#include<algorithm>

#include<queue>
#include<stack>
#include<map>
#include<vector>
using namespace std;
bool findit;//��û���ҵ�
int change[16]={
	
	51200,58368,29184,12544,  
     35968,20032,10016,4880,  
     2248,1252,626,305,  
     140,78,39,19  
};

char pic[4][4];
int cur;
int step;
void dfs(int block,int dep){//�ӵ�0�鿪ʼ�仯
	if(dep==step){//  outlet_1
		if(cur==0||cur==65535){
			findit=true;
		}
		return;
	}
	if(block>=16||findit)//֮���Լ������findit����ΪΪ�˾���Ľ�����dfs�Ĺ���  outlet_2
		//���� ���������16�Ļ�  ��ô����Ͳ�Ҫ��ȥִ���ˣ�
		return;
	cur=cur^change[block];//turn over
	dfs(block+1,dep+1);
	cur=cur^change[block];// recover !!  sure  this is to recover from begining
	dfs(block+1,dep);
}
int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%s",&pic[0])!=EOF){
		for(int i=0;i<3;i++){
			scanf("%s",&pic[i+1]);
		}
		cur=0;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				cur<<=1;
				if(pic[i][j]=='b')
					cur+=1;
			}
		}
		findit=false;
		for(step=0;step<=16;step++){
			dfs(0,0);
			if(findit==true) break;
		}
		if(step>16)
			printf("Impossible\n");
		else 
			printf("%d\n",step);
	}
	return 0;
}

/*: 1. error C2872: ��find��: ����ȷ�ķ���
1>        �����ǡ�d:\documents\visual studio 2008\projects\p1753\p1753\p1753_mine_dfs.cpp(16) : bool find��
1>        ��       ��d:\���\c++vs2008\vc\include\algorithm(72) : _InIt std::find(_InIt,_InIt,const _Ty &)��
1>d:\documents\visual studio 2008\projects\p1753\p1753\p1753_mine_dfs.cpp(35) : error C2872: ��find��: ����ȷ�ķ���
1>        �����ǡ�d:\documents\visual studio 2008\projects\p1753\p1753\p1753_mine_dfs.cpp(16) : bool find��
1>        ��       ��d:\���\c++vs2008\vc\include\algorithm(72) : _InIt std::find(_InIt,_InIt,const _Ty &)��

��˵ʲô��   ����㷨�о�ȻҲ��find������� ������˸���
*/
