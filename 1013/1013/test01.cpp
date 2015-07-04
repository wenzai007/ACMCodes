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
using namespace std;
vector<int> v;
map<string,int> theMap;
string a="aaa"; string b="bbb";string c="ccc";
// add something to theMap...




int main(){
	theMap[a]=7;
	theMap[b]=8;
	theMap[c]=9;
	double b=1.233333;
	v.push_back(8);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	vector<int>::iterator it;
	vector<int>::iterator iq;
	for(map<string,int>::iterator iter1 = theMap.begin(); iter1 != theMap.end(); )
	{
		if(iter1->second == 8)
		{
			iter1=theMap.erase(iter1); //#1 
		}else
		{
			++iter1;
		}
	} 

	//*
	for(it=v.begin();it!=v.end();){
		if(*it==2){
			//iq=it;
			it=v.erase(it);
			//it=iq;
			continue;
		}
		it++;
	}
	//*/
	/*
	for(int i=0;i<v.size();){
	if(v[i]==2){
	//	iq=it+1;
	v.erase(v.begin()+i);

	//it=iq;
	continue;
	}
	i++;
	}
	//*/
	int arr[10];
	int ss=sizeof(arr);
	int sss=sizeof(int);
	return 0;
}

