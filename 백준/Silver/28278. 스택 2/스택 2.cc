#include <iostream>
#include <stack>
using namespace std;

// 스택 2

void program(int num, stack<int>& s) 
{
	// 1이 입력되면 정수 X를 스택에 넣는다
    if (num == 1)
    {
        int X;
		cin >> X;

        s.push(X);
    }
	// 2가 입력되면 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    else if (num == 2)
    {
        if (!s.empty())
        {
			cout << s.top() << "\n";
            s.pop();
        }
        else
			cout << "-1\n";
    }
	// 3이 입력되면 스택에 들어있는 정수의 개수를 출력한다.
    else if (num == 3)
    {
        cout << s.size() << "\n";
    }
	// 4가 입력되면 스택이 비어있으면 1, 아니면 0을 출력한다.
    else if (num == 4)
    {
        if (s.empty())
        {
            cout << "1\n";
        }
        else
        {
            cout << "0\n";
        }
    }
	// 5가 입력되면 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    else if (num == 5)
    {
        if (s.empty())
        {
            cout << "-1\n";
        }
        else
        {
            cout << s.top() << "\n";
		}
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    stack<int> s;

    for(int i = 0; i < N; i++) 
    {
        int num;
        cin >> num;

		program(num, s);
	}

    return 0;
}