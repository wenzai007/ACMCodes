//注意这是poj上的题目 而且  如果 【1，,10】区间的话【1,4】和【5,10】两个是
//可以覆盖所有的区间的！！  注意这一点  很重要的！！不用【1,4】和【4，10】的！！
#include <iostream>  
#include <algorithm>  
using namespace std;  
  
const int Max = 25000;  
  
// 对象  
int N, T;  
struct Interval {  
    int b, e;  
}I[Max];  
  
// 函数  
bool greater( const Interval & i1, const Interval & i2 )  
{  
    return i1.b < i2.b;  
}  
  
int Greedy()  
{  
    int num = 0; // 最少区间数   
    int right = 0; // 已覆盖区间右端点  
    int top = 0; // 集合首  
  
    while( right < T ) {  
        // 选出包含begin的区间中右端点最大的那个  
        int begin = right + 1; // 待覆盖的起点  
        for( int i = top; i < N; ++ i ) {  
            if( I[i].b <= begin && I[i].e >= begin )  //防止都在左边或者都在右边
                right = I[i].e > right ? I[i].e : right;  
            else if( I[i].b > begin ) {  
                top = i;  
                break;  
            }  
        }  
        // 没有包含begin的区间  
        if( begin > right ) break; //这一轮right没有改变 
        else ++ num;  
    }  
  
    if( right == T ) return num;  
    else return -1;  
}  
  
int main()  
{	freopen("in.txt","r",stdin);
    scanf( "%d%d", & N, & T );  
    for( int i = 0; i < N; ++ i )  
        scanf( "%d%d", & I[i].b, & I[i].e );  
      
    sort( I, I + N, greater );  
    printf( "%d\n", Greedy() );  
    return 0;  
}  