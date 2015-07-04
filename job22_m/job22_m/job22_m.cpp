//第一次结果不对   应该是5  但是我的是3  原因是28行

#include<algorithm>
#include<string.h>
#include <stdio.h>
using namespace std;
//int buf[108][2];//这一次我不用结构体了 改用二维数组
//貌似不行   二维数组的话 没有办法按照第二维的大小进行排序
//还得用结构体@@@！！
struct shows{
	int start;
	int end;
	bool operator <(const shows b)const {
		return end<b.end;
	}
}buf[108];
int n;
int main(){
	//freopen("in.txt","r",stdin);
	while (scanf("%d",&n)!=EOF&&n){
		for(int i=0;i<n;i++){
			scanf("%d%d",&buf[i].start,&buf[i].end);//以前为什么还要多此一举的使用哪个透明片、变量？？？
		}//又一次忘记加上&  累计！！！！好多好多次啦
		sort(buf,buf+n);//n个结构体
		int cnt=1;//记录一共有几个节目
		int endline=buf[0].end;
		for(int i=1;i<n;i++){
		//	if(buf[i].start>endline){ //!!!!这里错了 应该大于等于
			if(buf[i].start>=endline){
				cnt++;
				endline=buf[i].end;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
