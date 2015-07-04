#include <stdio.h>
int main () {
	freopen("in.txt","r",stdin);
	int a , b;
	while (scanf ("%d%d",&a,&b) != EOF) {
		if(a == 0 && b == 0) break; 
		int ans = 1; //保存最
		while(b != 0) { //若b不为0，即对b转
			if (b % 2 == 1) { //若当前二进制2^k次为当前二进
				ans *= a; //最
				ans %= 1000; //求其后三位数 
			}
			b /= 2; //b除以2
			a *= a; //求下一位二进制位的权重，a求其平方，即从a的1次开始
			a%=1000;
		}
		printf("%d\n",ans);
	}
	return 0;
}