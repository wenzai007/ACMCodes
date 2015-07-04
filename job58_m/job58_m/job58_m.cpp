//我去  longlong  是 lld  long是ld！！否则scanf无法赋值！！
//ac  ！！  好爽！！
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
#define   mod_value   200907
int main(){
	freopen("in.txt","r",stdin);
	long long a,b,c,k,ans,q;
	int N;
	while (scanf("%d",&N)!=EOF&&N){
		while (N--!=0){
			ans=0;
			//scanf("%ld",&a);
			//scanf("%ld%ld%ld%ld",&a,&b,&c,&k);所有值被赋值成负值！！！
			scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
			if((b-a)==(c-b)){//a + (k-1)*d
				long long d=(b-a)%mod_value;
				k-=1;
				k%=mod_value;
				a%=mod_value;
				ans=a+k*d;
				ans%=mod_value;
			}
			else if(b/a==c/b){
				q=b/a;
				q%=mod_value;
				a%=mod_value;
				//k%=mod_value;k不能摸
				ans=1;
				k-=1;
				while(k){
					if(k%2==1){
						ans*=q;
						ans%=mod_value;
					}
					k/=2;
					q*=q;
					q%=mod_value;
				}
				ans*=a;
				ans%=mod_value;
			}
			printf("%lld\n",ans);
		}
		
	}
	return 0;
}
