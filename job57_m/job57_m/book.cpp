#include <stdio.h>
int main () {
	freopen("in.txt","r",stdin);
	int a , b;
	while (scanf ("%d%d",&a,&b) != EOF) {
		if(a == 0 && b == 0) break; 
		int ans = 1; //������
		while(b != 0) { //��b��Ϊ0������bת
			if (b % 2 == 1) { //����ǰ������2^k��Ϊ��ǰ����
				ans *= a; //��
				ans %= 1000; //�������λ�� 
			}
			b /= 2; //b����2
			a *= a; //����һλ������λ��Ȩ�أ�a����ƽ��������a��1�ο�ʼ
			a%=1000;
		}
		printf("%d\n",ans);
	}
	return 0;
}