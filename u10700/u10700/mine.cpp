//��һ���ύ  wa
//̰�ġ����ȼӺ��Ϊ����ȳ˺��Ϊ��С�����и�ע������12������ÿ�������20������Ҫ��long long��ȻWA��
//Ȼ�� ����֮��һֱ����ac  ��wa  Ϊʲô��   ԭ������Ϊ�Ǹ� ��������� ���Ǵ���֮����������ǲ�����
//�Ǹ�int�����ͣ���Ҫ�ĳ�  long long �����Ͳſ��Ե�  
//�����ҷ�����Ȼ���һ����scanf("%c",&op)==EOF ������Ȼ�ǿ���д��'\n'�� Ҳ����˵������ú��鷳��
//�Ǹ����⴦�� ���ո���  ==EOF ��ʵ���Բ������⴦���ֱ��д��=='\n' ��Ȼ��vs���治�У�����ȷʵ����
//��oj��ac���������һ���ַ�Ҳ��������Ϊ'\n'���ַ�
//Ҳ�ǶԵ�  ��һ�������Լ���д��  Ȼ��������ϵķ��ֺ��ҵ�˼·��һ���ģ������˼ҵ��Ǹ�ȴ�ǳ��Ķ� ��Ϊû�б�Ҫд����������  ռ����ô����  ���ǿ���д��һ����������ģ�����ȫ
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
int n;
int id=0;
char op;

long long   ins[80];
long long  deal[80];//��int ��Ϊlong long 


long long  domax(){
	long long  sum=0;
	int nnum;
	int rnum;
	int dealid=0;
	char maxop;
	for(int i=0;i<id-1;i+=2){
		nnum=ins[i];
		if(ins[i+1]==-3){//�˳���ʱ��
			sum+=nnum;
			deal[dealid++]=sum;
			break;
		}
		else if(ins[i+1]==-1){
			sum+=nnum;
		}
		else if(ins[i+1==-2]){
			sum+=nnum;
			deal[dealid++]=sum;
			sum=0;
		}
	}
	long long  res=1;
	for(int i=0;i<dealid;i++){
		res*=deal[i];
	}
	return res;
}


long long  domin(){
	long long  sum=1;//�ó˷�
	int nnum;
	int dealid=0;
	char minop;
	for(int i=0;i<id-1;i+=2){
		nnum=ins[i];
		if(ins[i+1]==-3){
			sum*=nnum;
			deal[dealid++]=sum;
			break;
		}
		else if(ins[i+1]==-1){//�ӷ�
			sum*=nnum;
			deal[dealid++]=sum;
			sum=1;
		}
		else if(ins[i+1==-2]){//�˷�
			sum*=nnum;
		}
	}
	long long  res=0;
	for(int i=0;i<dealid;i++){
		res+=deal[i];
	}
	return res;
}


int main(){
	freopen("in.txt","r",stdin);   
	sf("%d",&n);
	while(n--){
		while(true){
			scanf("%d",&ins[id++]);
			scanf("%c",&op);
			//if(scanf("%c",&op)!=EOF){
				if(op=='\n'){
					ins[id++]=-3;// ���������
					long long  mymax=domax();
					long long  mymin=domin();
					pf("The maximum and minimum are %lld and %lld.\n",mymax,mymin);
					id=0;
					break;
				}
				else if (op=='+'){
					ins[id++]=-1;//-1 is �ӷ�
				}
				else if(op=='*'){
					ins[id++]=-2;// -2 is �˷�
				}
			//}
			/*else{
				ins[id++]=-3;// ���������
				long long  mymax=domax();
				long long  mymin=domin();
				pf("The maximum and minimum are %lld and %lld.\n",mymax,mymin);
				id=0;
				break;

			}
			*/
		}
	}
	return 0;
}

