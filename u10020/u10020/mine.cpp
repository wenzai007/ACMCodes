/*第一次是compile error  不能直接用begin 和end 在c++ c11标准中不行
 *后来一看自己写的是什么jb玩意啊  每次必须要保证 那个区间是跨在myend的两边的！！
 * 

 后来又看了一遍以前写的 重写了一遍的，  才过了  
 * 
 */

#define for if(0); else for 
#define pf printf
#define sf  scanf
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>//有cmath 但是没有math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;

int c_num;
int id;//记录每一次的个数
struct node{
	int l,r;
	bool operator <(const node &B)const{
		return l<B.l;
	}
}buf[100008];
char ins[20];
int m;
vector <int> v;
int  realend,myend,mybegin;

void justdoit(){
	sort(buf,buf+id);
	mybegin=myend=0;
	realend=m;
	int bid=0;//so that mybegin_id+1=0
	int biggest_id;
	int i=0;
	bool flag;
	while (myend<realend && i<id){
		flag=false;
		for(i=bid;i<id;i++){
			if(buf[i].l<=mybegin && buf[i].r>=mybegin){
				if(buf[i].r>myend){
					biggest_id=i;
					myend=buf[i].r;
					flag=true;
				}
			}
			if(buf[i].l>mybegin){
				bid=i;
				break;
			}
		}
		if(flag==false)
			break;
		else{
			mybegin=myend;
			v.push_back(biggest_id);
		}
	}
	/*
	   while(mybegin<realend && i<id){
	   bool flag=false;//是否更改
	   for(i=bid+1;buf[i].l<=mybegin && i<id;i++){//buf[i].l<=mybegin 这句话不要写在条件里面 要写在if里面才好处理！！
	   now_id=i;
	   if(buf[i].r>myend){//
	   myend=buf[i].r;
	   biggest_id=i;
	   flag=true;
	   }
	   }
	   if(buf[i].l>mybegin&&i<id)
	   break;
	   bid=now_id;
	   mybegin=myend;
	   if(flag==true)
	   v.push_back(biggest_id);//下标 
	   }
	   */

	if(myend<realend){
		pf("0\n");
	}
	else{
		pf("%d\n",v.size());
		for(int i=0;i<v.size();i++){
			pf("%d %d\n",buf[v[i]].l,buf[v[i]].r);
		}
	}
	if(c_num!=0){
		pf("\n");
	}
}
int main(){
	freopen("in.txt","r",stdin);   
	sf("%d",&c_num);
	while(c_num--){
		gets(ins);
		v.clear();
		sf("%d",&m);
		id=0;
		while(true){
			sf("%d%d",&buf[id].l,&buf[id].r);
			//id++;//此处位置放错了
			if(!buf[id].l&&!buf[id].r){
				//id--;//最后一个0 0不能算
				justdoit();
				break;
			}
			id++;
		}
	}
	return 0;
}

