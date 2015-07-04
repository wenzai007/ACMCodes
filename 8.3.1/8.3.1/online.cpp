#include<stdio.h>  
#define MAX 100   
int Board[MAX][MAX]; // ���̺����¼  
int number = 1;  // L�͹��ƺ�  
  
void ChessBoard(int tr , int tc , int x , int y ,int size) {  
    if(size == 1) {  
        return;  
    }  
    int t = number++;  // ���̺�����  
    int s = size / 2;  // �ָ�����  
    // �����ķ�֮һ���Ͻ�������  
    if(x < tr + s && y < tc +s) { // ������ⷽ���ڴ���������  
        ChessBoard(tr , tc , x , y , s);  
    } else {                      // ������ⷽ���ڴ���������  
        Board[tr+s-1][tc+s-1] = t; // �������½�  
        ChessBoard(tr , tc , tr+s-1 , tc+s-1 , s); // ���������  
    }  
	// �����ķ�֮һ���Ͻ�������  
    if(x >= tr+s && y < tc+s) {  
        ChessBoard(tr+s , tc , x , y , s);        
    } else {  
        Board[tr + s][tc + s - 1] = t;  
        ChessBoard(tr+s , tc , tr + s , tc + s - 1 , s);      
    }  
    // �����ķ�֮һ���½�������  
    if(x < tr + s && y >= tc + s) {  
        ChessBoard(tr , tc+s , x , y , s);  
    } else {  
        Board[tr + s - 1][tc + s] = t;  
        ChessBoard(tr , tc+s , tr+s-1 , tc+s , s);  
    }  
    
    // �����ķ�֮һ���½�������  
    if(x >= tr+s && y >= tc+s) {  
        ChessBoard(tr+s , tc+s , x , y , s);  
    } else {  
        Board[tr + s][tc + s] = t;  
        ChessBoard(tr+s , tc+s , tr + s , tc + s , s);            
    }  
  
}  
  
int main() {  
    int size , x , y;  
    int i , j;  
    printf("��������size�ĳߴ磺\n");  
    // �������Ͻ�����ӣ�1��1����ʼ  
    scanf("%d",&size);  
    printf("���뿪ʼ���ǵĵ�����x,y\n");  
    scanf("%d %d" , &x , &y);  
    Board[x][y] = number;  
    ChessBoard(1,1,x,y,size);  
    printf("���Ϊ��\n");  
    for(i =1;i<=size;i++) {  
        for(j=1;j<=size;j++) {  
            printf("%3d " , Board[i][j]);  
        }  
        printf("\n");  
    }  
    return 0;   
}  