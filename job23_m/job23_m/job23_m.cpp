// wa   ԭ�� ������ʧ
//  �ڶ��� wa  Ҳ�Ǿ�����ʧ����
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int dense[200];//�洢Ũ�ȵ�����
int c,n,V,W,P;
int main(){
	//freopen("in.txt","r",stdin);
	while (scanf("%d",&c)!=EOF&&c){
		while (c--!=0){
			scanf("%d%d%d",&n,&V,&W);
			for(int i=0;i<n;i++){
				scanf("%d",&dense[i]);
			}
			sort(dense,dense+n);
			int cnt=0;//һ���м�������
			double densetmp=0;
			if(dense[0]>W) {
				printf("0 0.00\n");
				continue;//��һ������
			}
			densetmp=dense[0];
			int total=dense[0];//��¼�ܵ�Ũ�Ⱥ�
			cnt++;//cnt==1
			//while (densetmp<=W&&cnt<n){//��������˴��󣡣� �����ó���
				// ��Ϊ��������ѭ����15.0000001 ��W��ȽϵĻ�
				//��Ȼ�� ��ȥ�˺���ı����15  ��������������
				//�̶� ����Ӧ��ֹͣ��ʱ��ȴ�����Ľ���ѭ��
				//�Ӷ�ʹ�����ھ��ȵ���ʧ�����µĽ������
				//��������������ó��� �����ó˷������бȽϣ���
			  // Ҳ������densetmp<=W  ����ͬʱ����cnt�������� 
			while (total<=(W*cnt)&&cnt<n){
				total+=dense[cnt];
				cnt++;
				//densetmp=total/cnt;//!!!!!!��������һ������ĵط�
							//����ǿ��ת���� �� Ҳͬ����ʹ�þ���
				     //����ʧ����  ����  10/3 ==3  ��ôdensetmp��
				   //����ֵ��Ϊ  3.000000000 ������3.3333333  
				densetmp=(double )total/cnt;
				
			}
			//if(total<=(W*cnt)){  //���˴�Ҳ��Ӧ���޸�
			if(total>(W*cnt)){
			    cnt--;
				total-=dense[cnt];
				densetmp=(double)total/cnt; //ͬ�����޸�
			}
			printf("%d %.2lf\n",cnt*V,densetmp/100);
		}
	}
	return 0;
}










// effect
