//
//  main.cpp
//  Maximal Rectangle
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
    
    int maximalRectangle(vector<vector<char>>& matrix){
        if(matrix.size()==0)
            return 0;
        int maxnum=INT_MIN;
        for(int i=0;i<matrix.size();i++){
            vector<int > v;
            for(int j=0;j<matrix[i].size();j++){
                int k=i;
                int cnt=0;
                while(k>=0 && matrix[k][j]=='1' ){
                    cnt++;
                    k--;
                }
                v.push_back(cnt);
                
            }
            int tmp=largestRectangleArea(v);
            maxnum=max(maxnum,tmp);
        }
        return maxnum;
    }
    
    
    
    
    int largestRectangleArea(vector<int> &height) {
        
        stack<int> s;
        int maxarea=INT_MIN;
        height.push_back(0);
        int i=0;
        while(i<height.size()){
            if(s.empty() || height[s.top()]< height[i]){
                s.push(i++);// notice this is index number
            }
            else{
                int now=s.top();
                s.pop();
                int nowarea= height[now]*(s.empty()?i:i-s.top()-1);
                maxarea= max(maxarea,nowarea);
                
            }
            
        }
        return maxarea;
    }
    
    int max(int a,int b){
        return a>b?a:b;
    }
};


int main(int argc, const char * argv[]) {
    vector<int > h={2,1,5,6,2,3};
    vector<int > hh={0,0};
    vector<vector<char> > matrix={{'0','0','1','0'},{'0','0','0','1'},{'0','1','1','1'},{'0','0','1','1'}};
    Solution s;
    printf("%d\n", s.maximalRectangle(matrix));
    return 0;
}

