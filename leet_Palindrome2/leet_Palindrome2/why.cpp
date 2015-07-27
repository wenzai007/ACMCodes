////
////  main.cpp
////  leet_Palindrome Partitioning II
////
////  Created by zhangwenze on 15/7/26.
////  Copyright (c) 2015年 zhangwenze. All rights reserved.
////
//
//
//#include <iostream>
//#include <stdio.h>
//#include <string>
//#include <unordered_set>
//
//#include<stdlib.h>
//
//#include<string.h>
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
//using namespace std;
//
//
//int cuts[100];
//    
//    int min(int x,int y){
//        return  x<y?x:y;
//    }
//    
//    int minCut(string s) {
//        
//        int len= s.length();
//      //  int cuts[len+1];// because the last element may has a cut too  防止j+1越界 后面
//        bool palin[len-1][len-1];
//        for(int i=0;i<len;i++){
//            for(int j=0;j<len;j++){
//                palin[i][j]=false;
//            }
//        }
//        
//        for(int i=0;i<=len;i++){
//            cuts[i]=len-i-1;//  the last element cuts is 0 no need to cut
//            printf("%d",cuts[i]);
//            
//        }
//        for(int i=len-1;i>=0;i--){
//            for(int j=i;j<len;j++){
//                for(int k=0;k<len;k++)
//                    printf("cuts[%d]: %d\n",k,cuts[k]);
//                if(s[i]==s[j] && (j-i<2 || palin[i+1][j-1])){//is palin
//                    
//                    for(int k=0;k<len;k++)
//                        printf("cuts[%d]: %d\n",k,cuts[k]);
//                    palin[i][j]=true;
//                    printf("cuts[%d]: %d\n",i,cuts[i]);
//                    cuts[i]=min(cuts[i],cuts[j+1]+1);
//                    printf("cuts[%d]: %d cuts[%d]: %d\n",i,cuts[i],j+1,cuts[j+1]);
//                }
//            }
//        }
//        return cuts[0];
//        
//        
//    }
//
//
//int main(int argc, const char * argv[]) {
//    string ss="aab";
//    string sss="ababbbabbaba";
//    string ssss="coder";
//    // int m=sss[0];
//    //int n=sss[2];
//    if (sss[0]==sss[2]) printf("yes\n");
//  //  Solution s;
//    int res=minCut(ssss);
//    //printf("asdfasdfasf");
//    printf("%d\n",res);
//    return 0;
//}
