#include <stdio.h>   
#include <string.h>   
  
int t;  
int n, k;  
int map[20][20];  
int sum;  
  
void mu(int a[][20], int b[][20]) {  
    int sbb[20][20];  
    for (int k = 0; k < n; k ++) {  
    for (int i = 0; i < n; i ++) {  
        int sum = 0;  
        for (int j = 0; j < n; j ++) {  
        sum += a[k][j] * b[j][i];  
        }  
        sbb[k][i] = sum % 9973;  
    }  
    }  
    for (int i = 0; i < n; i ++)  
    for (int j = 0; j < n; j ++)  
        map[i][j] = sbb[i][j];  
}  
void tra(int map[][20], int k) {  
    int bs[20][20];  
    for (int i = 0; i < n; i ++)  
    for (int j = 0; j < n; j ++)  
        bs[i][j] = map[i][j];  
    if (k / 2) {  
    mu(map, map);  
    tra(map, k / 2);  
    if (k % 2)  
    mu(map, bs);  
    }   
}  
int main() {  
	freopen("in.txt","r",stdin);
    scanf("%d", &t);  
    while (t --) {  
    sum = 0;  
    memset(map, 0, sizeof(map));  
    scanf("%d%d", &n, &k);  
    for (int i = 0; i < n; i ++) {  
        for (int j = 0; j < n; j ++) {  
        scanf("%d", &map[i][j]);  
        }  
    }  
    tra(map, k);  
    for (int i = 0; i < n; i ++)  
        sum += map[i][i];  
    printf("%d\n", sum % 9973);  
    }  
    return 0;  
}