     #include "stdio.h"
    int main(){
    int A[1002],n;
    while(scanf("%d",&n)&&n!=0){
    int counter=0,G,i;
    for(i=1;i<=n;i++) scanf("%d",&A[i]);
    scanf("%d",&G);
    for(i=1;i<=n;i++) if(A[i]==G)counter++;
    printf("%d\n",counter);
    }
    return 1;
    }

