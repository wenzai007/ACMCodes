//主要是怎么去存储多个数在一个数组中 把F[i]  J[i] 和比值都存下
//哦  可以用结构体数组
//也可以用 多维数组  例如 int [n][3];
//但是如果是不同的类型的话  貌似只能用那个结构体以及不太会用的
//vector了吧
//1.   wrong answer! 少考虑了情况
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct  cases {
	double J,F; //  不能用int 应该 因为减去的数字可能是double的
	double rate;
	bool  operator <(const cases b)const{
		return rate>b.rate;//让大的在前面
	}
}buf[2000];//开大一点
int main(){
//	freopen("in.txt","r",stdin);
	double Ftotal;
	int num;
	double jtmp,ftmp;
	while (scanf("%lf%d",&Ftotal,&num)!=EOF){
		if(Ftotal==-1&&num==-1)break;
		for(int i=0;i<num;i++){
			scanf("%lf%lf",&jtmp,&ftmp);
			buf[i].J=jtmp;
			buf[i].F=ftmp;
			buf[i].rate=jtmp/ftmp;
		}
		sort(buf,buf+num);
		double res=0;
	//	while (Ftotal>0){//!!这句话其实可以去掉的！！这句话必须去掉
		//因为 这个条件在这里 我们就会啥考虑一种情况
		//那就是当我们的钱F还没有花完的时候 ，但是货物 也就是J已经
		//没有了的时候那么  while 判断的时候就会继续循环
		//从 i=0  继续遍历数组 然后重复的计算 结果 
		//c从而导致了 wrong answer 
			for(int i=0;i<num;i++){
				if(Ftotal>0){
					if(Ftotal>=buf[i].F){
						Ftotal-=buf[i].F;
						res+=buf[i].J;
					}
					else {
						//Ftotal=0;这句话的位置放错地方了 当然是要先说下一句话
						//才能清零的啊！！
						res+=(buf[i].J)*Ftotal/buf[i].F;
						Ftotal=0;
					}
				}
				else break;
			}
	//	} ！！！去掉while 否则是错的！
		//printf("%.3lf\n",&res);//不知道对不对？？？先别管格式了 傻逼
// 先看看哪个    变量你他娘的是怎么写的？？  &是什么jb
        printf("%.3lf\n",res);//就是这样写的！！
	}
	return 0;
}










//  middle effect















//  for the middle effect
