#include <stdio.h>
#define N 10000001
int Tree[N];
int findRoot(int x) { //���ҽ��x�������ĸ����
	if (Tree[x] == -1) return x;
	else {
		int tmp = findRoot(Tree[x]);
		Tree[x] = tmp;
		return tmp;
	}
}
int sum[N]; //��sum[i]��ʾ�Խ��iΪ�������Ľ�����,���б������ݽ���Tree[i]Ϊ-1���ý��Ϊ���ĸ����ʱ��Ч
int main () {
	freopen("in.txt","r",stdin);
	int n;
	while (scanf ("%d",&n) != EOF) {
		for (int i = 1;i < N;i ++) { //��ʼ�������Ϣ
			Tree[i] = -1; //���н��Ϊ��������
			sum[i] = 1; //���м��ϵ�Ԫ�ظ���Ϊ1
		}
		while(n -- != 0) {
			int a , b;
			scanf ("%d%d",&a,&b);
			a = findRoot(a);
			b = findRoot(b);
			if (a != b) {
				Tree[a] = b;
				sum[b] += sum[a]; //�ϲ�����ʱ,����Ϊ���������ĸ�����ϱ���ĸü���Ԫ�ظ����������ۼӵ��ϲ�������������
			}
		}
		int ans = 1;//��,������Ϊ1���������ȳ���ʼ��Ϊ1
		for (int i = 1;i <= N;i ++) {
			if (Tree[i] == -1 && sum[i] > ans) ans = sum[i]; //ͳ�����ֵ
		}
		printf("%d\n",ans); //���
	}
	return 0;
}