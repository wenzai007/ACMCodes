#include<stdio.h>
#include<math.h> //提供那个abs 绝对值函数
#include<stdlib.h>
#include<string.h>
#define isleap(x)  ((x%4==0&&x%100!=0)||(x%400)==0)?1:0
int buf[5001][13][32];// 为了存纯每一个天数的东西 ！！
int daysofmonth [13][2]={/*要想好是用[2][13]还是[13][2]
						   因为按照多维数组是按照行赋值的东西
						   所有这里面为了书写方便是写成[13][2]
						   当然另一种也可以但是初始化的时候不要出错
						   */
	0,0,
	31,31,//1
	28,29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,//7
	31,31,//8
	30,30,
	31,31,//10
	30,30,
	31,31
};
struct date{
	int year;
	int month;
	int day;
	void nextday(){// 仅仅作用在自己身上！然后将自己的变化过程
		//   复制给多维数组  自己是从零变化到5000年的
		//   这个过程赋值给数组！！！！要理解这种思想
		this->day++;//显示的使用this指针  当然只有成员函数才有
		//this指针的
		
		if(day>daysofmonth[month][isleap(year)]){
			day=1;
			month++;
		}
		if(month>12){
			month=1;
			year++;
		}
	}
}; 

int main(){//预处理 类似于哈希映射的原理  就是说数组的下标代表的
	       //是日期  而其值代表的是与第一天的天数差。
	date tmp;
	tmp.year=0;tmp.month=1;tmp.day=1;
	int cnt=0;
	while(tmp.year<5001){
	//buf[0][1][1]=0;//虽然结果要求加1 但是那是两个数的差之间
					//之间的了，所以应该再后面加上什么东西
		buf[tmp.year][tmp.month][tmp.day]=cnt;
		tmp.nextday();
		cnt++;
	}
	int year1,month1,day1;
	int year2,month2,day2;
	while(scanf("%4d",&year1)!=EOF){
		scanf("%2d",&month1);
		scanf("%2d",&day1);
		scanf("%4d",&year2);
		scanf("%2d",&month2);
		scanf("%2d",&day2);
		printf("%d\n",abs(buf[year2][month2][day2]-buf[year1][month1][day1])+1);
		//不知道哪个abs函数是不是这么写的?看来是的
	}
		return 0;	
}


// fot  the middle effect!!
