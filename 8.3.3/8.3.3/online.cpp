#include"stdio.h"  
#include"stdlib.h"  
  
struct Point{  
    int cap;  
    int x;  
    int y;  
    double k;  
}p[10000];  
  
int t;  
  
struct Node{  
    struct Point gho;  
    struct Point hug;  
}ans[10000];  
  
int com(const void *a,const void*b){  
    return (int)(((struct Point *)a)->k - ((struct Point *)b)->k);  
}  
  
void Ghost(int l,int h){  
  
    if(l < h){                                                                  //�������ڴ�����������ʱ�ݹ�  
    struct Point lower = {p[l].x,p[l].y};  
    int sign = l,flag = 0,g = h;  
    for(int i = l + 1; i <= h ; i ++){                                          //Ѱ�Ҵ��������½ǵĵ�  
        if(lower.y < p[i].y || (lower.y == p[i].y && lower.x < p[i].x)){  
            lower = p[i];  
            sign = i;  
        }  
    }  
    p[sign] = p[l];  
    p[l] = lower;                                                              //������һ������������ٵĵ�  
  
    for(int i = l + 1 ; i <= h ; i ++){                                        //�������������½ǵ��б��  
        p[i].k = (double)(p[i].y - p[l].y)/(p[i].x - p[l].x);  
        if(p[i].x - p[l].x == 0)p[i].k = 10000;  
    }  
    qsort(p + l + 1,h - l,sizeof(struct Point),com);                           //����б�ʴ�С�����������  
    for(int i = l ; i <= h ; i ++ ){                                           //�ҵ�����ָ���  
        flag += p[i].cap;  
        if(!flag){  
            g = i;  
            break;  
        }  
    }  
    if(p[g].cap == -1){                                                        //�����  
        ans[t].gho = p[g];  
        ans[t].hug = p[l];  
    }  
    else  
    {  
        ans[t].gho = p[l];  
        ans[t].hug = p[g];  
    }  
    t ++;  
  
    Ghost(l+1,g-1);                                                            //�ݹ������������  
    Ghost(g+1,h);  
    }  
    return;  
}  
  
int main(void){  
    int n;  
    t = 0;  
    scanf("%d",&n);  
    if(!(n%2)){  
        for(int i = 0 ; i < n ; i ++){  
            scanf("%d %d %d",&(p[i].x),&(p[i].y),&(p[i].cap));  
        }  
        Ghost(0,n - 1);  
        for(int i = 0 ; i < t ; i ++){  
            printf("%d:(%d|%d,%d)<->(%d|%d,%d)\n",i,ans[i].gho.cap,ans[i].gho.x,ans[i].gho.y,  
                ans[i].hug.cap,ans[i].hug.x,ans[i].hug.y);  
        }  
    }  
    return 0;  
}  