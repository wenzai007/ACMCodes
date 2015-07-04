#include <stdio.h>
#include <string.h>
#define ISYEAP(x) x % 100 != 0 && x % 4 == 0 || x % 400 == 0 ? 1 : 0
int dayOfMonth[13][2] = {
	0,0,
	31,31,
	28,29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31
};
struct Date {
	int Day;
	int Month;
	int Year;
	void nextDay() {
		Day ++;
		if (Day > dayOfMonth[Month][ ISYEAP(Year) ]) {
			Day = 1;
			Month ++;
			if (Month > 12) {
				Month = 1;
				Year ++;
			}
		}
	}
};
int buf[3001][13][32];
char monthName[13][20] = {
	"",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
}; //月名每个月名对应下标1到12
char weekName[7][20] = {
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday"
}; //周名每个周名对应下标0到6
int main () {
	Date tmp;
	int cnt = 0;
	tmp.Day = 1;
	tmp.Month = 1;
	tmp.Year = 0;
	while(tmp.Year != 3001) {
		buf[tmp.Year][tmp.Month][tmp.Day] = cnt;
		tmp.nextDay();
		cnt ++;
	} //以上与上题一致,预处理出每一天与原点日期的天数差
	int d ,m , y;
	char s[20];
	while (scanf ("%d%s%d",&d,s,&y) != EOF) {
		for (m = 1;m <= 12;m ++) {
			if (strcmp(s,monthName[m]) == 0) {
				break; //将输入字符串与月名比较得出月数
			}
		}
		int days = buf[y][m][d] - buf[2012][7][16]; //计算给定日期与今日日期的天数间隔(注意可能为负)
		days += 1; //今天(2012.7.16)为星期一,对应数组下标为1,则计算1经过days天后的下标
		puts(weekName[(days % 7 + 7) % 7]); //将计算后得出的下标用7对其取模,并且保证其为非负数,则该下标即为答案所对应的下标,输出即可
	}
	return 0;
}

