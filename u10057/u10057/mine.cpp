
/*
 * UVa: 10057 - A mid-summer night's dream.
 * Time: 0.236s
 * Result: Accept
 * Author: D_Double 
 * 
http://files.cnblogs.com/g0feng/%E5%85%B3%E4%BA%8E%E4%B8%AD%E4%BD%8D%E6%95%B0%E5%AE%9A%E7%90%86%E7%9A%84%E4%B8%80%E4%B8%AA%E6%A6%82%E7%8E%87%E8%AF%81%E6%98%8E.pdf

�������ʵ���ǿ���һ������  ��֪���˾���������  ��֪��������������
���ǣ�
������ֵ��С�������У�S(a)��|x(1)-a|+|X(2)-a|+...+|x(n)-a|,
����a��λ�á������a���������Ĺ۲�ֵ������ͬ���ܿ����ҵ���һ��a��ʹ��S(a)��С��
����ֻ�е�a���������Ĺ۲�ֵ������ͬʱ��S(a)�Ŵﵽ��Сֵ������Ĵ𰸾��ǣ�
��nΪ����ʱ��a���м�ֵʹS(a)��С��
��nΪż��ʱ�����м������۲�ֵ�Լ�����֮����κ�ʵ������S(a)����Сֵ�㡣
������λ������S(a)����Сֵ�㡣


�����ҵĲ��Ե�ȴ�ǶԵģ���  ̫������  �м��ʵ������������
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 1000010
using namespace std;
int arr[MAXN];

    int n;

int  cal(int x){
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=abs(arr[i]-x);
	}
	return sum;
}
int main(){
	freopen("in.txt","r",stdin);
    while(~scanf("%d",&n)){
        for(int i=0; i<n; ++i)
            scanf("%d",&arr[i]);

        sort(arr, arr+n);
        
        int mid, left, right;
        int ans_min, ans_num, ans_val;

        if(n%2==0){ // �����ż��������
            left=(n-2)/2;  right=(n)/2;
            
            ans_min=arr[left];
            
            ans_num=0;
            for(int i=left; arr[i]==arr[left]&&i>=0; --i) ++ans_num;
            for(int i=right; arr[i]==arr[right]&&i<n; ++i) ++ans_num;
            
            ans_val = arr[right]-arr[left]+1;
        }
        else{
            mid = (n-1)/2;

            ans_min = arr[mid];

            ans_num=0;
            for(int i=mid; arr[i]==arr[mid]&&i>=0; --i) ++ans_num;
            for(int i=mid+1; arr[i]==arr[mid]&&i<n; ++i) ++ans_num;

            ans_val = 1;
        }
        printf("%d %d %d\n", ans_min, ans_num, ans_val);
		
		for(int i=0;i<n;i++){
			printf("the %dth sum is-->    ",i);
			printf("%d\n",cal(arr[i]));
		}
		if(n%2==0){
			for(int i=arr[left];i<=arr[right];i++){
				printf("the sum between them is--->");
				printf("%d  \n",cal(i));
			}
			printf("hehehe  %d\n",cal(22.54645));
		}
    }
    return 0;
}
