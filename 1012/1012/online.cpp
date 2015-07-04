#include<iostream>   
#include<string>   
using namespace std;  
#define N 2000   
int main()  
{  freopen("in.txt","r",stdin);
	int n,m,i,j,k,t;  
	int stu[N][5];  
	int sear[N];  
	char courses[4]={'A','C','M','E'};  
	cin>>n;  
	cin>>m;  
	for(i=0;i<n;i++){  
		cin>>stu[i][0];  
		cin>>stu[i][2];  
		cin>>stu[i][3];  
		cin>>stu[i][4];  
		stu[i][1]=stu[i][2]+stu[i][3]+stu[i][4];  
	}  
	for(i=0;i<m;i++){  
		cin>>sear[i];  
	}  
	for(i=0;i<m;i++){  
		int high[4]={1,1,1,1};  
		int score[4],flag=0;  
		for(j=0;j<n;j++){  
			if(sear[i]==stu[j][0]){  
				flag=1;  
				score[0]=stu[j][1];  
				score[1]=stu[j][2];  
				score[2]=stu[j][3];  
				score[3]=stu[j][4];  
				for(k=0;k<n;k++){  
					if(sear[i]!=stu[k][0]){  
						if(score[0]<stu[k][1])  
							high[0]++;  
						if(score[1]<stu[k][2])  
							high[1]++;  
						if(score[2]<stu[k][3])  
							high[2]++;  
						if(score[3]<stu[k][4])  
							high[3]++;  
					}  
				}  
				int highest=N+1,cour;  
				for(t=0;t<=3;t++){  
					if(high[t]<highest){  
						highest=high[t];  
						cour=t;  
					}  
				}  
				cout<<highest<<" "<<courses[cour]<<endl;  
				break;  
			}  
		}  
		if(0==flag)  
			cout<<"N/A"<<endl;  
	}  
	return 0;  
}