#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
using namespace std;
#define MAXN 100000

int  t , n;
long long  num[MAXN];//保存某一个值的总数

//打表初始化
void init(){
    long long i , j , k , tmp;//long long注意
    memset(num , 0 , sizeof(num));//初始化
    for(i = 1 ; i <= 5 ; i++){//枚举位数，最大到5位即可
        for(j = pow((double)10,(int)i-1) ; j < pow((double)10,(int)i) ; j++){
            num[j] = num[j-1] ;//这个是之前的一个的位数  下面需要从1开始

			tmp = (j-pow((double)10,(int)i-1)+1)*i;//当前这个位数有多少位
			//比如说当前是120 那么就是120-100+1   100到120 包括100的  然后乘以3         
            for(k = 1 ; k < i ; k++)
                tmp +=(pow((double)10,(int)k)-pow((double)10,(int)k-1))*k;//这个是之前的所有的位数加在一起的
            num[j] += tmp;
        }
    }
}

void solve(){
    int i , j , k , pos , ans;
    //找到pos位置
    for(i = 1 ; i < MAXN ; i++){
        if(n > num[i-1] && n <= num[i]){
            pos = i ; break;
        }
    }
    //查找
    int cnt = n-num[pos-1] ; int sum = 0;
    int len , tmp , tmp_j;
    for(j = 1 ; j <= pos ; j++){
        tmp_j = j;
        for(i = tmp_j , len = 0 ; i != 0 ; i/=10) len++;
        for(k = len-1; k >= 0 ;k--){
            ans = tmp_j/pow((double)10,(int)k) ; sum++;
            if(sum == cnt){            
                printf("%d\n" , ans);
                return;
            }
            tmp = pow((double)10,(int)k) ; tmp_j %= tmp;
        }
    } 
}

int main(){
    //freopen("input.txt" , "r" , stdin);
    init() ; scanf("%d" , &t); 
    while(t--){
        scanf("%d" , &n) ; solve();
    }
    return 0;
}
