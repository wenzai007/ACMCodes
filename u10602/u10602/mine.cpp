//̫���� ��һ�ξ�ac�������  �о���ˬ����
//�������������� compare�������   Ҫѧ�����ʹ�õķ�������
//�Զ���һ���ȽϺ�����  Ȼ������������������캯����
//��������Զ���ĺ�������ʹ��������ƣ���

#define for if(0); else for 
#define pf printf
#define sf  scanf
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>//��cmath ����û��math

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
            return equalnum(a,c)<equalnum(b,c);//Ϊ��������������������Ҫ��
          }
};


/*
bool mycmp(string a,string b,string c){
	return equalnum(a,c)>equalnum(b,c);//Ϊ��������������������Ҫ��
}
*/
int main(){
	freopen("in.txt","r",stdin);   
	sf("%d",&c_num);
	
	while (c_num--){
		v1.clear();v2.clear();
		sf("%d",&w_num);
		gets(ins);
		gets(ins);//��һ�� �ַ���
		string nowp=ins;
		v2.push_back(nowp);
		for(int i=0;i<w_num-1;i++){//ʣ�µ�w_num-1��
			gets(ins);
			tmp=ins;
			v1.push_back(tmp);
		}
		int tol=nowp.size();
		while (!v1.empty()){
			sort(v1.begin(),v1.end(),cpae(nowp));//����ǹؼ�
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

