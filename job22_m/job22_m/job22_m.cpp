//��һ�ν������   Ӧ����5  �����ҵ���3  ԭ����28��

#include<algorithm>
#include<string.h>
#include <stdio.h>
using namespace std;
//int buf[108][2];//��һ���Ҳ��ýṹ���� ���ö�ά����
//ò�Ʋ���   ��ά����Ļ� û�а취���յڶ�ά�Ĵ�С��������
//�����ýṹ��@@@����
struct shows{
	int start;
	int end;
	bool operator <(const shows b)const {
		return end<b.end;
	}
}buf[108];
int n;
int main(){
	//freopen("in.txt","r",stdin);
	while (scanf("%d",&n)!=EOF&&n){
		for(int i=0;i<n;i++){
			scanf("%d%d",&buf[i].start,&buf[i].end);//��ǰΪʲô��Ҫ���һ�ٵ�ʹ���ĸ�͸��Ƭ������������
		}//��һ�����Ǽ���&  �ۼƣ��������ö�ö����
		sort(buf,buf+n);//n���ṹ��
		int cnt=1;//��¼һ���м�����Ŀ
		int endline=buf[0].end;
		for(int i=1;i<n;i++){
		//	if(buf[i].start>endline){ //!!!!������� Ӧ�ô��ڵ���
			if(buf[i].start>=endline){
				cnt++;
				endline=buf[i].end;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
