#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;
int L,N;
int buf[660];

bool cmp(int a,int b) {
return a>b;
}

int totaltmp=0;//�洢���ǵ�ǰ�� ��
// the most important function!

int main(){
freopen ("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
while (scanf("%d%d",&L,&N)!=EOF&&L){

for(int i=0;i<N;i++) scanf("%d",&buf[i]);

sort(buf,buf+N,cmp);

int px;
totaltmp=0;//֮ǰ���ǳ�ʼ��

for(px=0; px<N; px++){//px�����Ʋ���̫�� 
totaltmp+=buf[px];
if (totaltmp>=L) break;
}

if(px==N)printf("impossible\n");
else printf("%d\n",px+1);

}


return 0;
}