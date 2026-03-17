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

	// 스택
	stack<char> s;
	// 이전 문자 저장
	char last = ' ';
	// 쇠 막대기 조각 수
	int bar = 0;

	for (int i = 0; i < str.size(); i++)
	{
		s.push(str[i]);

		if (str[i] == ')' && last == '(')
		{
			// ()는 레이저 이므로 스택에서 () 제거
			s.pop();
			s.pop();

			// 쇠 막대기는 스택의 길이만큼 조각 추가
			bar += s.size();
		}

		// 쇠 막대기가 끝나는 부분이므로 1조각 추가
		else if (str[i] == ')' && last == ')')
		{
			// ()는 막대기 이므로 스택에서 () 제거한 후 1조각 추가
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