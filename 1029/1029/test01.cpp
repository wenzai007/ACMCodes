


//��һ��  �𰸴���0�֣�  ԭ��   û�а�freopenȥ������
// ������21��  ��4��  ����case ���г�ʱ����
//ԭ���������Ϊ  �������� ������������  ������1��
//������
#define for if(0); else for 
//#define win32 1
#ifdef  win32
#define LL _int64
#else 
#define  LL  long long 
#endif

#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>>//��cmath ����û��math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;

long long  buf1[1000008];
int main(){
		int idx=0;
		for(int i=0;i<6;i++){
			scanf("%lld",&buf1[idx++]);
		}
	return 0;
}
