#include <iostream>
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

int main(){
	
	multimap<int,int> mp;
	mp.insert(make_pair(112,1));
	mp.insert(make_pair(202,2));
	mp.insert(make_pair(12,3));
	mp.insert(make_pair(12,1));
	mp.insert(make_pair(18,2));
	mp.insert(make_pair(18,3));
	mp.insert(make_pair(18,1));
	mp.insert(make_pair(29,2));
	mp.insert(make_pair(29,3));
	multimap<int,int> ::iterator  it;
	for(it=mp.begin();it!=mp.end();it++){
		cout<<it->first;
		cout<<"  's the value is";
		cout<<it->second<<endl;
	}
	string a[20];
	gets(a[2]);
	for(int i=0;i<20;i++){
		a[i]="fuk it";
	}
	return 0;
}

