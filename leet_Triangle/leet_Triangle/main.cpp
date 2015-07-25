//
//  main.cpp
//  leet_Triangle
//
//  Created by zhangwenze on 15/7/22.
//  Copyright (c) 2015年 zhangwenze. All rights reserved.
// 完全正确    这道题目就是典型的三角形的问题!!
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
    
    int min(int a,int b){
        return a<b?a:b;
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        //vector <vector<int> > minum;
        int lev=(int) triangle.size();
        for(int i=lev-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                triangle[i][j]=min(triangle[i][j]+triangle[i+1][j],triangle[i][j]+ triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
        
    }
};




int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    vector<vector<int> > tri={{2},{3,4},{6,5,7},{4,1,8,3}};
    Solution so;
    int res=so.minimumTotal(tri);
    printf("%d\n",res);
    return 0;
}
