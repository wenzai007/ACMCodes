//
//  main.cpp
//  leet_Largest Rectangle in Histogram
//
//  Created by zhangwenze on 15/7/28.
//  Copyright (c) 2015年 zhangwenze. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        
        stack<int> s;
        int maxarea=INT_MIN;
        height.push_back(0);
        for(int i=0;i<height.size();i++){
            if(s.empty() || height[s.top()]< height[i]){
                s.push(i);// notice this is index number
                continue;
                
            }
            //while((height[s.top()]>=height[i]) && !s.empty()){顺序写错了就会报错啊！！！ 记住啊！！
            while(!s.empty() && (height[s.top()]>=height[i])){
                int now=s.top();
                s.pop();
                int nowarea= height[now]*(s.empty()?i:i-s.top()-1);
                maxarea= max(maxarea,nowarea);
                
            }
            s.push(i);
        }
        return maxarea;
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int > h={2,1,5,6,2,3};
    vector<int > hh={0,0};
    Solution s;
    printf("%d\n", s.largestRectangleArea(hh));
    return 0;
}
