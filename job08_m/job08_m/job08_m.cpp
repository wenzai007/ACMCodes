
#include<stdio.h>
#include<math.h>
#include<string.h>
int buf[5001][13][32];
#define isleap(x)  ((x%4==0&&x%100!=0)||x%400==0)?1:0  
//���� 1900��������  2000������
int daysofmonth[13][2]={
	0,0,//����ط������˼�һ��0,0 Ȼ���ʹ���Ҳ���һ��Сʱ����
	31,31,
	28,29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	31,31,//8
	30,30,
	31,31,
	30,30,
	31,31
};
char weekname[7][15] ={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"
};// ��������Ȼд���� wednesday��11

char monthName[13][18]={"","January","February","March","April",
					"May","June","July","August","September","October",
					"November","December"};//���� ����ط����˶���Ȼ������һ��Сʱ����
/*   switch�ð����� 
int monthName(char *c){//c��һ���������ƶ�����һ��ָ��ɣ�
	int res;
	switch(*c){
		case *c=="January":res=1;
						break;
		case "February" : res=2;//February  not Febrary
						 break;
		case  "March": res=3;
					   break;
		case  "April":  res=4;
						break;
		case  "May":  res=5;
					  break;
		case  "June" :res =6;
					   break;
		case  "July"; res=7;
					   break;
		case  "August" : res=8;
						break;
		case  "September": res=9;
						   break;
		case  "October" : res=10;
						 break;
		case  "November" : res =11;
						  break;
		case  "December" : res =12;
						   break;
			//�⼸���·�
	}
	return res;				   
}
//*/

struct date{
	int year;
	int month;
	int day;
	void nextday(){
		day++;
		if(day>daysofmonth[month][isleap(year)]){
			day=1;
			month++;
		}
		if(month>12){
			month=1;
			year++;
		}
	}
};
int main(){
	date tmp;
	tmp.year=0;tmp.month=1;tmp.day=1;
	int cnt=0;
	while (tmp.year<5001){
		buf[tmp.year][tmp.month][tmp.day]=cnt;
		tmp.nextday();
		cnt++;
	}
	//char *monStr=NULL;
	char monStr[18];
	int monTmp,dayTmp,yearTmp;
	/*
	while (scanf("%d%s%d",&dayTmp,monStr,&yearTmp)!=EOF){//���Ǽ�!=EOF���µ� Output Limit Exceeded (OLE) : Your program tried to write too much information. 
		                                       //This usually occurs if it goes into a infinite loop.
		//monTmp=monthName(monStr);            //������ѭ�������
		for(int i=0;i<13;i++){
			if(strcmp(monthName[i],monStr)==0) monTmp=i;
		}
		int dif =buf[yearTmp][monTmp][dayTmp];
		 dif=((dif-buf[2014][2][17])%7+7)%7;
		 printf("%s\n",weekname[dif]);
		// int mm=(-2)%7;//����-2
		//printf("%d",mm);
	}
    */
     while (scanf("%d%d%d",&yearTmp,&monTmp,&dayTmp)!=EOF){
	 	int nowday=buf[yearTmp][monTmp][dayTmp];
		nowday-=buf[yearTmp][1][1]-1;//��Ϊ����д��������-1������+��
	   printf("%d\n",nowday);
	 }
    return 0;
	
   //����дreturn0��������
}











//for the middle effect!
