//@1 wa ��������ʲôԭ�򡣡��� 
//@2	Main.cpp
//F:\temp\12976163.31208\Main.cpp(71) : fatal error C1071: unexpected end of ///file found in comment �走  ���������ע��ɾ�� �ͺ���  AC �� �����������ע��shit  �Ժ�ע�Ͷ�д��������

#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>
 
#include<queue>
#include<stack>
#include<vector>
#include<map>
using namespace std;


struct node{
	double a,b;
	bool operator <(const node bb)const{
		return a<bb.a;
	}
	
}buf[1008];

int n,d,x,y;
int cnt=0;
bool flag;
int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%d%d",&n,&d)!=EOF){
		if(!n&&!d)
			break;
		cnt++;
		flag=false;

		for(int i=0;i<n;i++){
			scanf("%d%d",&x,&y);
			if(d<abs(y)){
				flag=true;
				//break;!!!@1�����ԭ������wa�� ��  ��Ϊ������break��
//����Ļ��ͻ��������ģ�break֮���������ݲ����� Ȼ��ֱ�Ӷ���һ��n ��d//��ֵ����ȴ�� x y�����������n��d��ֵ�ˡ�������  ���Բ���break
			}
			double yy=abs(y);
			buf[i].a=(double)x-sqrt(d*d-yy*yy);
			buf[i].b=(double)x+sqrt(d*d-yy*yy);

		}
		if(flag==true){
			printf("Case %d: -1\n",cnt);
			continue;//@!���������ǿ���continue�ģ�
		}
		int ans=1;//���ٵ�ǰ�����Ҫ���� Ȼ��ӵڶ�����ʼ��� 
		sort(buf,buf+n);
		double right=buf[0].b;
		for(int i=1;i<n;i++){
			if(buf[i].a>right){//right �ǵ�ǰ��������ܽ������״����ұߵĵ�
				ans++;
				right=buf[i].b;
				continue;
			}
			if(buf[i].b<right){
				right=buf[i].b;//��Ϊֻ���������ܹ�ʹ�õ�ǰ���״︲�ǵ����еĵ�
			}
		}
		printf("Case %d: %d\n",cnt,ans);
	}

	return 0;
}
//@1 wa ��������ʲôԭ�򡣡��� 
//@2	Main.cpp
//F:\temp\12976163.31208\Main.cpp(71) : fatal error C1071: unexpected end of ///file found in comment �走  ���������ע��ɾ�� �ͺ���  AC �� �����������ע��shit