#include <iostream>
#include <deque>
#include <string>

using namespace std;

// 큐 2

void program()
{
	int N;
	cin >> N;

	deque<int> q;
	
	for (int i = 0; i < N; i++)
	{
		string command;
		cin >> command;

		if (command == "push")
		{
			int X;
			cin >> X;
			q.push_back(X);
		}
		else if (command == "pop")
		{
			if (q.empty())
				cout << "-1\n";
			else
			{
				cout << q.front() << "\n";
				q.pop_front();
			}
		}
		else if (command == "size")
		{
			cout << q.size() << "\n";
		}
		else if (command == "empty")
		{
			cout << q.empty() << "\n";
		}
		else if (command == "front")
		{
			if(q.empty())
				cout << "-1\n";
			else
				cout << q.front() << "\n";
		}
		else if (command == "back")
		{
			if(q.empty())
				cout << "-1\n";
			else
				cout << q.back() << "\n";
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