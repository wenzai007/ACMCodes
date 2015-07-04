//当然了 这道题 不用 大数类就行   但是我是为了巩固一下大数的编码
//  其实直接  算进位  和乘法就可以了   一位一位的乘法  因为只是乘以2  只要是10以内d
//乘法都可以用 一位一位的乘法  而不用像这里的  要4位4位的进行！！
//4位进行存储的话 最多只能乘以  10000以内的整数
#define for if(0);else for
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>>//有cmath 但是没有math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;
const int size=1000;

char instr[80];
char outstr[80];

int hash_in[12];
int hash_out[12];
struct big{
    int nums[size];
	int idx;
	void init(){
		for(int i=0;i<size;i++){
			nums[i]=0;
		}
		idx=0;
	}
	void output(){
		for(int i=idx-1;i>=0;i--){
			if(i==idx-1){
				printf("%d",nums[i]);
			}
			else {
				printf("%04d",nums[i]);
			}
		}
		printf("\n");
	}
	void set( char s[]){
		init();
		int L=strlen(s);
		int c=1,j=0;int sum=0;
		for(int i=L-1;i>=0;i--){
			sum+=(s[i]-'0')*c;
			j++;
			c*=10;
			if(j==4||i==0){
				nums[idx++]=sum;
				c=1;
				j=0;
				sum=0;
			}
		}

	}
	big  operator *(int x)const{//这个方法只能乘以最大的书
		big c;
		c.init();
		int carry=0;
		int sum=0;
		for(int i=0;i<idx;i++){
			sum=nums[i]*x+carry;
			carry=sum/10000;
			sum%=10000;
			c.nums[c.idx++]=sum;
		}
		if(carry!=0){
			c.nums[c.idx++]=carry;
		}
		return c;
	}

};
int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%s",instr)!=EOF){
		big a;
		a.set(instr);
		big b;
		b=a*2;
		for(int i=0;i<12;i++){
			hash_in[i]=0;
			hash_out[i]=0;
		}
		for(int i=0;i<strlen(instr);i++){
			hash_in[instr[i]-'0']++;
		}
		//很麻烦的对于 乘以2以后的结果数位拆解！！！
		int oidx=0;int thenum;
		for(int i=0;i<b.idx;i++){
			thenum=b.nums[i];
			do{
				outstr[oidx++]=thenum%10;
				hash_out[thenum%10]++;
				thenum/=10;
			}
			while(thenum);
		}
		if(oidx!=strlen(instr)){
			printf("No\n");
			b.output();
			continue;
		}
		bool flag=true;
		for(int i=0;i<10;i++){
			if(hash_in[i]!=hash_out[i])
				flag=false;
		}
		if(flag==false){
				printf("No\n");
			b.output();
		}
		else {
			printf("Yes\n");
			b.output();
		}

	}
	return 0;
}

