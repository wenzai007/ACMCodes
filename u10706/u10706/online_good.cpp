
/*  
 *
 *  ������������InitSequenceLength  �ܺã��ܾ���
Sk�ĳ��ȣ�  
k�ķ�Χ  
[1  , 9  ]: k  
[10 , 99 ]: 9 + (k-9)*2  
[100, 999]: 9 + 90*2 + (k-99)*3  
...  

*/  
  
#include <iostream>  
#include <cstdio>  
#include <string>  
  
using namespace std;  
  
#define MAXN 31270  
#define MAXLEN 146000  //��31270 ���ĳ��ȴ����146000
  
unsigned int seqLen[MAXN];  
  
void InitSequenceLength(void)  
{  
    seqLen[0] = 0;  
    unsigned int delta = 1, c = 10, sum = 0;  
  
    int i;  
    for (i = 1; seqLen[i-1] <= 2147483647; i++)  
    {  
        //��iΪ10��100��1000...ʱ��delta��Ҫ��1  
        if (i == c)  
        {  
            delta++;  
            c *= 10;  
        }  
        sum += delta;  //���sum��ʵ����s[k] ��һ����̬�Ķ��� �����ڱ仯
		//�������¼�����ܵĳ���
		//����112123123412345  ��sum�ֱ�Ϊ1  12  123   1234  12345 �ĳ���
		//��seqLen[1~5]Ϊ1 3 6 10 15 �ȵ�����
        seqLen[i] = seqLen[i-1] + sum;  
    }  
}  
  
int BSearch(int low, int high, unsigned int targ)  
{  
    while (low <= high)  
    {  
        int mid = (low + high) / 2;  
  
        if (targ == seqLen[mid])  
        {  
            return seqLen[mid-1];  
        }  
        else if (targ < seqLen[mid])  
        {  
            high = mid - 1;  
        }  
        else  
        {  
            low = mid + 1;  
        }  
    }  
    return seqLen[high];  
}  
  
int main(void)  
{  
    InitSequenceLength();  
    string maxSeq;  
    maxSeq.reserve(MAXLEN+10);  
    int i;  
    for (i = 1; maxSeq.length() < MAXLEN; i++)  
    {  
        char temp[10];  
        sprintf(temp, "%d", i);  
        maxSeq += temp;  /*����ֱ�Ӽ� ���Ҽӵ�\0Ϊֹ
			string (1)	
	string& operator+= (const string& str);
	c-string (2)	
	string& operator+= (const char* s);
	character (3)	
	string& operator+= (char c);
	initializer list (4)	
	string& operator+= (initializer_list<char> il) 

	*/
	}
    int ncases;  
    scanf("%d", &ncases);  
  
    while (ncases-- != 0)  
    {  
        unsigned int p;  
        scanf("%d", &p);  
        int i = BSearch(1, 31268, p);  
        printf("%c\n", maxSeq[p-i-1]);  
    }  
    return 0;  
}  
