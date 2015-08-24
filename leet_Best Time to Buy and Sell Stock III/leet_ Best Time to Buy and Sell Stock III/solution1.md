# 下面是第一种方法 
# 用到了 之前的Best Time to Buy and Sell Stock 1 中的方法  就是  对每一个点 进行左右分别的计算  然后算最大的值


 ```cpp
 	int maxProfit(vector<int>& prices) {
        int len= prices.size();
        if(len<=1)
            return  0;
        int maxv_left=0;
        int maxv_right=0;
        int max=0;
        
        for(int i=0;i<len;i++){
            maxv_left=findMaxLeft(prices,i);
            maxv_right=findMaxRight(prices, i);
            max= mymax(max,maxv_left+maxv_right);
            
        }
        return 0;
    }
    
    int findMaxLeft(vector<int>& prices,int k){
        int max_v=0;
        int min=INT_MAX;
        for(int i=0;i<=k;i++){
            if(prices[i]<min){
                min=prices[i];
        
            }
            if((prices[i]-min) > max_v ){//减的是自己也没事
                max_v=prices[i]-min;
            }
        }
        return max_v;
    }
    
    int findMaxRight(vector<int>& prices,int k){
        int max_v=0;
        int min=INT_MAX;
        for(int i=k+1;i<prices.size();i++){
            if(prices[i]<min){
                min=prices[i];
                
            }
            if((prices[i]-min) > max_v ){//减的是自己也没事
                max_v=prices[i]-min;
            }
        }
        return max_v;
    }
 
 ```
 
 后来就是TLE  超时了  
 这个方法是O（n^2）复杂度
 
 
 所以  想一个O（n）的方法
 
 
 
 两次运用O（n）的初始化，分别从左到右  从右到左  进行扫描  然后对两个数组进行初始化，
 从左到右简单  ，就是正常的O（n）初始化
 
## <font color="73425">` 这道题目的关键是从右到左初始化!!! ` </font>



   	5   8  3   6   9  11  45 
   
       <--------------- 
       
#  一定要这个方向，否则的话  一定要用O（n^2）的 因为要从左遍历，再从当前点向右遍历  才能得到右边那一边的最大收益    


<font color = "ff3c00"> 从右到左  维护每一个点最大的当前值  再维护一个最大收益    </font>

下面这段值得仔细琢磨

```cpp
 int max=INT_MIN;
        max_value=0;
        for(int i=len-2;i>=0;i--){//从（i，n]开区间
            if(prices[i+1]>max)//这都是 i+1
                max=prices[i+1];
            if(max-prices[i+1]>max_value)
                max_value=max-prices[i+1];
            
            maxFromRight[i]=max_value;//这里是i
        }
        
```

第一次wa  因为没有注意开闭区间  无法相加  下面更改后AC

另外一定注意！！  从左到右 和从右到左  是一个闭区间一个开区间的！！！

```cpp
int min=INT_MAX;
        int max_value=0;
        for(int i=0;i<len;i++){//  从[0,i]闭区间
            if(prices[i]<min)
                min=prices[i];
            if((prices[i]-min)>max_value)
                max_value=prices[i]-min;
            
            maxFromLeft[i]=max_value;
        }
        
        int max=INT_MIN;
        max_value=0;
        for(int i=len-2;i>=0;i--){//从（i，n]开区间
            if(prices[i+1]>max)//这都是 i+1
                max=prices[i+1];
            if(max-prices[i+1]>max_value)
                max_value=max-prices[i+1];
            
            maxFromRight[i]=max_value;//这里是i
        }
        
        max_value=0;
        for(int i=0;i<len;i++){
            max_value=mymax(maxFromLeft[i]+maxFromRight[i],max_value);
        }
        
        return max_value;        

```
 
 AC！

       
  
       

