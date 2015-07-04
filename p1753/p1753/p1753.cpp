#include<iostream>
using namespace std;
 
bool map[6][6], find = false;
int step;
int dr[5] = {-1, 0, 0, 0, 1};
int dc[5] = {0, -1, 0, 1, 0};
 
bool isgoal(){                           //  判断矩阵的所有格子是否为同一个颜色。
    for(int i = 1; i <= 4; i ++)
        for(int j = 1; j <= 4; j ++)
            if(map[i][j] != map[1][1])
                return false;
    return true;
}
 
void flip(int row, int col){             //  翻动点(row,col)时的map[][]的变化。
    for(int i = 0; i < 5; i ++){
        int r = row + dr[i];
        int c = col + dc[i];
        map[r][c] = !map[r][c];
    }
}
 
void print(){
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			printf("%d ",map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void dfs(int row, int col, int de+p){     //  点(row,col)为现在是否要操作的点


    if(dep == step){//当满了的时候不论如何都要停止就是
        find = isgoal();//只有dep等于step的时候find的值才可能从false变为true
        return;
    }
    if(find || row == 5) return;//find 必须要加上  否则是错误的！
	//没满的话 但是行数到了5的时候也要停止

    flip(row, col);      
	print();
	//  要对点(row,col)进行翻动。
    if(col < 4) dfs(row, col + 1, dep + 1);
    else dfs(row + 1, 1, dep + 1);

    flip(row, col);                      // 因为从更深的地方出来了，所以
	print();
	//不是结果的状态   所以还原状态，不对点(row,col)进行翻动。
	//然后对下一个开始的点开始翻动，也就是枚举的方法，必然有一个还原的步骤！！
    if(col < 4) dfs(row, col + 1, dep);
    else dfs(row + 1, 1, dep);
}
 
int main(){
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
    char c;
    for(int i = 1; i <= 4; i ++)
        for(int j = 1; j <= 4; j ++){
            cin >> c;
            if(c == 'b') map[i][j] = true;
       }
    for(step = 0; step <= 16; step ++){   //  枚举0 ~ 16 步。
        dfs(1, 1, 0);
        if(find) break;
    }
    if(find) cout << step << endl;
    else cout << "Impossible" << endl;
    return 0; 
}