/*

#include<stdio.h>
void main(){
	int   n;
	int buf[100];
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&buf[i]);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n-i-1;j++){
				if(buf[j]>buf[j+1]){
					int temp=buf[j];
					buf[j]=buf[j+1];
					buf[j+1]=temp;
				}
			}
		}
		for(int  i=0;i<n;i++){
			printf("%d ",buf[i]);
		}
		printf("\n");

	
	}
	
}
  //*/
/*�����ܽ᣺  
 * 1.������������ʱ��һ��
 * ҪҪ�ÿո񽲲�ͬ�����ֽ��зָ�ÿո� ����������Ϊ
 * ��Щ��һ������  �����ָܷ�
 * 2.scanf��������һ��Ҫ����ȷ����һ�������Ƕ��������
 * �ڶ���������Ҫ����ֵ�ı��� ǰ��Ҫ��&���� �������ڴ����
 * ����ָ���������׵�ַ�������� ������Ҫ��&���ţ�
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * */
