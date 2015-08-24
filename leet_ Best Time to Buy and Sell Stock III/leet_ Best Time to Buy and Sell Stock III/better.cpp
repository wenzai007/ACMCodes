//
//  better.cpp
//  leet_ Best Time to Buy and Sell Stock III
//
//  Created by zhangwenze on 15/8/24.
//  Copyright (c) 2015年 zhangwenze. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>//有cmath 但是没有math

#include<stack>
#include<queue>
#include<vector>// add graghs
#include<map>

#include<time.h>
using namespace std;



class Solution {
public:
    
    int mymax(int a,int b){
        return a>b?a:b;
    }
    
    int maxProfit(vector<int>& prices) {
        int len= prices.size();
        if(len<=1)
            return  0;
        
        vector<int> maxFromLeft(len,0);
        vector<int> maxFromRight(len,0);
        
        int min=INT_MAX;
        int max_value=0;
        for(int i=0;i<len;i++){//  从[0,i]闭区间
            if(prices[i]<min)
                min=prices[i];
            if((prices[i]-min)>max_value)
                max_value=prices[i]-min;
            
            maxFromLeft[i]=max_value;
        }
        
        int max=INT_MIN;
        max_value=0;
        for(int i=len-2;i>=0;i--){//从（i，n]开区间
            if(prices[i+1]>max)//这都是 i+1
                max=prices[i+1];
            if(max-prices[i+1]>max_value)
                max_value=max-prices[i+1];
            
            maxFromRight[i]=max_value;//这里是i
        }
        
        max_value=0;
        for(int i=0;i<len;i++){
            max_value=mymax(maxFromLeft[i]+maxFromRight[i],max_value);
        }
        
        
        return max_value;
    }

};

    int main(int argc, const char * argv[]) {
        
        vector<int> list ={1,2};
        Solution s;
        
        int res =s.maxProfit(list);
        printf("%d\n",res);
        
        // insert code here...
        printf("Hello, World!\n");
        return 0;
    }
