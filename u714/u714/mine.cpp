/*���������ֵ��С����8.3.5�����  ����һģһ��  ���ֵ�ϸ��  ��ϸ���Ϳ��Կ�8.3.5 
 * Ҫ�������
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

int book[508];
int  outpos[508];
int b_num,p_num;

bool cansplit(long long x ){//һ�� ���ֵĻ���Ҫ��Ҫ��bool�͵ı���
	long long sum=0;
	int t=0;//һ����Ҫ�����ָ���  ��Ȼ��p_num-1 ����
	for(int i=b_num-1;i>=0;i--){
		sum+=book[i];
		if(sum>x){
			sum=book[i];
			t++;
		}
		if(t>p_num-1)
			return false;
	}
	return true;
}

int main(){
	freopen("in.txt","r",stdin);   
	int c_num;
	sf("%d",&c_num);

	while (c_num--){
		sf("%d%d",&b_num,&p_num);
		for(int i=0;i<b_num;i++){
			sf("%d",&book[i]);
		}
		long long maxofthem=0,sumofthem=0;
		for(int i=0;i<b_num;i++){
			if(maxofthem<book[i])
				maxofthem=book[i];
			sumofthem+=book[i];
		}
		long long l,r,mid;
		l=maxofthem;r=sumofthem;
		while(l<r){//�˴����ֵ�ϸ��Ҫ�����������
			mid=(l+r)/2;
			if(cansplit(mid))//r��ֵʼ���ǿ�������cansplit�ģ�
				r=mid;
			else
				l=mid+1;
		}
		//����l��ֵ���ǿ��Ե���С��ֵ
		long long msum=0;
		int splitnum=0;
		memset(outpos,0,sizeof(outpos));
		for(int i=b_num-1;i>=0;i--){
			msum+=book[i];
			if(msum>l){
				msum=book[i];
				outpos[i]=1;
				splitnum++;
			}
		}
		if(splitnum<p_num-1){
			for(int i=0;i<b_num;i++){
				if(outpos[i]==1)//�˴�����Ҫ�ģ������֮ǰ��б���ظ���
								//��ô��Ҫ������һ���µ�б�ܣ�����Ļ�
								//������100/100 100/100 100�����
								//��ȷӦ��100/100/100/100 100
					continue;
				outpos[i]=1;
				splitnum++;
				if(splitnum==p_num-1)
					break;
			}
		}
		for(int i=0;i<b_num-1;i++){
			pf("%d ",book[i]);
			if(outpos[i])
				pf("/ ");
		}
		pf("%d\n",book[b_num-1]);
		
	}
	return 0;
}

