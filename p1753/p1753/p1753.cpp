#include<iostream>
using namespace std;
 
bool map[6][6], find = false;
int step;
int dr[5] = {-1, 0, 0, 0, 1};
int dc[5] = {0, -1, 0, 1, 0};
 
bool isgoal(){                           //  �жϾ�������и����Ƿ�Ϊͬһ����ɫ��
    for(int i = 1; i <= 4; i ++)
        for(int j = 1; j <= 4; j ++)
            if(map[i][j] != map[1][1])
                return false;
    return true;
}
 
void flip(int row, int col){             //  ������(row,col)ʱ��map[][]�ı仯��
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
void dfs(int row, int col, int de+p){     //  ��(row,col)Ϊ�����Ƿ�Ҫ�����ĵ�


    if(dep == step){//�����˵�ʱ������ζ�Ҫֹͣ����
        find = isgoal();//ֻ��dep����step��ʱ��find��ֵ�ſ��ܴ�false��Ϊtrue
        return;
    }
    if(find || row == 5) return;//find ����Ҫ����  �����Ǵ���ģ�
	//û���Ļ� ������������5��ʱ��ҲҪֹͣ

    flip(row, col);      
	print();
	//  Ҫ�Ե�(row,col)���з�����
    if(col < 4) dfs(row, col + 1, dep + 1);
    else dfs(row + 1, 1, dep + 1);

    flip(row, col);                      // ��Ϊ�Ӹ���ĵط������ˣ�����
	print();
	//���ǽ����״̬   ���Ի�ԭ״̬�����Ե�(row,col)���з�����
	//Ȼ�����һ����ʼ�ĵ㿪ʼ������Ҳ����ö�ٵķ�������Ȼ��һ����ԭ�Ĳ��裡��
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
    for(step = 0; step <= 16; step ++){   //  ö��0 ~ 16 ����
        dfs(1, 1, 0);
        if(find) break;
    }
    if(find) cout << step << endl;
    else cout << "Impossible" << endl;
    return 0; 
}