
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;

string str; 
stack<int> s;

bool IsDigit(char ch)
{
	int a = ch - '0';
	return a >= 0 && a <= 9; 
}

int GetSign(char ch)
{
	int f;
	if (ch == '+')
	{
		f = 1;
	}
	else if (ch == '-')
	{
		f = -1;
	}
	else if (ch == '*')
	{
		f = 2;
	}
	else if (ch == '/')
	{
		f = 3;
	}
	return f;
}

int main()
{	freopen ("in.txt","r",stdin);
	int i;
	int f;                        // f是下一个相邻的数的符号
	int sum;
	while (cin >> str)
	{
		int len = str.length();
		i = 0;
		(str[0] == '-')? f = -1 : f = 1;
		while (i < len)
		{
			sum = 0;
			// 取数
			while (i < len && IsDigit(str[i]))
			{
				sum = sum * 10 + str[i] - '0';
				i++; 
			}
			if (f == 1 || f == -1)
			{
				sum *= f;
				s.push(sum);
			}
			else if (f == 2)
			{
				int a = s.top();
				s.pop();
				s.push(a*sum);
			}
			else if (f == 3) 
			{
				int b = s.top();
				s.pop();
				s.push(b/sum);
			}

			if (i >= len)
			{
				break;
			}
			f = GetSign(str[i]);                // 获取下一个数的符号
			i++;
		}
		// 算和
		sum = 0;
		while (!s.empty())
		{
			int a = s.top();
			s.pop();
			sum += a;
		}          
		cout << sum << endl;
	}
	return 0;
}