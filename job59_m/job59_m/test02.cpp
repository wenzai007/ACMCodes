#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
void change(int a[]){
	a[2]=444;
}
int main(){
	int a[]={1,2,3,4,5};
    change(a);
	return 0;
}

