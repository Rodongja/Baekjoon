#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 큐

void program()
{
	int N;
	cin >> N;

	vector<int> que;
	int head = 0, tail = 0;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		if (str == "push")
		{
			int num;
			cin >> num;
			que.push_back(num);
			tail++;
		}

		else if (str == "pop")
		{
			if (head == tail)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << que[head] << "\n";
				head++;
			}
		}

		else if (str == "size")
		{
			cout << tail - head << "\n";
		}

		else if (str == "empty")
		{
			if (head == tail)
			{
				cout << "1" << "\n";
			}
			else
			{
				cout << "0" << "\n";
			}
		}


		else if (str == "front")
		{
			if (head == tail)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << que[head] << "\n";
			}
		}

		else if (str == "back")
		{
			if (head == tail)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << que[tail - 1] << "\n";
			}
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