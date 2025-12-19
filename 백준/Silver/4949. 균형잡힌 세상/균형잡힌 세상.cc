#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 균형잡힌 세계

void VPS()
{
    string str = "";
	// 첫 번째 문자열 입력
    getline(cin, str);

    while (str != ".")
    {

        stack<char> s;
        bool ok = true;

        for (char c : str)
        {
            // 스택에 '(', '[' 입력
            if (c == '(' || c == '[')
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
            else if (c == ']')
            {
                if (s.empty() || s.top() != '[')
                {
                    ok = false;
                    break;
                }
                s.pop();
            }
        }

		// 스택이 비어있지 않으면 짝이 맞지 않음
        if (!s.empty()) ok = false;

        cout << (ok ? "yes\n" : "no\n");

		// 다음 문자열 입력
        getline(cin, str);
    }
}

int main()
{
    VPS();
	return 0;
}