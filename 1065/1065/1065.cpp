//��ʼ  ֻ��12��     ԭ��  1  û����  tmp�洢 
// 2   �жϵ�ʱ��û����<=0  ��ֻ��<0 ���е�
#define for if(0); else for 
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
long long a,b,c,tmp;
int n;
int main(){
	freopen("in.txt","r",stdin);   
	//a=(long long)pow(2.0,63)-1;
	while (scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a,&b,&c);
			tmp=a+b;
			printf("Case #%d: ",i);
			//if(a>0&&b>0&&tmp<0){//�� ����ְ� ��tmp�ͶԲ��þ�
				//����
			if(a>0&&b>0&&tmp<=0){
				printf("true\n");
				continue;
			}
			//if(a<0&&b<0&&tmp>0){
			if(a<0&&b<0&&tmp>=0){
				printf("false\n");//����һ��continue 12��
				//��������˰��Сʱ
				continue;
			}
			if(tmp>c)
				printf("true\n");
			else
				printf("false\n");
		}
	}
	return 0;
}

