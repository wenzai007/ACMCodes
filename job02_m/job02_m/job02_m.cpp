#include<stdio.h>
#include<algorithm>
#include<string.h>  //此处不确定到底是cstring还是什么对了  string头文件里有strcmp函数！
using namespace std;
int n;

struct student{
	int age,achieve;
	char name[101];
	//*sta
	bool operator < (const student &b) const {
		if(achieve!=b.achieve){
			return achieve<b.achieve;
		}
		else if(strcmp(name,b.name)!=0)
			return strcmp(name,b.name)<0;
		else return age<b.age;
	}
	//end */
}stu[1002];

   /*
bool cmp(student a, student b) {
		if(a.achieve!=b.achieve){
			return a.achieve<b.achieve;
		}
		else if(strcmp(a.name,b.name)!=0)
			return 
			strcmp(a.name,b.name)<0;
		else return a.age<b.age;
}
   //end*/


int main(){
	while (scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%s",stu[i].name);//not sure  of the wring of it???
			scanf("%d",&stu[i].age);
			scanf("%d",&stu[i].achieve);
		}
		sort(stu,stu+n);
		for(int i=0;i<n;i++){
			printf("%s %d %d\n",stu[i].name,stu[i].age,stu[i].achieve);
			
		}
	}
	return 0;
}
