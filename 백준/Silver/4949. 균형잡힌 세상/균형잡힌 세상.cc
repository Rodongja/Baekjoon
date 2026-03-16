#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

// 균형잡힌 세상

void check(string str)
{
	stack<char> s;

	for (int i = 0; i < str.size(); i++)
	{
		// (,{,[가 들어가면 push
		if (str[i] == '(' || str[i] == '[')
		{
			s.push(str[i]);
		}

		// ),},]인 경우
		else if (str[i] == ')' || str[i] == ']')
		{
			// 여는 괄호가 없는데 닫는 괄호가 나온 경우
			if (s.size() == 0)
			{
				cout << "no" << "\n";
				return;
			}

			// 미스매칭
			else if (s.top() == '(' && str[i] != ')')
			{
				cout << "no" << "\n";
				return;
			}

			else if (s.top() == '[' && str[i] != ']')
			{
				cout << "no" << "\n";
				return;
			}

			// 나머지의 경우 마지막 괄호를 지운다
			else
			{
				s.pop();
			}
		}
	}

	// 검사 후 스택이 빈 경우
	if (s.empty())
	{
		cout << "yes" << "\n";
	}
	// 스택이 남아있는 경우
	else
	{
		cout << "no" << "\n";
	}
}

void program()
{
	string str;
	
	while (str != ".")
	{
		getline(cin, str);
		
		if (str == ".")
		{
			break;
		}

		check(str);
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}