//不知道现行查找的话会不会超时的呢？算了 直接二分查找吧
//1.提交的时候是wa  尼玛#ifndef!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//2.并且如果名字开到50 而不是100的话  那么就是runtime error！！sb
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
#define  ONLINE    1
int N,M;
struct student{
	//int num;  写错了  不应该是int 型 无法输出了   
	//英爱是char [] 行    不管你是什么格式我就是按照你的输入形式
	//进行输出@@   恩 
	char num[100];
	char name[100];
	char gender[10];
	int age;
	bool operator <(student const b) const{//这样写对么
		return strcmp(num,b.num)<0;
	}
}buf[1002];
int binarySearch(char x[]){
   int left=0;int right=N-1;
	int middle=(left+right)/2;
	while (left<=right){
		int restmp=strcmp(buf[middle].num,x);
		if(restmp==0)return middle;
		else if(restmp<0)left=middle+1;
		else right=middle-1;//然后所有情况考虑完了之后
		                    //不管怎样 都要执行下一句！
		middle=(left+right)/2;
	}
	if(left>right) return -1;

}
int main(){
#ifndef ONLINE
	freopen ("in.txt","r",stdin);
#endif
	
	int age;
	char num[100];
	char name [100];
	char gender[10];
	int i;
	while (scanf("%d",&N)!=EOF&&N){
		for(i=0;i<N;i++){
			scanf("%s%s%s%d",num,name,gender,&age);
  /*		
			buf[i].num=num;//字符数组可以这样赋值么？？不可以
			               //数组的地址是不可以改变的！！
			buf[i].name=name;
			buf[i].gender=gender;
			buf[i].age=age;
  */
			strcpy(buf[i].num,num);
            strcpy(buf[i].name,name);
			strcpy(buf[i].gender,gender);
			buf[i].age=age;
		}
		sort(buf,buf+N);
		scanf("%d",&M);
		for(i=0;i<M;i++){
			scanf("%s",num);
			int tt=binarySearch(num);
			if (tt==-1)printf("No Answer!\n");
			else{
				printf("%s %s %s %d\n",buf[tt].num,buf[tt].name,buf[tt].gender,buf[tt].age);
				
			}
		}


	}
	return 0;//又忘了！！
}








//for the middle effect
