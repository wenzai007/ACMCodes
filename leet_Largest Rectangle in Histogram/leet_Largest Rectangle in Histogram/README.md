###  注意顺序

```cpp

while((height[s.top()]>=height[i]) && !s.empty())

```
和这个是完全不一样的啊！！！！

```cpp
while(!s.empty() && (height[s.top()]>=height[i])){
```

如果当前的栈是空的，那么再用第一句的时候  会报错 
runtimeerror
而
第二个则不会  因为  先判断栈是否是空的  

<font color="#ed9d49"  size="30px"> 这一点一定要注意啊！！！</font>

另外一个很好的讲解是这里   <http://www.cnblogs.com/lichen782/p/leetcode_Largest_Rectangle_in_Histogram.html>


此外  重构一下代码  下面这段可以这样写

```cpp
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
```

不用for 循环 用while


```cpp
 while(i<height.lenth())
            if(s.empty() || height[s.top()]< height[i]){
                s.push(i++);// notice this is index number
                continue;
                
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
};
```

##  <font color="aaad">这样的话就少了很多代码 也很简洁  唉  我真的还只是一个菜鸟啊  这代码写的真是醉了！！！！</font>


<font color="FD482F" size="25px">关于思路的另外的理解请见 上面的链接以及本子上面的@30
	 </font>




