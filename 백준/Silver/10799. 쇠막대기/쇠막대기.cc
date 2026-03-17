#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

// 쇠막대기


void program()
{
	string str;
	cin >> str;

	stack<char> s;
	char last = ' ';
	int bar = 0;

	for (int i = 0; i < str.size(); i++)
	{
		s.push(str[i]);

		// 쇠 막대기는 스택만큼 조각 추가
		if (str[i] == ')' && last == '(')
		{
			s.pop();
			s.pop();

			bar += s.size();
		}

		// 쇠 막대기가 끝나는 부분이므로 1조각 추가
		else if (str[i] == ')' && last == ')')
		{
			s.pop();
			s.pop();
			bar++;			
		}

		last = str[i];
	}

	cout << bar << "\n";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}