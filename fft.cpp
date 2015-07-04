#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

#define ff(i,n) for (i=0; i<n; i++)
#define pi 3.1415926535897932384626433839
#define maxn 1000000

struct cp {
	double r , i;
	cp operator + (const cp & jia) {
		cp res;
		res.r = r + jia.r;
		res.i = i + jia.i;
		return res;
	}
	cp operator - (const cp & jian) {
		cp res;
		res.r = r - jian.r;
		res.i = i - jian.i;
		return res;
	}
	cp operator * (const cp & che) {
		cp res;
		res.r = r*che.r-i*che.i;
		res.i = i*che.r+r*che.i;
		return res;
	}	
	cp(double rr , double ii) {
		r=rr;
		i=ii;
	}
	cp(double p) {
		p=2*pi/p;
		r=cos(p);
		i=sin(p);
	}
	cp() {
	}
};

cp a[maxn] , b[maxn] , c[maxn] , d[maxn];	//a : 系数 b : 总结果暂存 c : 分结果暂存 d : find总结果 
int n;

void find(int st , int bu , int len , int dr) { //从st位置开始，步长bu , 步数len , 单位e的方向dr
	int i , j , k;
	if (len==1) {
		d[st]=a[st];
		return ;
	}
	find(st,bu*2,len/2,dr);
	find(st+bu,bu*2,len/2,dr);
	cp u(1,0);
	cp dlt(dr*len);
	k=len/2*bu;
	for (i=1; i<=len/2; i++) {
		c[st+(i-1)*bu]=d[st+(i-1)*bu*2]+u*d[st+(i-1)*bu*2+bu];
		c[st+(i-1)*bu+k]=d[st+(i-1)*bu*2]-u*d[st+(i-1)*bu*2+bu];
		u=u*dlt;
	}
	for (i=1; i<=len; i++) d[st+bu*(i-1)]=c[st+bu*(i-1)];
}

int main() {
	freopen("in.txt" , "r" , stdin);
	int i , j , k;
	cin >> n;
	n++;
	for (i=1; i<=n; i++) {
		scanf("%d" , &k);
		cp t(k,0);
		a[n+1-i]=t;
		cp t1(0,0);
		a[i+n]=t1;
	}
	n*=2;
	find(1,1,n,1);
	for (i=1; i<=n; i++) b[i]=d[i];
	n/=2;
	for (i=1; i<=n; i++) {
		scanf("%d" , &k);
		cp t(k,0);
		a[n+1-i]=t;
		cp t1(0,0);
		a[i+n]=t1;
	}
	n*=2;
	find(1,1,n,1);
	for (i=1; i<=n; i++) a[i]=b[i]*d[i];
	find(1,1,n,-1);
	for (i=1; i<n; i++) printf("%.0lf " , d[i].r/n);
	cout << endl;
	return 0;
}


