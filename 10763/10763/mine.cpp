//ڤ˼�����˺þ�  ���ڸ����˳����ˣ���������
//��������Ĺ�����������  ���Ȱ���a b �ĺ����� ������ ��ô����a-b�ľ���ֵ����
//��������Ψһ��ȷ���Ƿ���  ��ȫ��ȵ��� ��Ϊ  ��������Ψһȷ��������
//����˵��a+b=x a-b=y or  a+b=x a-b=-y  ��ôa b Ψһȷ��   ����a bֵ���� ������ν�ģ�
//Ȼ�����һ�¼��� 
//�����ҵ������Ǵ����   tle��    ��ʱ  ������O��n����  ����
//��ȷ�ķ�������map  ������ǲ���ÿ��pair ��������0 �ǵĻ���ô��
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
struct stu{
	int a,b;
	bool operator <(const stu &B)const{
		if((a+b)!=(B.a+B.b)){
			return (a+b)<(B.a+B.b);
		}
		else
			return abs(a-b)<abs(B.a-B.b);
	}
}buf[500008];
int n;
int main(){
	freopen("in.txt","r",stdin);   
	while(scanf("%d",&n)&&n){
		if(n%2!=0){
			printf("NO\n");
			continue;
		}
		for(int i=0;i<n;i++){
			scanf("%d%d",&buf[i].a,&buf[i].b);
		}
		sort(buf,buf+n);
		bool flag=true;
		for(int i=0;i<n;i+=2){
			if((buf[i].a+buf[i].b)!=(buf[i+1].a+buf[i+1].b)||(buf[i].a-buf[i].b)!=(buf[i+1].b-buf[i+1].a)){
				flag=false;
				break;
			}
		}
		if(flag==true){
			printf("YES\n");
		}
		else
			printf("NO\n");
	}
	return 0;
}

