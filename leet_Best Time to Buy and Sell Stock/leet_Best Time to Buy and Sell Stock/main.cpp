//
//  main.cpp
//  Best Time to Buy and Sell Stock
//
//  Created by zhangwenze on 15/7/28.
//  Copyright (c) 2015年 zhangwenze. All rights reserved.
//
/**
  this is my solution !!!   
  10 8  9   5  5.1
 */

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;



class Solution {
public:
    
    int min(int a,int b){
        return a<b?a:b;
    }
    
    int max(int a,int b){
        return a>b?a:b;
    }
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0){
            return 0;
        }
        int len =prices.size();
        int maxfit=0;
      //  memset(maxfit, 0,len);
        int mincur= prices[0];
        
        for(int i=1;i<len;i++){
            if(prices[i]>mincur){
                maxfit=max(maxfit,prices[i]-mincur);
               // printf("%d\n",maxfit);
            }
            else{
                mincur=min(mincur,prices[i]);
            }
        }
        return maxfit;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> p={11,8,10,5,6};
    Solution s;
    int res=s.maxProfit(p);
    printf("%d\n",res);
    return 0;
}
