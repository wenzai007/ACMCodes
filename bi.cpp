#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<list>
#include<iomanip>
#include<set>
#include<deque>
#include<stack>
#include<functional>
#include<numeric>
#include<utility>

#include<iostream>
#include<string>
#include<math.h>
#include<queue>
#include<vector>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;

#define vint vector <int>
#define vstring vector <string>
#define ff(i,n) for (i=0; i<n; i++)
#define pb(a,b) a.push_back(b)
#define ma 100000000
#define maxn 1000000
#define sort1(a) sort(a.begin(),a.end(),f1)
#define sort2(a) sort(a.begin(),a.end(),f2)

vint d[maxn+2] , ans[maxn+2] , xu;
int dn[maxn+2] , low[maxn+2] , n , tol , stk[maxn+2] , tolans , tolstk;

bool f1(int p , int q) {
	return p<q;
}

bool f2(int p , int q) {
	return ans[p].size()<ans[q].size();
}

void init() {
	int i , x , y , j;
	string s;
	cin >> n;
	ff(i,n) d[i].clear();
	while (cin >> s) {
		ff(j,s.length()) if ((s[j]=='(')||(s[j]==')')||(s[j]==',')) s[j]=' ';
		stringstream ss(s);
		ss >> x >> y;
		pb(d[x],y);
		pb(d[y],x);
	}
	memset(dn,0,sizeof(dn));
	memset(low,0,sizeof(low));
	tol=tolans=tolstk=0;
}

void dfs(int p , int fa) {
	tol++;
	low[p]=dn[p]=tol;
	tolstk++;
	stk[tolstk]=p;
	int i , j , k=d[p].size() , ne;
	ff(i,k) if (d[p][i]!=fa) {
		if (dn[d[p][i]]!=0) {
			if (low[p]>dn[d[p][i]]) low[p]=dn[d[p][i]];
		}
		else {
			ne=d[p][i];
			dfs(ne,p);
			if (low[ne]>=dn[p]) {
				while (1) {
					pb(ans[tolans],stk[tolstk]);
					tolstk--;
					if (stk[tolstk+1]==ne) break;
				}
				pb(ans[tolans] , p);
				tolans++;
			}
			if (low[ne]<low[p]) low[p]=low[ne];
		}
	}
}

void outit() {
	int i , j , k;
	ff(i,tolans) pb(xu,i);
	sort2(xu);
	ff(i,xu.size()) cout << xu[i] << ' ' << d[xu[i]].size() << endl;
	cout << endl;
	ff(i,tolans) {
		sort1(ans[xu[i]]);
		ff(j,ans[xu[i]].size()) cout << ans[xu[i]][j] << ' ';
		cout << endl;
	}
}
void outit2() {
	int i , j , k;
	ff(i,tolans) pb(xu,i);
	sort2(xu);
	ff(i,tolans) {
		sort1(ans[i]);
		ff(j,ans[i].size()) cout << ans[i][j] << ' ';
		cout << endl;
	}
}

int main() {
	freopen("in.txt" , "r" , stdin);
	int i , j , k , n , m;
	init();
	dfs(0,0);
	outit();
	return 0;
}