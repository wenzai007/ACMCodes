#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<string>
#include<ctype.h>

#include<algorithm>
#include<math.h>>//有cmath 但是没有math

#include<stack>
#include<queue>
#include<vector>// add graghs  
#include<map>

#include<time.h>
using namespace std;

int main(){

	char str[] = "now#the tiger is coming#please run away";  
	char delims[] = "#";  
	char *result = NULL;  

	result = strtok( str, delims );  

	while( result != NULL )  
	{  
		printf( "result is \"%s\"\n", result );  
		result = strtok( NULL, delims );  
	}  
	return 0;
}




