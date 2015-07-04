#define for if(0); else for 
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

struct  stu{
	char name[18];
	char gen[2];
	char id[18];
	int grade;
	bool operator <(const stu b)const{//operator是关键字
		//本身是蓝色的  如果不是的话就是拼写错了
		return grade>b.grade;
	}
};
vector<stu> v1,v2;
int N;

int main(){
	freopen("in.txt","r",stdin);   
	while (scanf("%d",&N)!=EOF){
		v1.clear();v2.clear();
		for(int i=0;i<N;i++){
			stu tmp;
			scanf("%s%s%s%d",tmp.name,tmp.gen,tmp.id,&tmp.grade);
			/* 开始的时候下面这句
			话我写成了 if(tmp.gen==“M")  然后发现
			v1根本不会执行任何的push_back原因是
			这里的tmp.gen是一个指针了 而不是字符串
			试问  两个指针的地址怎么可能相等 所以永远不会
			相等的  所以不能用那个  要改成strcmp函数才可以
			注意strcmp函数的写法*/
			if(strcmp(tmp.gen,"M")==0)
				v1.push_back(tmp);
			else 
				v2.push_back(tmp);
		}
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());	
		int lm=v1.size()-1,lf=v2.size()-1;
		if(v2.size()){
			printf("%s %s\n",v2[0].name,v2[0].id);
		}
		else printf("Absent\n");
		if(v1.size()){
			printf("%s %s\n",v1[lm].name,v1[lm].id);
		}
		else printf("Absent\n");
		if(v1.size()==0||v2.size()==0){
			printf("NA\n");
		}
		else {
			printf("%d\n",v2[0].grade-v1[lm].grade);
		}

	}
	return 0;
}

