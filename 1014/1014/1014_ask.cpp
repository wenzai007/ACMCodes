/*  
����Ȿ���ѡ���һֱû�й����������˺ܾ�ûû���֡����˱��˵Ĵ���֮�󣬲ŷ���ԭ����Ŀ�н��ġ�Note that since the bank is closed everyday after 17:00, for those customers who cannot be served before 17:00, you must output "Sorry" instead.�� ��ʵ��˵��ʼ����ʱ�䲻�ܳ���17:00�����Ƿ������ʱ�䡣

*/
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

queue<int> q[22];//ÿһ������һ������  
int process[1080];//ÿһ���˵Ĵ���ʱ��
int origi_process[1080];//����ԭ���Ĵ���ʱ�䣬��Ϊ�������process�����ı��
int finish[1080];//ÿһ���˵����ʱ��
int query[1080];//��ѯ������
int N,M,K,Q;

string  format(int x,int i){//Ϊ�������ʽ
	string ret;
	char str[12];
	int hour,minute;
	/*�˴����˵�� ��
1. >=д����> ���ִ������ڱ߽���������������Ŀ�и����Ĳ������ݿ���ȷ����>=��д>�Ļ��������sorry
2. origi_process[query[i]] д���� origi_process[i] ��Ҳ�ǳ�����bug
3. ��Ŀû����ϸ����Ŀ�С�At 08:00 in the morning, customer1 is served at window1����˵����ν�ġ�served"��ָ��ʼҵ���ʱ�䣬�� for those customers who cannot be served before 17:00, you must output "Sorry" instead.�� ˵������17:00֮ǰserved��Ҳ����˵������17:00֮ǰ��ʼҵ������sorry��Ҳ����˵����17:00��ʼ��ҲҪ���sorry
*/
	if(x>=540){
		if(x-origi_process[query[i]]>=540){//ע����  ��ʼʱ�����540 17:00
		ret="Sorry";
		return ret;
		}
	}

//	if(x>540){
//		if(x-origi_process[i]>540){//ע����  ��ʼʱ�����540 17:00
//		ret="Sorry";
//		return ret;
//		}
//	}
	hour=8+x/60;
	minute=x%60;
	sprintf(str,"%02d:%02d",hour,minute);//��ʽ���ַ���
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
			origi_process[i]=process[i];
		}
		for(int i=1;i<=Q;i++){
			scanf("%d",&query[i]);
		}
		int idx=1;//����Ϊ��ʼ��    idxΪ��ǰӦ�ý���������ڵ���һ����!
		for(int i=1;i<=M;i++){
			for(int j=0;j<N;j++){
				if(idx>K) break;
				q[j].push(idx++);//ÿһ�����ڶ�Ӧһ������ ÿ�����а�������
			}
		}//����ʱ�� ȫ����� ����ȫ��ȥ�� Ҳ����û��
		//idx����һ��Ӧ�ý�����е���
		int t=0;//ʱ�䡢 ��ʱ��ı仯������ÿһ��״̬ ��Ϊt����
		while (true){//һֱѭ�� ֱ��ÿһ���Ӷ��ǿյ�ֹͣ
			bool empty=true;//�ǲ������ж��ж��յ�
			for(int i=0;i<N;i++){
				if(!q[i].empty())
					empty=false;
			}
			if(empty==true) break;//���˾�ֹͣ
			t++;//ʱ�䲻������  �Է�����Ϊ��λ
			for(int i=0;i<N;i++){//ÿһ���Ӷ���ÿһ�����еĵ�һ����
				if(!q[i].empty()){
					int newp=q[i].front();//ÿһ�����еĵ�һ����
					process[newp]--;//ʱ�����
					if(process[newp]==0){
						q[i].pop();//����ǵĻ�����
						finish[newp]=t;//������ӵ��˽�����ʱ���ʱ����t
						if(idx<=K){//ÿ������ֻ���г��ӵ�ʱ��Ż�����ӵ�
							q[i].push(idx);//��һ�������
							idx++;
						}
					}
				}
			}
		}//while  true
		for(int i=1;i<=Q;i++){//��sprintf 
			string s=format(finish[query[i]],i);//����ÿһ����ѯ�Ľ��
			printf("%s\n",s.c_str());//�����
		}
	}



	return 0;
}

