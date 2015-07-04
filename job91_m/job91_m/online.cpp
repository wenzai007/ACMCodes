#include <iostream>

#include <cstring>

#include<stdio.h>

#include <algorithm>

using namespace std;



int main()

{

   char s[7];

   while (cin>>s){

      cout<<s<<endl;

      while (next_permutation(s,s+strlen(s)))

         printf("%s\n",s);

      cout<<endl;

   }

   return 0;

}