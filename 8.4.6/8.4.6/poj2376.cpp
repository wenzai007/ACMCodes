//ע������poj�ϵ���Ŀ ����  ��� ��1��,10������Ļ���1,4���͡�5,10��������
//���Ը������е�����ģ���  ע����һ��  ����Ҫ�ģ������á�1,4���͡�4��10���ģ���
#include <iostream>  
#include <algorithm>  
using namespace std;  
  
const int Max = 25000;  
  
// ����  
int N, T;  
struct Interval {  
    int b, e;  
}I[Max];  
  
// ����  
bool greater( const Interval & i1, const Interval & i2 )  
{  
    return i1.b < i2.b;  
}  
  
int Greedy()  
{  
    int num = 0; // ����������   
    int right = 0; // �Ѹ��������Ҷ˵�  
    int top = 0; // ������  
  
    while( right < T ) {  
        // ѡ������begin���������Ҷ˵������Ǹ�  
        int begin = right + 1; // �����ǵ����  
        for( int i = top; i < N; ++ i ) {  
            if( I[i].b <= begin && I[i].e >= begin )  //��ֹ������߻��߶����ұ�
                right = I[i].e > right ? I[i].e : right;  
            else if( I[i].b > begin ) {  
                top = i;  
                break;  
            }  
        }  
        // û�а���begin������  
        if( begin > right ) break; //��һ��rightû�иı� 
        else ++ num;  
    }  
  
    if( right == T ) return num;  
    else return -1;  
}  
  
int main()  
{	freopen("in.txt","r",stdin);
    scanf( "%d%d", & N, & T );  
    for( int i = 0; i < N; ++ i )  
        scanf( "%d%d", & I[i].b, & I[i].e );  
      
    sort( I, I + N, greater );  
    printf( "%d\n", Greedy() );  
    return 0;  
}  