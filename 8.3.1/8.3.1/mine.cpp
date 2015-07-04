//yes  一次就对了！！！  太好了！当然是先参考了别人的代码之后写的！！
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<math.h>
#include<algorithm>

#include<vector>
#include<map>
#include<queue>
#include<stack>
using namespace std;
const int SIZE=100;
int pic[SIZE][SIZE];
int num=1;
//开始定义两个坐标 就可以搞定那些个递归  很方便的
//其中 x1,y1 为左上角的坐标  x2,y2 为特殊点的坐标 
//然后 size 为当前的大小  （也就是2的某次幂的一个数）
void cover(int x1,int y1,int x2,int y2,int size){//只有分治
	// 没有归并
	if(size==1)
		return;
	int halfsize=size/2;
	int np=num++;
	if((x2-x1)<halfsize && (y2-y1)<halfsize){
		cover(x1,y1,x2,y2,halfsize);
	}
	else{
		pic[x1+halfsize-1][y1+halfsize-1]=np;//左上部分的右下角变为特殊的
		cover(x1,y1,x1+halfsize-1,y1+halfsize-1,halfsize);
	}
	if((x2-x1)>=halfsize&&(y2-y1)<halfsize){
		cover(x1+halfsize,y1,x2,y2,halfsize);
	}
	else{
		pic[x1+halfsize][y1+halfsize-1]=np;
		cover(x1+halfsize,y1,x1+halfsize,y1+halfsize-1,halfsize);
	}
	if((x2-x1)<halfsize&&(y2-y1)>=halfsize){//  zuo xia 
		cover(x1,y1+halfsize,x2,y2,halfsize);
	}
	else{
		pic[x1+halfsize-1][y1+halfsize]=np;
		cover(x1,y1+halfsize,x1+halfsize-1,y1+halfsize,halfsize);
	}
	if((x2-x1)>=halfsize&&(y2-y1)>=halfsize){
		cover(x1+halfsize,y1+halfsize,x2,y2,halfsize);
	}
	else{
		pic[x1+halfsize][y1+halfsize]=np;
		cover(x1+halfsize,y1+halfsize,x1+halfsize,y1+halfsize,halfsize);
	}
}
int main(){
	int s,xx,yy;
	printf("please input the size and the x and y of special point\n");
	scanf("%d%d%d",&s,&xx,&yy);
	cover(1,1,xx,yy,s);
	for(int i=1;i<=s;i++){
		for(int j=1;j<=s;j++){
			printf("%3d",pic[i][j]);
		}
		printf("\n");
	}

	return 0;
}
