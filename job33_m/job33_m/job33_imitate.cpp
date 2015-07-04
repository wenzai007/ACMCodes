#include<stdio.h>
#include<math.h>
//用公式  不用循环
int main(){
	freopen("in.txt","r",stdin);
	int m,n;
	while (scanf("%d%d",&m,&n)!=EOF){
		if(m==0&&n==0)break;
		int count=0;
		//int deep1=(int)(log(m)/log(2)+1);
		//int deep2=(int)(log(n)/log(2))+1;//要进行转换
		int deep1=(int)(log((double)m)/log(2.0)+1);
		int deep2=(int)(log((double)n)/log(2.0))+1;

		int dif=deep2-deep1;
		//count+=(int)(pow(2,dif)-1);
		count+=(int)(pow(2.0,dif)-1);
		int leftleaf,rightleaf;
		leftleaf=rightleaf=m;
		for(int i=1;i<=dif;i++){
			leftleaf=leftleaf*2;
			rightleaf=rightleaf*2+1;
		}
		if(rightleaf<=n)
			count+=rightleaf-leftleaf+1;
		else if(n>=leftleaf)
			count+=n-leftleaf+1;
		//否则不加 任何东西
		printf("%d\n",count);
	}
	return 0;
}

