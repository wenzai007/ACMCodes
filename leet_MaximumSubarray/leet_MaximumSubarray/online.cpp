//
//  online.cpp
//  leet_MaximumSubarray

// 采用分治法的方法来进行  处理！！
//
//  Created by zhangwenze on 15/7/23.
//  Copyright (c) 2015年 zhangwenze. All rights reserved.
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
    
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxV = INT_MIN;
        return maxArray(A, 0, n-1, maxV);
    }
    int maxArray(int A[], int left, int right, int& maxV)
    {
        if(left>right)
            return INT_MIN;
        int mid = (left+right)/2;
        int lmax = maxArray(A, left, mid -1, maxV);
        int rmax = maxArray(A, mid + 1, right, maxV);
        maxV = max(maxV, lmax);
        maxV = max(maxV, rmax);
        //下面这个方法就是求包含特定的一个元素（mid元素）的最大连续串的和是多少
        //先求  它挨着它的左边的连续的最大的和是多少，然后求挨着它的右边的连续的
        //最大的和是多少  最后加上它自己   这个是一般的方法
        int sum = 0, mlmax = 0;
        for(int i= mid -1; i>=left; i--)
        {
            sum += A[i];
            if(sum > mlmax)
                mlmax = sum;
        }
        sum = 0; int mrmax = 0;
        for(int i = mid +1; i<=right; i++)
        {
            sum += A[i];
            if(sum > mrmax)
                mrmax = sum;
        }
        maxV = max(maxV, mlmax + mrmax + A[mid]);
        return maxV;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    
    //vector<int> nums= {-2,1,-3,4,-1,2,1,-5,4};
    int A[]={-2,1,-3,4,-1,2,1,-5,4};
    Solution so;
    int res=so.maxSubArray(A,9);
    printf("%d\n",res);
    return 0;
}