/*
һ��ʼ�Ұ����Ǵ�С����������Ϊ��������С�ˡ���������û�п����������������ݣ�
6 6 7 11.
һֱ����ȥ��61��������ȼ�ǰ�������ټ�7��11������ʣ�µ������������������60��
ԭ����ǵ�����ǰ��������֮�󣬱����7 11 12����ʱ��Ӧ�ü�7��11�ģ����Ҽ���7��12���˴�����1.
��ʵ���ǹ��������е����з���ڵ���ܺͶ����ˣ�Ҳ����˵�Ǹ��ǹ�������ľ��
wpl��
Ȼ����������ȶ����ˡ���
 *
 *
 * 
 *    
 * */

#define for if(0); else for 
#define pf printf
#define sf  scanf
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
/*  ��ʼ�Ĵ���д��
int main(){
	freopen("in.txt","r",stdin);   

int n;
int buf[5008];
int mybuf[5008];
	while(sf("%d",&n)!=EOF&&n){
		for(int i=0;i<n;i++){
			sf("%d",&buf[i]);
		}
		sort(buf,buf+n);
		int sum=buf[0];
		int id=0;
		for(int i=1;i<n;i++){
			sum+=buf[i];
			mybuf[id++]=sum;
		}
		int tot=0;
		for(int i=0;i<id;i++){
			tot+=mybuf[i];
		}
		pf("%d\n",tot);
	}
	return 0;
}
*/

priority_queue <int,vector<int>,greater<int>  > q;
int n;
int tmp;
int main(){
	freopen("in.txt","r",stdin);
	while(sf("%d",&n)!=EOF && n){
		while(!q.empty())
			q.pop();
		for(int i=0;i<n;i++){
			sf("%d",&tmp);
			q.push(tmp);
		}
		int sum=0;
		while(q.size()>1){
			int a=q.top();
			q.pop();
			int b=q.top();
			q.pop();
			q.push(a+b);
			sum+=a+b;
		}
		pf("%d\n",sum);
	}
	return 0;
}


