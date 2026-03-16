#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 덱

void program()
{
	int N;
	cin >> N;

	const int maxSize = 100000;
	int dq[2*maxSize + 1];
	int head = maxSize, tail = maxSize;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		if (str == "push_front")
		{
			cin >> dq[--head];
		}

		else if (str == "push_back")
		{
			cin >> dq[tail++];
		}

		else if (str == "pop_front")
		{
			if (head == tail)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << dq[head++] << "\n";
			}
		}

		else if (str == "pop_back")
		{
			if (head == tail)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << dq[--tail] << "\n";
			}
		}

		else if (str == "size")
		{
			cout << tail - head << "\n";
		}
		else if (str == "empty")
		{
			if (tail == head)
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
				cout << dq[head] << "\n";
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
				cout << dq[tail - 1] << "\n";
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