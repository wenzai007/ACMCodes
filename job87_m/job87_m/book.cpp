#include <stdio.h>
#include <queue>
using namespace std;
struct N { //״̬�ṹ��
	int a , b, c; //ÿ�������п��ֵ����
	int t; //�õ���������㵹����
};
queue<N> Q; //����
bool mark[101][101][101]; //������飨x��y��z�����б�ǣ���ֻ�е�һ�εõ���������飨x��y��z����״̬Ϊ��Ч״̬���������ȥ
void AtoB (int &a,int sa,int &b,int sb) { //�㵹����,���ݻ�Ϊsa�ı��ӵ����ݻ�Ϊsb�ı���,�������ò���a��b����ʼʱΪԭʼ�����п��ֵ������������������Ϻ�Ϊ���Ա��п��ֵ������
	if (sb - b >= a) { //��a����ȫ������b��
		b += a;
		a = 0;
	}
	else { //����
		a -= sb - b;
		b = sb;
	}
}
int BFS(int s,int n,int m) {
	while(Q.empty() == false) { //�����зǿ�ʱ,�ظ�ѭ��
		N now = Q.front(); //�ó���ͷ״̬
		Q.pop(); //������ͷ״̬
		int a , b , c; //a.b.c��ʱ�������������п������
		a = now.a;
		b = now.b;
		c = now.c; //������״̬���������п������
		AtoB(a,s,b,n); //��a�㵹��b
		if (mark[a][b][c] == false) { //�����������δ����
			mark[a][b][c] = true; //��Ǹ������
			N tmp;   
			tmp.a = a;
			tmp.b = b;
			tmp.c = c;
			tmp.t = now.t + 1; //�����µ�״̬
			if (a == s / 2 && b == s / 2) return tmp.t;
			if (c == s / 2 && b == s / 2) return tmp.t;
			if (a == s / 2 && c == s / 2) return tmp.t; //����״̬�Ѿ�Ϊƽ��״̬,��ֱ�ӷ��ظ�״̬�ĺ�ʱ
			Q.push(tmp); //����������
		}
		a = now.a;
		b = now.b;
		c = now.c; //����a.b.cΪδ�㵹ǰ�����
		AtoB(b,n,a,s); //b����a
		if (mark[a][b][c] == false) {
			mark[a][b][c] = true;
			N tmp;
			tmp.a = a;
			tmp.b = b;
			tmp.c = c;
			tmp.t = now.t + 1;
			if (a == s / 2 && b == s / 2) return tmp.t;
			if (c == s / 2 && b == s / 2) return tmp.t;
			if (a == s / 2 && c == s / 2) return tmp.t;
			Q.push(tmp);
		}
		a = now.a;
		b = now.b;
		c = now.c;
		AtoB(a,s,c,m); //a����c
		if (mark[a][b][c] == false) {
			mark[a][b][c] = true;
			N tmp;tmp.a = a;
			tmp.b = b;
			tmp.c = c;
			tmp.t = now.t + 1;
			if (a == s / 2 && b == s / 2) return tmp.t;
			if (c == s / 2 && b == s / 2) return tmp.t;
			if (a == s / 2 && c == s / 2) return tmp.t;
			Q.push(tmp);
		}
		a = now.a;
		b = now.b;
		c = now.c;
		AtoB(c,m,a,s); //c����a
		if (mark[a][b][c] == false) {
			mark[a][b][c] = true;
			N tmp;
			tmp.a = a;
			tmp.b = b;
			tmp.c = c;
			tmp.t = now.t + 1;
			if (a == s / 2 && b == s / 2) return tmp.t;
			if (c == s / 2 && b == s / 2) return tmp.t;
			if (a == s / 2 && c == s / 2) return tmp.t;
			Q.push(tmp);
		}
		a = now.a;
		b = now.b;
		c = now.c;
		AtoB(b,n,c,m); //b����c
		if (mark[a][b][c] == false) {
			mark[a][b][c] = true;
			N tmp;
			tmp.a = a;
			tmp.b = b;tmp.c = c;
			tmp.t = now.t + 1;
			if (a == s / 2 && b == s / 2) return tmp.t;
			if (c == s / 2 && b == s / 2) return tmp.t;
			if (a == s / 2 && c == s / 2) return tmp.t;
			Q.push(tmp);
		}
		a = now.a;
		b = now.b;
		c = now.c;
		AtoB(c,m,b,n); //c����b
		if (mark[a][b][c] == false) {
			mark[a][b][c] = true;
			N tmp;
			tmp.a = a;
			tmp.b = b;
			tmp.c = c;
			tmp.t = now.t + 1;
			if (a == s / 2 && b == s / 2) return tmp.t;
			if (c == s / 2 && b == s / 2) return tmp.t;
			if (a == s / 2 && c == s / 2) return tmp.t;
			Q.push(tmp);
		}
	}
	return -1;
}
int main () {
	freopen("in.txt","r",stdin);
	int s , n , m;
	while (scanf ("%d%d%d",&s,&n,&m) != EOF) {
		if (s == 0) break; //��sΪ0,��n.mΪ0���˳�
		if (s % 2 == 1) { //��sΪ�����򲻿���ƽ��,ֱ�����NO
			puts("NO");
			continue;
		}for (int i = 0;i <= s;i ++) {
			for (int j = 0;j <= n;j ++) {
				for (int k = 0;k <= m;k ++) {
					mark[i][j][k] = false;
				}
			}
		} //��ʼ��״̬
		N tmp;
		tmp.a = s;
		tmp.b = 0;
		tmp.c = 0;
		tmp.t = 0; //��ʼʱ״̬
		while(Q.empty() == false) Q.pop(); //��ն�����״̬
		Q.push(tmp); //����ʼ״̬�������
		mark[s][0][0] = true; //��ǳ�ʼ״̬
		int rec = BFS(s,n,m); //�����������
		if (rec == -1) //��Ϊ-1���NO
			puts("NO");
		else printf("%d\n",rec);//���������
	}
	return 0;
}