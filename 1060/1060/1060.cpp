/*
  19/25
���Ե�	���	��ʱ(ms)	�ڴ�(kB)	�÷�/����
0	����ȷ	1	256	8/8
1	����ȷ	1	256	7/7
2	����ȷ	2	256	2/2
3	�𰸴���	2	376	0/2
4	�𰸴���	2	256	0/2
5	����ȷ	2	380	2/2
6	�𰸴���	2	376	0/2
ԭ��  ����Ȿ��û�и��ӵ��㷨��ֻҪ���Ǻü�
��case�ͺ��ˡ�1.����ǰ����0������ 5 003 032.�����
�������� 3 0.0000 00.03.ָ���ļ���Ҫ������ȫ.
*/
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
int n;
struct F{
	string ex;
	int index;
};
F getit(string a){//�����⴦��0
	F tmp;
	if(a=="0"){
		tmp.ex="0";tmp.index=0; return tmp;
	}
	if(a.find(".")==string::npos){
		int len=a.size();
		tmp.index=len;
		string np=a.insert(0,"0.");
		if(len>n){
			np=np.substr(0,n+2);
		}
		else{
			for(int i=1;i<=n-len;i++){
				np+="0";
			}
		}
		tmp.ex=np;
		return tmp;
	}
	else{//��С����
		int id=a.find(".");
		if(!(id==1&&a[0]=='0')){
			tmp.index=id;
			a.replace(id,1,"");
			a.insert(0,"0.");
			int len=a.size();//0.1234
			len-=2;
			if(len>n){
				a=a.substr(0,n+2);
			}
			else{
				for(int i=1;i<=n-len;i++){
					a+="0";
				}
			}
			tmp.ex=a;
			return tmp;
		}
		else {//0.xxxx
			int ix;
			for(ix=0;ix<a.size();ix++){
				if(a[ix]!='0'&&a[ix]!='.')
					break;
			}
			tmp.index=id-ix+1;//0.001  
			a.replace(0,ix-1,"0.");
			int len=a.size();
			len-=2;
			if(len>n){
				a=a.substr(0,n+2);
			}
			else{
				for(int i=1;i<=n-len;i++){
					a+="0";
				}
			}
			tmp.ex=a;
			return tmp;
		}
	}
}
char in1[108],in2[108];
int main(){
	freopen("in.txt","r",stdin);   
	while (scanf("%d%s%s",&n,in1,in2)!=EOF){
		string s1=in1;
		string s2=in2;
		F f1=getit(s1);
		F f2=getit(s2);
		if(f1.ex==f2.ex&&f1.index==f2.index){
			if(f1.ex=="0"){
				printf("YES 0 0\n");
				continue;
			}
			printf("YES %s*10^%d\n",f1.ex.c_str(),f1.index);
		}
		else{
			if(f1.ex=="0"){
				printf("NO 0 %s*10^%d\n",f2.ex.c_str(),f2.index);
				continue;
			}
			else if(f2.ex=="0"){
				printf("NO %s*10^%d 0\n",f1.ex.c_str(),f1.index);
				continue;
			}
			printf("NO %s*10^%d %s*10^%d\n",f1.ex.c_str(),f1.index,f2.ex.c_str(),f2.index);
		}
	}
	return 0;
}

