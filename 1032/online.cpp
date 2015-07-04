#include<iostream>   
#include<stdlib.h>   
#include<stdio.h>   
#include<string.h>   
using namespace std;  
const int N=100000;  
typedef struct Node{  //数组下标就是他的地址 所以不用存了
    int next;  
    char val[2];  
}Node;  
int find_sharing(Node * link,int head1,int len1,int head2,int len2){//make len1>=len2   
    int pre=len1-len2;  //参数中有指针  的写法 看看
    int p=head1;  
    while(pre>0){  
        p=link[p].next;  
        pre--;  
    }  
    int q=head2;  
    while(p!=-1){  
        if(p==q)  
            return q;  
        q=link[q].next;  
        p=link[p].next;  
    }  
    return -1;  
}  
int main()  
{  
    Node *link=new Node [N];  
    memset(link,0,sizeof(int)*N);  
    int head1,head2,n,i;  
    scanf("%d%d%d",&head1,&head2,&n);  
    for(i=0;i<n;i++){  
        int addr;  
        char val[2];  
        int add_next;  
        scanf("%d%s%d",&addr,val,&add_next);  
        strcpy(link[addr].val,val);  
        link[addr].next=add_next;  
    }  
    int len1=0,len2=0;  
    int p=head1;  
    while(p!=-1){  
        len1++;  
        p=link[p].next;  
    }  
    p=head2;  
    while(p!=-1){  
        len2++;  
        p=link[p].next;  
    }  
    int res;  
    if(len1>=len2)  
        res=find_sharing(link,head1,len1,head2,len2);  
    else  
        res=find_sharing(link,head2,len2,head1,len1);  
    if(res!=-1)  
        printf("%05d\n",res);  
    else  
        printf("-1\n");  
    return 0;  
}  