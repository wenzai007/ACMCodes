
/*感谢各位童鞋的指点，说一下这个题目的坑爹的地方所在：
  1.   0.0+0.0=0.0
  2.   00007.1+0.9=8.0
  3.   7.000000+8.0=15.0
  4.   8.00001+1.99999=10.0 
  希望A这个题目的童鞋不要再纠结。。。。。。。
  */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
int n;
char a[108],b[108];
char c_frac[100];
char c_int[100];
int size_c_frac;
int size_c_int;

int a_len,b_len;
int a_dot,b_dot;

void process_ab(){
	int a_frac_len=a_len-a_dot;
	int b_frac_len=b_len-b_dot;
	int dif=abs(a_frac_len-b_frac_len);
	int idx;
	if(a_frac_len>b_frac_len){
		for(idx=b_len;idx<b_len+dif;idx++){
			b[idx]='0';
		}
		b[idx]=0;
	}
	else if(a_frac_len<b_frac_len){
		for(idx=a_len;idx<a_len+dif;idx++){
			a[idx]='0';
		}
		a[idx]=0;
	}
}
void process_c (){
	int fra_len_con=strlen(a)-a_dot;
	int carry=0;
	int carry_int=0;
	size_c_frac=0;
	size_c_int=0;
	for(int i=strlen(a)-1,j=strlen(b)-1;i>a_dot&&j>b_dot;i--,j--){
		int each_d=a[i]-'0'+b[j]-'0'+carry;
		carry=each_d/10;
		c_frac[size_c_frac++]=each_d%10+'0';
	}
	if(carry!=0)  carry_int=carry;
	int i,j;
	for(i=a_dot-1,j=b_dot-1;i>=0&&j>=0;i--,j--){
		int each_d=a[i]+b[j]-'0'-'0'+carry_int;
		carry_int=each_d/10;
		c_int[size_c_int++]=each_d%10+'0';
	}
	while(i>=0){
		int each_d=a[i]-'0'+carry_int;
		carry_int=each_d/10;
		c_int[size_c_int++]=each_d%10+'0';
		i--;
	}
	while (j>=0){
		int each_d=b[j]-'0'+carry_int;
		carry_int=each_d/10;
		c_int[size_c_int++]=each_d%10+'0';
		j--;
	}
	if(carry_int>0){
		c_int[size_c_int++]=carry_int+'0';
	}
}


int main(){
	freopen("in.txt","r",stdin);
	while (scanf("%d",&n)!=EOF){
		//*
		while (n--!=0){
			scanf("%s%s",a,b);
			memset(c_frac,0,sizeof(c_frac));
			memset(c_int,0,sizeof(c_int));
			a_len=strlen(a); b_len=strlen(b);
			for(int i=0;i<a_len;i++){
				if(a[i]=='.') {
					a_dot=i;break;
				}
			}
			for(int i=0;i<b_len;i++){
				if(b[i]=='.'){
					b_dot=i;break;
				}
			}
			process_ab();
			process_c();
			int first=0;
			for(int k=size_c_int-1;k>=0;k--){
				if(c_int[k]!='0') {
					first=k;
					break;
				}
			}
			for(int k=first;k>=0;k--){
				printf("%c",c_int[k]);
			}
			printf(".");
			int last=size_c_frac-1;
			for(int k=0;k<size_c_frac;k++){
				if(c_frac[k]!='0'){
					last=k;
					break;
				}
			}
			for(int k=size_c_frac-1;k>=last;k--){
				printf("%c",c_frac[k]);
			}
			printf("\n");
		}
		//*/
	}
	return 0;
}

