//��Ҫ����ôȥ�洢�������һ�������� ��F[i]  J[i] �ͱ�ֵ������
//Ŷ  �����ýṹ������
//Ҳ������ ��ά����  ���� int [n][3];
//��������ǲ�ͬ�����͵Ļ�  ò��ֻ�����Ǹ��ṹ���Լ���̫���õ�
//vector�˰�
//1.   wrong answer! �ٿ��������
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct  cases {
	double J,F; //  ������int Ӧ�� ��Ϊ��ȥ�����ֿ�����double��
	double rate;
	bool  operator <(const cases b)const{
		return rate>b.rate;//�ô����ǰ��
	}
}buf[2000];//����һ��
int main(){
//	freopen("in.txt","r",stdin);
	double Ftotal;
	int num;
	double jtmp,ftmp;
	while (scanf("%lf%d",&Ftotal,&num)!=EOF){
		if(Ftotal==-1&&num==-1)break;
		for(int i=0;i<num;i++){
			scanf("%lf%lf",&jtmp,&ftmp);
			buf[i].J=jtmp;
			buf[i].F=ftmp;
			buf[i].rate=jtmp/ftmp;
		}
		sort(buf,buf+num);
		double res=0;
	//	while (Ftotal>0){//!!��仰��ʵ����ȥ���ģ�����仰����ȥ��
		//��Ϊ ������������� ���Ǿͻ�ɶ����һ�����
		//�Ǿ��ǵ����ǵ�ǮF��û�л����ʱ�� �����ǻ��� Ҳ����J�Ѿ�
		//û���˵�ʱ����ô  while �жϵ�ʱ��ͻ����ѭ��
		//�� i=0  ������������ Ȼ���ظ��ļ��� ��� 
		//c�Ӷ������� wrong answer 
			for(int i=0;i<num;i++){
				if(Ftotal>0){
					if(Ftotal>=buf[i].F){
						Ftotal-=buf[i].F;
						res+=buf[i].J;
					}
					else {
						//Ftotal=0;��仰��λ�÷Ŵ�ط��� ��Ȼ��Ҫ��˵��һ�仰
						//��������İ�����
						res+=(buf[i].J)*Ftotal/buf[i].F;
						Ftotal=0;
					}
				}
				else break;
			}
	//	} ������ȥ��while �����Ǵ�ģ�
		//printf("%.3lf\n",&res);//��֪���Բ��ԣ������ȱ�ܸ�ʽ�� ɵ��
// �ȿ����ĸ�    ���������������ôд�ģ���  &��ʲôjb
        printf("%.3lf\n",res);//��������д�ģ���
	}
	return 0;
}










//  middle effect















//  for the middle effect
