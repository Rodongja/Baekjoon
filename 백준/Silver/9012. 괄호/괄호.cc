#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 괄호

void VPS()
{
    int T;
    cin >> T;
	cin.ignore(); // 개행 문자 제거
 
    for(int i = 0; i < T; i++)
    {
        string str;
        std::getline(cin, str);

        stack<char> s;
        bool ok = true;

        for (char c : str)
        {
            // 스택에 '('입력
            if (c == '(')
            {
                s.push(c);
            }
			// 스택에서 짝 맞추기
			else if (c == ')')
            {
				// 짝이 맞지 않으면 ok = false
                if (s.empty() || s.top() != '(')
                {
                    ok = false;
                    break;
                }
                s.pop();
            }
        }

		// 스택이 비어있지 않으면 짝이 맞지 않음
        if (!s.empty()) ok = false;

        std::cout << (ok ? "YES\n" : "NO\n");
    }
}

int main()
{
    VPS();
	return 0;
}