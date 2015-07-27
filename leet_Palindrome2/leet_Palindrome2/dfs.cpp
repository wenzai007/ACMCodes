//
//  main.cpp
//  leet_Palindrome Partitioning II
//
//  Created by zhangwenze on 15/7/26.
//  Copyright (c) 2015年 zhangwenze. All rights reserved.
//
//但是这种方案 会导致 超时  TLE！！！！！

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
    
    vector <vector<string> > minCut(string s) {
    
        vector <vector<string> > res ;
        vector<string> list;
        partition (res,list,s);
        
        return  res;
    }
    void partition(vector <vector<string> > &res ,vector<string> list,string s){// 不是全局的  所以三个变量都要加上
        if(s.length()==0){
            res.push_back(list);
            return;
        }
        
        for(int i=1;i<=s.length(); i++){
            string subs=s.substr(0,i);//>0,  连续i个字符
            if(ispalin(subs)){
                list.push_back(subs);
                string rem=s.substr(i);//>i-1 从第i个开始
                partition(res, list,rem);
                list.pop_back();//两个作用 1如果放进去了list 那么返回的时候一路清空 最后这个list全部清空 可以为下一轮遍历做准备 2  如果这个list 没有 成功，那么拿出来上一个subs，遍历下一种可能的组合
            }
        }
        
    }
    
    bool ispalin(string s){
        int i=0,j=s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
    
};

int main(){
    string ss="aab";
    string sss="ababbbabbaba";
    string ssss="kwtbjmsjvbrwriqwxadwnufplszhqccayvdhhvscxjaqsrmrrqngmuvxnugdzjfxeihogzsdjtvdmkudckjoggltcuybddbjoizu";
    // int m=sss[0];
    //int n=sss[2];
    //if (sss[0]==sss[2]) printf("yes\n");
    
    vector <vector<string> > r;
    Solution s;
    r=s.minCut(sss);
    int mincut=INT_MAX;
    for(int i=0;i<r.size();i++){
        if(r[i].size()<mincut)
            mincut=r[i].size();
        for(int j=0;j<r[i].size();j++){
            printf("%s\n",r[i][j].c_str());
        }
    }
    printf("-------->%d\n",mincut-1);
    
    return 0;
}


