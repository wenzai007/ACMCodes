// wa   原因 精度损失
//  第二次 wa  也是精度损失！！
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int dense[200];//存储浓度的数组
int c,n,V,W,P;
int main(){
	//freopen("in.txt","r",stdin);
	while (scanf("%d",&c)!=EOF&&c){
		while (c--!=0){
			scanf("%d%d%d",&n,&V,&W);
			for(int i=0;i<n;i++){
				scanf("%d",&dense[i]);
			}
			sort(dense,dense+n);
			int cnt=0;//一共有几个容器
			double densetmp=0;
			if(dense[0]>W) {
				printf("0 0.00\n");
				continue;//下一组数据
			}
			densetmp=dense[0];
			int total=dense[0];//记录总的浓度和
			cnt++;//cnt==1
			//while (densetmp<=W&&cnt<n){//这里出现了错误！！ 不能用除法
				// 因为如果下面的循环是15.0000001 与W相比较的话
				//当然是 舍去了后面的变成了15  所以满足了条件
				//继而 本来应该停止的时候却继续的进行循环
				//从而使得由于精度的损失而导致的结果错误
				//方解决法：避免用除法 而是用乘法来进行比较！！
			  // 也就是让densetmp<=W  两边同时乘以cnt！！！！ 
			while (total<=(W*cnt)&&cnt<n){
				total+=dense[cnt];
				cnt++;
				//densetmp=total/cnt;//!!!!!!这是另外一个错误的地方
							//不加强制转换的 话 也同样会使得精度
				     //有损失！！  比如  10/3 ==3  那么densetmp会
				   //被赋值成为  3.000000000 而不是3.3333333  
				densetmp=(double )total/cnt;
				
			}
			//if(total<=(W*cnt)){  //！此处也相应的修改
			if(total>(W*cnt)){
			    cnt--;
				total-=dense[cnt];
				densetmp=(double)total/cnt; //同样的修改
			}
			printf("%d %.2lf\n",cnt*V,densetmp/100);
		}
	}
	return 0;
}










// effect
