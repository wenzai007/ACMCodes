


//
//  main.cpp
//  leet_MaximumSubarray
//
//  Created by zhangwenze on 15/7/22.
//  Copyright (c) 2015年 zhangwenze. All rights reserved.

//用的是  动态规划的  方法  时间复杂度是O（n）  
 // 分析思路见本子  @29
//


#include <iostream>
#include <stdio.h>
#include <string>
#include <unordered_set>

#include<stdlib.h>

#include<string.h>
#include<ctype.h>

#include<algorithm>
#include<math.h>//有cmath 但是没有math

#include<stack>
#include<queue>
#include<vector>// add graghs
#include<map>

using namespace std;

class Solution {
public:
    
    int max(int a,int b){
        return  a>b?a:b;
    }
    
    int maxSubArray(vector<int>& nums) {
        int maxres=nums[0];
        int len =nums.size();
        int sum[len];
        sum[0]=nums[0];
        for(int i=1;i<len;i++){
            sum[i]=max(sum[i-1]+nums[i],nums[i]);
            maxres=max(maxres,sum[i]);
        }
        return maxres;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    
    vector<int> nums= {-2,1,-3,4,-1,2,1,-5,4};
    Solution so;
    int res=so.maxSubArray(nums);
    printf("%d\n",res);
    return 0;
}
 
 
 //*/
