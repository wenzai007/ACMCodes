//wa һ��  Ȼ��   ����mû��clear���� �ĺ�ac
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


map< pair<int,int>,int > m;
map< pair<int,int>,int >::iterator it;

int n;
int a,b;
bool isok(){
	for(it=m.begin();it!=m.end();it++){
		if(it->second!=0){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("in.txt","r",stdin);   
	while(scanf("%d",&n)&&n){
		m.clear();
		if(n%2!=0){
			for(int i=0;i<n;i++){
				scanf("%d%d",&a,&b);
			}
			printf("NO\n");
			continue;
		}
		for(int i=0;i<n;i++){
			scanf("%d%d",&a,&b);
			a<b? ++m[make_pair(a,b)]:--m[make_pair(b,a)];//�ܾ����д������˵���㷨 ��������
			//��ֻ֤����һ�� Ȼ�󿴳��Ƿ�ƥ�� ��ס������
		}
		if(isok())
			printf("YES\n");
		else 
			printf("NO\n");

	}
	return 0;
}
