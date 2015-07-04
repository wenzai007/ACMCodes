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

queue<int> q[22];
int process[1080];
int finish[1080];
int query[1080];
int N,M,K,Q;

string  format(int x){
	string ret;
	char str[12];
	int hour,minute;
	if(x>540){
		ret="Sorry";
		return ret;
	}
	hour=8+x/60;
	minute=x%60;
	sprintf(str,"%02d:%02d",hour,minute);
	ret=str;
	return ret;
}


int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d%d%d%d",&N,&M,&K,&Q)!=EOF){//N�Ǵ�����Ŀ
		for(int i=0;i<N;i++){
			while (!q[i].empty()) q[i].pop();

		}
		for(int i=1;i<=K;i++){
			scanf("%d",&process[i]);
		}
		for(int i=1;i<=Q;i++){
			scanf("%d",&query[i]);
		}
		int idx=1;
		for(int i=1;i<=M;i++){
			for(int j=0;j<N;j++){
				if(idx>K) break;
				q[j].push(idx++);
			}
		}//����ʱ�� ȫ�����
		//idx����һ��Ӧ�ý�����е���
		int t=0;//ʱ�䡢
		while (true){//һֱѭ�� ֪���ӿ�
			bool empty=true;
			for(int i=0;i<N;i++){
				if(!q[i].empty())
					empty=false;
			}
			if(empty==true) break;//���˾�ֹͣ
			t++;//ʱ�䲻������  �Է�����Ϊ��λ
			for(int i=0;i<N;i++){
				if(!q[i].empty()){
					int newp=q[i].front();
					process[newp]--;
					if(process[newp]==0){
						q[i].pop();
						finish[newp]=t;
						if(idx<=K){//ÿ������ֻ���г��ӵ�ʱ��Ż�����ӵ�
							q[i].push(idx);
							idx++;
						}
					}
				}
			}
		}//while  true
		for(int i=1;i<=Q;i++){//��sprintf
			string s=format(finish[query[i]]);
			printf("%s\n",s.c_str());
		}
	}



	return 0;
}

