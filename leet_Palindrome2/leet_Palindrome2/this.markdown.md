#Something of this question
![Mou icon](http://25.io/mou/Mou_128.png)

>this is  a fucking good editor I love it so much!!  

	this could be in the frame
	
####Tables
	
column1 | colume 2 | colume 3
------- | -------- | --------
c1		  |		c2   |  dfsad
 daadf  |dfjaifkf|adsf
 asdf;as| asdjflk|asdf
 
 
 初始的时候
 凡是求最优解的，一般都是走DP的路线。这一题也不例外。首先求dp函数，

定义函数
D[i,n] = 区间[i,n]之间最小的cut数，n为字符串长度

    a   b   a   b   b   b   a   b   b   a   b   a
                         i                              n
如果现在求[i,n]之间的最优解？应该是多少？简单看一看，至少有下面一个解


    a   b   a   b   b   b   a   b   b   a   b   a
                    i               j   j+1  	n

此时  D[i,n] = min(D[i, j] + D[j+1,n])  i<=j <n。这是个二维的函数，实际写代码时维护比较麻烦。所以要转换成一维DP。如果每次，从i往右扫描，每找到一个回文就算一次DP的话，就可以转换为
D[i] = 区间[i,n]之间最小的cut数，n为字符串长度， 则,

D[i] = min(1+D[j+1] )    i<=j <n

有个转移函数之后，一个问题出现了，就是如何判断[i,j]是否是回文？每次都从i到j比较一遍？太浪费了，这里也是一个DP问题。
定义函数
P[i][j] = true if [i,j]为回文

那么
P[i][j] = str[i] == str[j] && P[i+1][j-1];

基于以上分析，实现如下：
 
```cpp

        for(int i=0;i<len;i++){
            cuts[i]=len-i-1;//所以cuts[len-1]= -1 
        }
```
这个地方是初始化啊 动归的初始化是很关键的东西！

然后进行相应的东西

```cpp

bool palin[len-1][len-1];
```
这个是判断回文的二位数组  所以下面的这个东西它是有两个动归的过程   一个是判断回文的动态规划的过程，一个是判断cuts数组的过程   简直是碉堡了！！

```cpp


```



