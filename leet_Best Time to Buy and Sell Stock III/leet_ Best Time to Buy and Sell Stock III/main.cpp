////
////  main.cpp
////  leet_ Best Time to Buy and Sell Stock III
////
////  Created by zhangwenze on 15/8/24.
////  Copyright (c) 2015年 zhangwenze. All rights reserved.
////
//
//
///**
// *  Best Time to Buy and Sell Stock III Total Accepted: 38468 Total Submissions: 160251 My Submissions Question Solution
//Say you have an array for which the ith element is the price of a given stock on day i.
// 
// Design an algorithm to find the maximum profit. You may complete at most two transactions.
// 
// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
// 
//
// *
// *  @param ie    <#ie description#>
// *  @param again <#again description#>
// *
// *  @return <#return value description#>
// 
// 
// */
//
//
//
//#include<stdio.h>
//#include<stdlib.h>
//
//#include<string.h>
//#include<string>
//#include<ctype.h>
//
//#include<algorithm>
//#include<math.h>//有cmath 但是没有math
//
//#include<stack>
//#include<queue>
//#include<vector>// add graghs
//#include<map>
//
//#include<time.h>
//using namespace std;
//
//
//
//class Solution {
//public:
//    
//    int mymax(int a,int b){
//        return a>b?a:b;
//    }
//    
//    int maxProfit(vector<int>& prices) {
//        int len= prices.size();
//        if(len<=1)
//            return  0;
//        int maxv_left=0;
//        int maxv_right=0;
//        int max=0;
//        
//        for(int i=0;i<len;i++){
//            maxv_left=findMaxLeft(prices,i);
//            maxv_right=findMaxRight(prices, i);
//            max= mymax(max,maxv_left+maxv_right);
//            
//        }
//        return 0;
//    }
//    
//    int findMaxLeft(vector<int>& prices,int k){
//        int max_v=0;
//        int min=INT_MAX;
//        for(int i=0;i<=k;i++){
//            if(prices[i]<min){
//                min=prices[i];
//        
//            }
//            if((prices[i]-min) > max_v ){//减的是自己也没事
//                max_v=prices[i]-min;
//            }
//        }
//        return max_v;
//    }
//    
//    int findMaxRight(vector<int>& prices,int k){
//        int max_v=0;
//        int min=INT_MAX;
//        for(int i=k+1;i<prices.size();i++){
//            if(prices[i]<min){
//                min=prices[i];
//                
//            }
//            if((prices[i]-min) > max_v ){//减的是自己也没事
//                max_v=prices[i]-min;
//            }
//        }
//        return max_v;
//    }
//    
//    
//    
//};
//
//
//
//int main(int argc, const char * argv[]) {
//    
//    vector<int> list(10,1);
//    list[1]=8;
//    
//    // insert code here...
//    printf("Hello, World!\n");
//    return 0;
//}
