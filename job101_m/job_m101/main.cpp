//
//  main.cpp
//  job_m101
//
//  Created by zhangwenze on 15/7/7.
//  Copyright (c) 2015年 zhangwenze. All rights reserved.
//

#include <stdio.h>

#define INF 0x7fffffff //无穷
int max(int a,int b){return a > b ? a:b ;}

struct E{//保存物品信息的结构体
    int w;//物品的体积
    int v;//物品的价值
}list[101];

int dp[101][1001];//记录状态数组，dp[i][j]表示前i个物品组成的总体积不大于j的最大价值和
int main(){
     freopen("/Users/Knight/Documents/workspace/ACMCodes/job101_m/job_m101/in.txt","r",stdin);
    
    int s;//总共能共用来采药的时间
    int n;//代表山洞里的草药的数目
    while(scanf("%d%d",&s,&n) != EOF){
        for(int i = 1; i <= n;i++){
            scanf("%d%d",&list[i].w,&list[i].v);
        }
        for(int i = 0;i <= s; i++){
            dp[0][i] = 0;//前0个物品组成的总体积不大于i的最大价值和为0，这个要注意
        }//初始化状态
        for(int i = 1; i <= n; i++){//循环每一个物品
            for(int j = s; j >= list[i].w;j--){//对s到list[i].w的每一个j
                //状态转移来源为dp[i-1][j] 或dp[i-1][j-list[i].w] + list[i].v,选择其中较大的一个
                dp[i][j] = max(dp[i-1][j],dp[i-1][j - list[i].w] + list[i].v);
            }
            for(int j = list[i].w - 1; j >= 0; j--)//对于list[i].w - 1 到0的每个j，状态仅能来源于dp[i-1][j],故直接赋值？？？这里应该是确定不能够放当前的list[i]了的时候。并且j小于list[i].w 那么j - list[i].w就是负数了，所以不能一起处理的！
            dp[i][j] = dp[i-1][j];
        }
        
        
        
        /**
         
         my added codes
         
         */
        for(int i=0;i<=n;i++){
            for(int j=s;j>=0;j--){
                if(dp[i][j]!=0){
                    printf("i:  %d   j:  %d   value-->  %d\n",i,j,dp[i][j]);
                }
            }
        }
        
        
        
        printf("%d---------------------------------\n",dp[n][s]);
        
        for(int i=0;i<5;i++)printf("\n");
        
       
        
        
    }
    return 0;
    
    
}

