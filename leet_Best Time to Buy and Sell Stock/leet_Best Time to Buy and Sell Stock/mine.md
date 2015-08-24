# 我的方法  是这样的


11 8   10  5   6


维护一个当前的最小元素 

维护一个当前的最大收益   

遍历 整个数组  不断更新   

```cpp
for(int i=1;i<len;i++){
            if(prices[i]>mincur){
                maxfit=max(maxfit,prices[i]-mincur);
               // printf("%d\n",maxfit);
            }
            else{
                mincur=min(mincur,prices[i]);
            }
        }
 return maxfit;

```

我的方法貌似比其他的方法都要简单很多唉~~~
