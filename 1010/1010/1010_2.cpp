//  ֻ��20�֣������ ������һ�� ����  Ϊʲô����
// ��Ϊ��û�п��� radixΪ1 ���������
//ʲôjb  �����Ͳ����ǻ��� ����֮��һ����20�֣�
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
//#include< time.h>!!!patϵͳ˵��û�����ͷ�ļ�  ������ĺ��ϸ񰡶�һ���ո񶼲��У���
#include <time.h>
using namespace std;


char s1[12],s2[12];
int id1,id2;
int tag,radix;

//int get_value(int r,int a[],int id ){//�������İ�char
int get_value(int r,char a[],int id ){
	int total=0;
	int w=1;
	for(int i=id-1;i>=0;i--){
		int d;
		if(a[i]<='9'&&a[i]>='0'){
			d=a[i]-'0';
		} 
		else d=a[i]-'a'+10;
		if(d>=r) return -1;
		total+=w*d;
		//w*=w;���������  w*=r;!!
		w*=r;
	}
	return total;

}

int main(){
	freopen("in.txt","r",stdin);
	//	srand(time(0));
	//	int r=rand();
	while(scanf("%s%s%d%d",s1,s2,&tag,&radix)!=EOF){
		bool find=false;
		int i;
		int ans;
		int sum1=0,sum2=0;
		id1=strlen(s1),id2=strlen(s2);
		if(tag==1){
			sum1=get_value(radix,s1,id1);
			if(id1>=id2){
			//	for(i=radix;i<=36;i++){
				for(i=1;i<=36;i++){
					int syx=get_value(i,s2,id2);
					if(syx==-1){
						continue;
					}
					if(syx==sum1){
						find=true;
						ans=i;
						break;
					}
				}
			}
			else {
				for(int i=1;i<radix;i++){
					int syx=get_value(i,s2,id2);
					if(syx==-1){
						continue;
					}
					if(sum1==syx){
						find=true;
						ans=i;
						break;
					}
				}
			}
		}
		else if(tag==2){
			sum2=get_value(radix,s2,id2);
			if(id1>=id2){
          		for(i=1;i<=radix;i++){
					int syx=get_value(i,s1,id1);
					if(syx==-1){
						continue;
					}
					if(syx==sum2){
						find=true;
						ans=i;
						break;
					}
				}
			}
			else{
				for(i=radix+1;i<=36;i++){
					int syx=get_value(i,s1,id1);
					if(syx==-1){
						continue;
					}
					if(syx==sum2){
						find=true;
						ans=i;
						break;
					}
				}
			}
		}
		if(find==true) printf("%d\n",ans);
		else printf("Impossible\n");
	}
	return 0;
}

