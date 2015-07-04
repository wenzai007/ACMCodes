//题目是保证了一定会有解的  所以  不用担心别的那些个复杂的情况
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


char instr[300];
char word[300];
int cnum;
int id;
int myend;
int L;
struct file {
	char str[300];
	int len;
	bool operator <(const file &B) const{
		return len<B.len;
	}
}buf[300];


bool  check(char *word){
	int cnt=0;
	bool  flag;
	bool used[300]={0};//初始化为false;
	char a[300];
	for(int i=0;i<id;i++){
		flag=false;
		if(!used[i]){
			for(int j=myend;j>=0;j--){
				if(!used[j]){
					if(buf[i].len+buf[j].len==L){
						strcpy(a,buf[i].str);
						strcat(a,buf[j].str);
						if(strcmp(a,word)==0){
							used[i]=used[j]=true;
							flag=true;
							break;
						}
						strcpy(a,buf[j].str);
						strcat(a,buf[i].str);
						if(strcmp(a,word)==0){
							used[i]=used[j]=true;
							flag=true;
							break;
						}

					}
					else if(buf[i].len+buf[j].len<L)
						break;//停止没必要的检测
				}
			}
		}
		if(flag){
			cnt++;
		}
	}
	if(cnt==id/2)
		return true;
	else 
		return false;
}

void output(){
	printf("%s\n",word);
	if(cnum!=0)
		printf("\n");
}
void workout(){
	sort(buf,buf+id);
	myend = id-1;//最后一个
	L=buf[0].len+buf[myend].len;
	for(int i=0;buf[i].len==buf[0].len;i++){
		for(int j=myend;buf[j].len==buf[myend].len;j--){
			strcpy(word,buf[i].str);
			strcat(word,buf[j].str);
			if(check(word)){
				output();
				return;
			}
			strcpy(word,buf[j].str);
			strcat(word,buf[i].str);
			if(check(word)){
				output();
				return;
			}
		}
	}

}

int main(){
	freopen("in.txt","r",stdin);   
	scanf("%d",&cnum);
	gets(instr);// delete the br (line feed code ) 
	gets(instr);//  the first  space 
	while (cnum--){
		id=0;
		while(true){
			if(!gets(instr))
				break;
			if(strcmp(instr,"")==0)// 读到空格输出并且进行下一次读入
				//workout();
				break;
			strcpy(buf[id].str,instr);
			buf[id].len=strlen(instr);
			id++;
		}
		workout();
	}

	return 0;

}


