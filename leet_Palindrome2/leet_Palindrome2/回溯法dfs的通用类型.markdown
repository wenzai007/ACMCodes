#回溯法的通用形式

```cpp
void partition(vector <vector<string> > &res ,vector<string> &list,string &s){// 不是全局的  所以三个变量都要加上
            if(s.length()==0){
                res.push_back(list);
                return;
            }
            
            for(int i=1;i<=s.length(); i++){
                string subs=s.substr(0,i);//>0,  连续i个字符
                if(ispalin(subs)){
                    list.push_back(subs);
                    string rem=s.substr(i-1);//>i-1 从第i个开始
                    partition(res, list,rem);
                    list.pop_back();//两个作用 1如果放进去了list 那么返回的时候一路清空 最后这个list全部清空 可以为下一轮遍历做准备 2  如果这个list 没有 成功，那么拿出来上一个subs，遍历下一种可能的组合
                }
            }
            
        }

```

###首先， 前面有一个成功的判断，然后停止 返回本身的程序 即
```cpp
if(s.length()==0){
                res.push_back(list);
                return;
            }

```
###但是这个地方注意一下，不论是成功还是失败 （满足整体是一个回文） 都是返回  函数    失败的话  在下面的for  循环结束的时候也会返回

  **注意这个地方**
  *dfs或者回溯法  都会有这个  前面加一个list.push_back(subs); 递归之后的下一个语句一定是 从集合中删除这个元素  list.pop_back()*
  
  作用有两个   
  > 两个作用 
  			
  			1. 如果放进去了list 那么返回的时候一路清空
  			 最后这个list全部清空 可以为下一轮遍历做准备
  			2.  如果这个list 没有 成功，那么说明上一个放进去
  			的不合适，应该拿出来进行下一种组合，所以拿出来
  			上一个subs，  遍历下一种可能的组合 
  			
 