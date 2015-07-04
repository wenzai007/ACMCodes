//超时的都改成素数筛做吧

//AC

#include <iostream>
#include <stdio.h>
#include <stack>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

using namespace std;

#define N 104730

bool prime[N];

void initPrime_s()
{
	int i, j, T = sqrt((double)N) + 1;
	memset(prime, 1, sizeof(prime));
	for(i = 2; i < T; ++i)
	{
		if(prime)
		{
			for(j = i + i; j < N; j += i)
			{
				prime[j] = false;
			}
		}
	}
	prime[0] = prime[1] = false;
}

int main()
{
	int k;
	initPrime_s();
	while(cin>>k)
	{
		int n=0;
		int i;
		for(i=0;i<N;i++)
			if(prime)
			{
				++n;
				if(n == k)
					break;
			}
		cout<<i<<endl;
	}
	return 0;
}

