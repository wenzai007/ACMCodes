#include<stdio.h>  
#define MAX 100   
int Board[MAX][MAX]; // 骨盘号码记录  
int number = 1;  // L型骨牌号  
  
void ChessBoard(int tr , int tc , int x , int y ,int size) {  
    if(size == 1) {  
        return;  
    }  
    int t = number++;  // 骨盘号自增  
    int s = size / 2;  // 分割棋盘  
    // 覆盖四分之一左上角子棋盘  
    if(x < tr + s && y < tc +s) { // 如果特殊方格在此子棋盘中  
        ChessBoard(tr , tc , x , y , s);  
    } else {                      // 如果特殊方格不在此子棋盘中  
        Board[tr+s-1][tc+s-1] = t; // 覆盖右下角  
        ChessBoard(tr , tc , tr+s-1 , tc+s-1 , s); // 覆盖其余的  
    }  
	// 覆盖四分之一右上角子棋盘  
    if(x >= tr+s && y < tc+s) {  
        ChessBoard(tr+s , tc , x , y , s);        
    } else {  
        Board[tr + s][tc + s - 1] = t;  
        ChessBoard(tr+s , tc , tr + s , tc + s - 1 , s);      
    }  
    // 覆盖四分之一左下角子棋盘  
    if(x < tr + s && y >= tc + s) {  
        ChessBoard(tr , tc+s , x , y , s);  
    } else {  
        Board[tr + s - 1][tc + s] = t;  
        ChessBoard(tr , tc+s , tr+s-1 , tc+s , s);  
    }  
    
    // 覆盖四分之一右下角子棋盘  
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
    printf("请先输入size的尺寸：\n");  
    // 方格左上角坐标从（1，1）开始  
    scanf("%d",&size);  
    printf("输入开始覆盖的点坐标x,y\n");  
    scanf("%d %d" , &x , &y);  
    Board[x][y] = number;  
    ChessBoard(1,1,x,y,size);  
    printf("结果为：\n");  
    for(i =1;i<=size;i++) {  
        for(j=1;j<=size;j++) {  
            printf("%3d " , Board[i][j]);  
        }  
        printf("\n");  
    }  
    return 0;   
}  