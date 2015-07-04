#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<math.h>





#define maxn 1010

#define INF 1e9

#define MIN(a,b) a >= b ? b : a

#define MAX(a,b) a >= b ? a : b



struct bigInt {

        int digit[260]; //maxn/4

        int size;



        void init() {

                memset(digit,0,sizeof(digit));

                size = 0;

        }



        void set(char str[]) {

                init();

                int len = strlen(str);

                int i,j,c = 1,sum = 0;

                for(i = len-1,j = 0; i >= 0; i--) {

                        sum += (str[i] - '0') * c;

                        c *= 10;

                        j++;

                        if(j==4 || i == 0) {

                                digit[size++] = sum;

                                c = 1;

                                j = 0;

                                sum = 0;

                        }



                }

        }



        void set(int x) {

                init();

                int j = 0,sum = 0,c = 1;

                size = 0;

                do {

                        sum += (x % 10)*c;

                        x /= 10;

                        c *= 10;

                        j++;

                        if(j==4) {

                                digit[size++] = sum;

                                sum = 0;

                                c = 1;

                                j = 0;

                        }

                }while(x);



                if(sum || size == 0) digit[size++] = sum;

        

        }

        

        bigInt operator + (const bigInt& b) {

                bigInt ret;

                ret.init();



                int i;

                int maxLen = MAX(size,b.size);

                int sum,carry = 0;

                for(i = 0; i < maxLen; i++ ) {

                        sum = digit[i] + b.digit[i] + carry;

                        

                        carry = sum / 10000;

                        sum %= 10000;

                        

                        ret.digit[ret.size++] = sum; 

                }



                if(carry) ret.digit[ret.size++] = carry;



                return ret;

        }



        bigInt operator + (int x) {

                bigInt ret;

                ret.init();

                ret.digit[0] += x;

                int carry = ret.digit[0] / 10000;

                ret.digit[0] %= 10000;

                int i = 1;

                while(carry) {

                        ret.digit[i] += carry;

                        carry = ret.digit[i] / 10000;

                        ret.digit[i] %= 10000;

                        i++;

                }

                return ret;

        }

        

        bigInt operator * (int x) {

                bigInt ret;

                ret.init();



                int i;

                int sum,carry = 0;

                for(i = 0; i < size; i++ ) {

                        sum = digit[i] * x + carry;

                        

                        carry = sum / 10000;

                        sum %= 10000;

                        

                        ret.digit[ret.size++] = sum; 

                }



                if(carry) ret.digit[ret.size++] = carry;



                return ret;

        }



        bigInt operator / (int x) {

                bigInt ret;

                ret.init();



                int i;

                int remainder = 0;

                int t,r;

                for(i = size-1; i >= 0; i-- ) {

                        t = (remainder * 10000 + digit[i]) / x;

                        ret.digit[i] = t;

                        r = (remainder * 10000 + digit[i]) % x;

                        remainder = r;

                }



                for(i = size - 1; i >= 0; i--)

                        if(ret.digit[i]) {

                                ret.size = i;

                                break;

                        }

                ret.size++;



                return ret;

        }

        

        int operator % (int x) {

                int i;

                int remainder = 0;

                int t,r;

                for(i = size-1; i >= 0; i-- ) {

                        t = (remainder * 10000 + digit[i]) / x;

                        r = (remainder * 10000 + digit[i]) % x;

                        remainder = r;

                }



                return remainder;

        }



        void output() {

                int i;

                for(i = size - 1; i >= 0; i--)

                        if(i == size - 1) printf("%d",digit[i]);

                        else printf("%04d",digit[i]);

                printf("\n");

        }





};





char str[maxn];

int ans[10000];





int main()

{

        #ifndef ONLINE_JUDGE

                freopen("in.txt","r",stdin);

        #endif

        

        int n;

        int i;

        int size;

        bigInt a,sum,c,t;

        while(scanf("%s",str) != EOF) {

                a.set(str);

                size = 0;

                do {

                        ans[size++] = a % 2;

                        a = a / 2;

                }while( !(a.digit[0] == 0 && a.size == 1) );

                

                sum.init();

                for(i = 0; i < size; i++) {

                        t.set(ans[i]);

                        sum = sum * 2 + t;

                }

                sum.output();

        

        }



        return 0;

}