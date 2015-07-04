#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
using namespace std;
#define MAXN 100000

int  t , n;
long long  num[MAXN];//����ĳһ��ֵ������

//����ʼ��
void init(){
    long long i , j , k , tmp;//long longע��
    memset(num , 0 , sizeof(num));//��ʼ��
    for(i = 1 ; i <= 5 ; i++){//ö��λ�������5λ����
        for(j = pow((double)10,(int)i-1) ; j < pow((double)10,(int)i) ; j++){
            num[j] = num[j-1] ;//�����֮ǰ��һ����λ��  ������Ҫ��1��ʼ

			tmp = (j-pow((double)10,(int)i-1)+1)*i;//��ǰ���λ���ж���λ
			//����˵��ǰ��120 ��ô����120-100+1   100��120 ����100��  Ȼ�����3         
            for(k = 1 ; k < i ; k++)
                tmp +=(pow((double)10,(int)k)-pow((double)10,(int)k-1))*k;//�����֮ǰ�����е�λ������һ���
            num[j] += tmp;
        }
    }
}

void solve(){
    int i , j , k , pos , ans;
    //�ҵ�posλ��
    for(i = 1 ; i < MAXN ; i++){
        if(n > num[i-1] && n <= num[i]){
            pos = i ; break;
        }
    }
    //����
    int cnt = n-num[pos-1] ; int sum = 0;
    int len , tmp , tmp_j;
    for(j = 1 ; j <= pos ; j++){
        tmp_j = j;
        for(i = tmp_j , len = 0 ; i != 0 ; i/=10) len++;
        for(k = len-1; k >= 0 ;k--){
            ans = tmp_j/pow((double)10,(int)k) ; sum++;
            if(sum == cnt){            
                printf("%d\n" , ans);
                return;
            }
            tmp = pow((double)10,(int)k) ; tmp_j %= tmp;
        }
    } 
}

int main(){
    //freopen("input.txt" , "r" , stdin);
    init() ; scanf("%d" , &t); 
    while(t--){
        scanf("%d" , &n) ; solve();
    }
    return 0;
}
