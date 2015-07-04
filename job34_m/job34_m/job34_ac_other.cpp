#include <stdio.h>

int pow(int a,int b)

{

        int sum,i;

        sum=1;

        if(b==0)

                return 1;

        else

        {

                for(i=0;i<b;i++)

                        sum=sum*a;

                return sum;

        }

}

int main()

{	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

        int n,i,flag,d;

        int a[1000];

        while(scanf("%d",&n)!=EOF)

        {

                for(i=0;i<n;i++)

                        scanf("%d",&a[i]);

                scanf("%d",&d);

                flag=pow(2,d-1)-1;

                if(n>=flag+1)

                {

                        printf("%d",a[flag]);

                        i=1;

                        while(flag+i<n&&i<flag+1)

                        {

                                printf(" %d",a[flag+i]);

                                i++;

                        }

                        printf("\n");

                }

                else

                        printf("EMPTY\n");

        }

        return 0;

}