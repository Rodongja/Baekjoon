#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

// 괄호의 값


void program()
{
	string str;
	cin >> str;

	stack<char>s;
	char last = str[0];
	int ans = 0;
	int temp = 1;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			s.push(str[i]);
			temp *= 2;
		}

		else if (str[i] == '[')
		{
			s.push(str[i]);
			temp *= 3;
		}


		// for문 진입하면서 괄호가 스택에 들어갔으므로 pop을 2번 한다
		else if (str[i] == ')')
		{
			if (last == '(')
			{
				s.pop();
				ans += temp;
				temp /= 2;
			}
			else
			{
				// 스택이 비어있으면 짝이 맞지않으므로 바로 0 출력 후 종료
				// (가 아닌 경우에도 짝이 맞지않으므로 0 출력 후 종료
				if(s.empty() || s.top() != '(')
				{
					cout << 0;
					return;
				}
				s.pop();
				temp /= 2;
			}
		}

		else if (str[i] == ']')
		{
			if (last == '[')
			{
				s.pop();
				ans += temp;
				temp /= 3;
			}
			else
			{
				if(s.empty() || s.top() != '[')
				{
					cout << 0;
					return;
				}
				s.pop();
				temp /= 3;
			}
		}

		last = str[i];
	}

	// 스택이 남아있는 경우 괄호의 짝이 맞지 않음
	if (s.empty())
	{
		cout << ans;
	}
	else
		cout << 0;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}