//
//  main.cpp
//  leet_wordbreak
//
//  Created by zhangwenze on 15/7/20.
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
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int len=s.length();
        vector <bool> possible(len,false);
        possible[0]=true;
        for(int i=1;i<=len;i++){
            for(int j=0;j<i;j++){
                if(possible[j] && wordDict.find(s.substr(j,i-j))!=wordDict.end()){
                    possible[i]=true;
                    break;// once p[i] is true,no neccessary to continue;
                }
                
            }
        }
        return  possible[len];
    }
};


int main(int argc, const char * argv[]) {
    // int main() {
    //freopen("/Users/Knight/Documents/workspace/ACMCodes/leet_wordbreak/leet_wordbreak/in.txt","r",stdin);
    //printf("helllo!\n");
    string s="leetcode";
   // unordered_set<string> wordDict={"leet","code"};
    unordered_set<string> wordDict={"leet","ode","c"};
    Solution sol;
    if(sol.wordBreak(s, wordDict)){
        printf("yes it can\n");
    }
    else printf("no  can not \n");
    return 0;
}
