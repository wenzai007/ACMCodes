//yes  һ�ξͶ��ˣ�����  ̫���ˣ���Ȼ���Ȳο��˱��˵Ĵ���֮��д�ģ���
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
//��ʼ������������ �Ϳ��Ը㶨��Щ���ݹ�  �ܷ����
//���� x1,y1 Ϊ���Ͻǵ�����  x2,y2 Ϊ���������� 
//Ȼ�� size Ϊ��ǰ�Ĵ�С  ��Ҳ����2��ĳ���ݵ�һ������
void cover(int x1,int y1,int x2,int y2,int size){//ֻ�з���
	// û�й鲢
	if(size==1)
		return;
	int halfsize=size/2;
	int np=num++;
	if((x2-x1)<halfsize && (y2-y1)<halfsize){
		cover(x1,y1,x2,y2,halfsize);
	}
	else{
		pic[x1+halfsize-1][y1+halfsize-1]=np;//���ϲ��ֵ����½Ǳ�Ϊ�����
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
