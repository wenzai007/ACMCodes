/*��������д��  ˵��  ֻ�е�һ�����ֵ�0�Ǳ���Ҫ
ȥ����  ����λ�õ�0 ���Ǳ���Ҫȥ���ģ���
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

const int size=100008;
int n;
char instr[10];
string buf[size];

bool cmp(const string &aa, const string &bb){
	string t1=aa+bb;
	string t2=bb+aa;
	return t1<t2;
}
int main(){
	freopen("in.txt","r",stdin);   
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%s",instr);
			buf[i]=instr;
		}
		sort(buf,buf+n,cmp);
		for(int i=0;i<n;i++){
			if(buf[i][0]=='0'){
				int dd;
				sscanf(buf[i].c_str(),"%d",&dd);
				printf("%d",dd);
			}
			else{
				printf("%s",buf[i].c_str());
			}
		}
		printf("\n");
	}
	return 0;
}

