/*��һ����compile error  ����ֱ����begin ��end ��c++ c11��׼�в���
 *����һ���Լ�д����ʲôjb���Ⱑ  ÿ�α���Ҫ��֤ �Ǹ������ǿ���myend�����ߵģ���
 * 

 �����ֿ���һ����ǰд�� ��д��һ��ģ�  �Ź���  
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
#include<math.h>//��cmath ����û��math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;

int c_num;
int id;//��¼ÿһ�εĸ���
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
	   bool flag=false;//�Ƿ����
	   for(i=bid+1;buf[i].l<=mybegin && i<id;i++){//buf[i].l<=mybegin ��仰��Ҫд���������� Ҫд��if����źô�����
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
	   v.push_back(biggest_id);//�±� 
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
			//id++;//�˴�λ�÷Ŵ���
			if(!buf[id].l&&!buf[id].r){
				//id--;//���һ��0 0������
				justdoit();
				break;
			}
			id++;
		}
	}
	return 0;
}

