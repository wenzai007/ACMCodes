/* 
 * UVa: 311 - Packets 
 * Time: 0.008s 
 * Author: D_Doubel 
 * 
 */  
#include<iostream>  
#include<cstdio>  
using namespace std;  
int arr[7];  
  
// 放置3*3的在6*6中的组合情况,优先放置更多的2*2  
// 当放置1个3*3时，还可以放置7个1*1和5个2*2  
// 当放置2个3*3时，还可以放置6个1*1和3个2*2  
// 当放置3个3*3时，还可以放置5个1*1和1个2*2  
int three[4][2]= {{0,0},{7,5},{6,3},{5,1}};  
  
int main(){  
	freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d%d%d%d",&arr[1],&arr[2],&arr[3],&arr[4],&arr[5],&arr[6])){  
        if(!arr[1]&&!arr[2]&&!arr[3]&&!arr[4]&&!arr[5]&&!arr[6])break;  
  
        int ans=(arr[3]+3)/4+arr[4]+arr[5]+arr[6]; // 3*3,4*4,5*5,6*6一起用了几个  
  
        arr[1] -= arr[5]*11; //6*6的可以放置一个5*5和11个1*1,所以直接优先把1*1和5*5放在一个盒子里  
  
        int left_for_2=three[arr[3]%4][1]+arr[4]*5;//已用的盒子中的空隙中共还可以放置多少个2*2  
  
        if(arr[2]<=left_for_2){ // 当已用盒子中的空隙可以放置完2*2盒子时  
            arr[1] -= three[arr[3]%4][0]; // 在空隙中与2*2组合的可以放置的1*1个数  
            arr[2] -= left_for_2;  
            arr[1] += arr[2]*4; // 如果2*2是负数，那说明负数的绝对值是空隙，可以用来放置1*1  
            if(arr[1]>0) // 如果1*1还有，那么要增加盒子  
                ans += (arr[1]+35)/36;  
        }   
        else{  // 不能放置完2*2  
            arr[1] -= three[arr[3]%4][0]; //之前和2*2组合一起填满盒子的1*1  
            arr[2] -= left_for_2;  
            ans += (arr[2]+8)/9;  // 再增加盒子直到能放完2*2  
            arr[1] -= (9-arr[2]%9)*4; // 增加的盒子中可能不能占满2*2，还有空位可以放置1*1  
            if(arr[1]>0)  
                ans += (arr[1]+35)/36;  
        }  
        printf("%d\n", ans);  
    }  
    return 0;  
}  