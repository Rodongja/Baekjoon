#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

// 에디터

void program()
{
	int N;
	cin >> N;

	stack<int> sta;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;


		if (str == "push")
		{
			int num;
			cin >> num;

			sta.push(num);
		}

		else if (str == "pop")
		{
			if(sta.empty())
			{
				cout << "-1\n";
				continue;
			}

			cout << sta.top() << "\n";
			sta.pop();
		}

		else if (str == "size")
		{
			cout << sta.size() << "\n";
		}

		else if (str == "empty")
		{
			if (sta.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}

		else if (str == "top")
		{
			if(sta.empty())
			{
				cout << "-1\n";
				continue;
			}

			cout << sta.top() << "\n";
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}