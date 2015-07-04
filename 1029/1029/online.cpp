//我去  自己太二了  其实    需要把两个数组放到一个新的数组中去就好了
//啊！！！     真是服了我自己了  太笨了 
//。。。。。  看看这个代码 吧  很好的！！  
#include<iostream>   
#include<stdlib.h>   
#include<stdio.h>   
#include<string.h>   
using namespace std;  
void merge_ab(const long *a,const int len_a,const long *b,const int len_b,long *ab){  
    int i,j,k;  
    i=0;  
    j=0;  
    k=0;  
    while(i<len_a&&j<len_b){  
        if(a[i]<=b[j]){  
            ab[k++]=a[i++];  
        }  
        else{  
            ab[k++]=b[j++];  
        }  
    }  
    if(i==len_a){  
        while(j<len_b)  
            ab[k++]=b[j++];  
    }  
    else{  
        while(i<len_a)  
            ab[k++]=a[i++];  
    }  
}  
int main()  
{  
    int n1,n2,i;  
    scanf("%d",&n1);  
    long *a=new long [n1];  
    for(i=0;i<n1;i++)  
        scanf("%ld",&a[i]);  
    scanf("%d",&n2);  
    long *b=new long [n2];  
    for(i=0;i<n2;i++)  
        scanf("%ld",&b[i]);  
    long *ab=new long[n1+n2];  
    merge_ab(a,n1,b,n2,ab);  
    if((n1+n2)&1==1)  
        printf("%ld\n",ab[(n1+n2+1)/2-1]);  
    else  
        printf("%ld\n",ab[(n1+n2)/2-1]);  
    return 0;  
}  
