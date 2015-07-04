#include <stdio.h>  
#include <math.h>  
#include <string.h>  
int MSize, N;  
bool list[10010];  
int hash[10100];  
bool IsPrime(int num)  
{  
    if(num == 1)  
    {  
        return false;  
    }  
    else if(num == 2)  
    {  
        return true;  
    }  
    else if(num % 2 == 0)  
    {  
        return false;  
    }  
    bool res = true;  
    int temp = sqrt((double)num);  
    for(int i = 3; i <= temp; i += 2)  
    {  
        if(num % i == 0)  
        {  
            res = false;  
            break;  
        }  
    }  
    return res;  
}  
int main()  
{  freopen("in.txt","r",stdin);
    while(scanf("%d %d", &MSize, &N) != EOF)  
    {  
        memset(list, false, sizeof(list)); //����Ǽ�¼��Щ���ù��� 
        while(!IsPrime(MSize))  
        {  
            MSize++;  
        }  
        int temp,index;  
        for(int i = 0; i < N; i++)  
        {  
            scanf("%d", &temp);  
            hash[i] = -1;  
            int j = 0;  
            for(int j = 0; j < MSize; j++)  //�ܺõĴ���ʽ ��jΪ0
				//Ȼ�����ж��Ƿ��һ�ξ��������  
            {  
                index = ((temp % MSize) + j * j) % MSize;  
                if(!list[index])  
                {  
                    list[index] = true;  
                    hash[i] = index;  
                    break;  
                }  
            }  
        }  
        printf("%d", hash[0]);  
        for(int i = 1; i < N; i++)  
        {  
            if(hash[i] == -1)  
            {  
                printf(" -");  
            }  
            else  
            {  
                printf(" %d", hash[i]);  
            }  
        }  
        printf("\n");  
    }  
    return 0;  
}  
