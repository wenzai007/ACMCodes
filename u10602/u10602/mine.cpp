//太好了 我一次就ac了这道题  感觉真爽！！
//并且灵活的运用了 compare这个函数   要学会这个使用的方法！！
//自定义一个比较函数类  然后第三个参数用作构造函数！
//并且这个自定义的函数可以使任意的名称！！

#define for if(0); else for 
#define pf printf
#define sf  scanf
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>//有cmath 但是没有math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;


int c_num,w_num;
char ins[108];
string tmp;
vector<string> v1;
vector<string> v2;


int equalnum(string a,string b){
	int lena=a.size();int lenb=b.size();
	int k=0;
	int sum=0;
	while(k<lena && k<lenb){
		if(a[k]==b[k]){
			sum++;
			k++;
		}
		else break;
	}
	return sum;
	
}
class cpae
{
      private:
            string c;
      public:
            cpae(string cc):c(cc) {};
      bool operator () (string a,string b) 
         {
            return equalnum(a,c)<equalnum(b,c);//为了让最后的数字是我们想要的
          }
};


/*
bool mycmp(string a,string b,string c){
	return equalnum(a,c)>equalnum(b,c);//为了让最后的数字是我们想要的
}
*/
int main(){
	freopen("in.txt","r",stdin);   
	sf("%d",&c_num);
	
	while (c_num--){
		v1.clear();v2.clear();
		sf("%d",&w_num);
		gets(ins);
		gets(ins);//第一个 字符串
		string nowp=ins;
		v2.push_back(nowp);
		for(int i=0;i<w_num-1;i++){//剩下的w_num-1个
			gets(ins);
			tmp=ins;
			v1.push_back(tmp);
		}
		int tol=nowp.size();
		while (!v1.empty()){
			sort(v1.begin(),v1.end(),cpae(nowp));//这个是关键
			string bestfit=v1.back();
			v1.pop_back();
			int pp=bestfit.size();
		    int ppp=equalnum(bestfit,nowp);
			tol+=(bestfit.size()-equalnum(bestfit,nowp));
			v2.push_back(bestfit);
			nowp=bestfit;
		}
		pf("%d\n",tol);
		for(int i=0;i<v2.size();i++){
			pf("%s\n",v2[i].c_str());
		}
	}
	return 0;
}

