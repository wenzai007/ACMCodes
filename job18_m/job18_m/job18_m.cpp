//��֪�����в��ҵĻ��᲻�ᳬʱ���أ����� ֱ�Ӷ��ֲ��Ұ�
//1.�ύ��ʱ����wa  ����#ifndef!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//2.����������ֿ���50 ������100�Ļ�  ��ô����runtime error����sb
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
#define  ONLINE    1
int N,M;
struct student{
	//int num;  д����  ��Ӧ����int �� �޷������   
	//Ӣ����char [] ��    ��������ʲô��ʽ�Ҿ��ǰ������������ʽ
	//�������@@   �� 
	char num[100];
	char name[100];
	char gender[10];
	int age;
	bool operator <(student const b) const{//����д��ô
		return strcmp(num,b.num)<0;
	}
}buf[1002];
int binarySearch(char x[]){
   int left=0;int right=N-1;
	int middle=(left+right)/2;
	while (left<=right){
		int restmp=strcmp(buf[middle].num,x);
		if(restmp==0)return middle;
		else if(restmp<0)left=middle+1;
		else right=middle-1;//Ȼ�����������������֮��
		                    //�������� ��Ҫִ����һ�䣡
		middle=(left+right)/2;
	}
	if(left>right) return -1;

}
int main(){
#ifndef ONLINE
	freopen ("in.txt","r",stdin);
#endif
	
	int age;
	char num[100];
	char name [100];
	char gender[10];
	int i;
	while (scanf("%d",&N)!=EOF&&N){
		for(i=0;i<N;i++){
			scanf("%s%s%s%d",num,name,gender,&age);
  /*		
			buf[i].num=num;//�ַ��������������ֵô����������
			               //����ĵ�ַ�ǲ����Ըı�ģ���
			buf[i].name=name;
			buf[i].gender=gender;
			buf[i].age=age;
  */
			strcpy(buf[i].num,num);
            strcpy(buf[i].name,name);
			strcpy(buf[i].gender,gender);
			buf[i].age=age;
		}
		sort(buf,buf+N);
		scanf("%d",&M);
		for(i=0;i<M;i++){
			scanf("%s",num);
			int tt=binarySearch(num);
			if (tt==-1)printf("No Answer!\n");
			else{
				printf("%s %s %s %d\n",buf[tt].num,buf[tt].name,buf[tt].gender,buf[tt].age);
				
			}
		}


	}
	return 0;//�����ˣ���
}








//for the middle effect
