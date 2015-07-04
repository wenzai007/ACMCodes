//这尼玛  短倒是挺短的  但是他妈的 变量的名字起得跟屎一样恶心啊！
#include <stdio.h>
#include <string.h>

int t;
long long Max, Min, num2[15];
int num1[15];
char fu[15];
int numm, numm2;

void init() {
    numm = 0; Min = 0; Max = 1;
    while (1) {
	scanf("%d%c", &num1[numm], &fu[numm]);
	numm ++;
	if (fu[numm - 1] == '\n')
	    break;
    }
}

void solve() {
    numm2 = 0;
    memset(num2, 0, sizeof(num2));
    for (int i = 0; i < numm; i ++) {
	num2[numm2] += num1[i];
	if (fu[i] == '*')
	    numm2 ++;
    }
    for (int i = 0; i <= numm2; i ++)
	Max *= num2[i];
    numm2 = 0;
    memset(num2, 0, sizeof(num2));
    for (int i = 0; i < numm; i ++) {
	if (num2[numm2] != 0)
	    num2[numm2] *= num1[i];
	else
	    num2[numm2] = num1[i];
	if (fu[i] == '+')
	    numm2 ++;
    }
    for (int i = 0; i <= numm2; i ++)
	Min += num2[i];
    printf("The maximum and minimum are %lld and %lld.\n", Max, Min);
}

int main() {
	freopen("in.txt","r",stdin);
    scanf("%d\n", &t);
    while (t --) {
	init();
	solve();
    }
    return 0;
}
