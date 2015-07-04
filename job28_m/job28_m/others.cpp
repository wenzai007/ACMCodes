
#include<stdio.h>

int main()

{

	int n,i,size,a[10000];

	char str;

	while(scanf("%d",&n))

	{

		if((n<=0)||(n>10000))

		{

			return 0;

		}

		size=0;

		for(i=0;i<n;i++)

		{

			scanf(" %c\n",&str);

			if(str=='P')

			{

				scanf("%d",&a[size++]);

			}

			else if(str=='O')

			{

				if(size)

				{

					size--;

				}

			}

			else if(str=='A')

			{

				if(size)

				{

					printf("%d\n",a[size-1]);

				}

				else

				{

					printf("E\n");

				}

			}

		}

		printf("\n");

	}

	return 0;

}
