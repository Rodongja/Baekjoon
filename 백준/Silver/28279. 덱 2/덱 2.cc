#include <iostream>
#include <deque>

using namespace std;

// 덱 2

void program()
{
	int N;
	cin >> N;

	deque<int> dq;

	for (int i = 0; i < N; i++)
	{
		int command;
		cin >> command;

		switch (command)
		{
			// 1 X: 정수 X를 덱의 앞에 넣는다. (1 ≤ X ≤ 100,000)
			case 1:
			{
				int X;
				cin >> X;
				dq.push_front(X);
			}
			break;
			// 2 X: 정수 X를 덱의 뒤에 넣는다. (1 ≤ X ≤ 100,000)
			case 2:
			{
				int X;
				cin >> X;
				dq.push_back(X);
			}
			break;
			// 3: 덱에 정수가 있다면 맨 앞의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
			case 3:
			{
				if (!dq.empty())
				{
					cout << dq.front() << "\n";
					dq.pop_front();
				}
				else
				{
					cout << "-1" << "\n";
				}
			}
			break;
			// 4: 덱에 정수가 있다면 맨 뒤의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
			case 4:
			{
				if(!dq.empty())
				{
					cout << dq.back() << "\n";
					dq.pop_back();
				}
				else
				{
					cout << "-1" << "\n";
				}
			}
			break;
			// 5: 덱에 들어있는 정수의 개수를 출력한다.
			case 5:
			{
				cout << dq.size() << "\n";
			}
			break;
			// 6: 덱이 비어있으면 1, 아니면 0을 출력한다.
			case 6:
			{
				if (dq.empty())
				{
					cout << "1" << "\n";
				}
				else
				{
					cout << "0" << "\n";
				}
			}
			break;
			// 7: 덱에 정수가 있다면 맨 앞의 정수를 출력한다. 없다면 -1을 대신 출력한다.
			case 7:
			{
				if (!dq.empty())
				{
					cout << dq.front() << "\n";
				}
				else
				{
					cout << "-1" << "\n";
				}
			}
			break;
			// 8: 덱에 정수가 있다면 맨 뒤의 정수를 출력한다. 없다면 -1을 대신 출력한다.
			case 8:
			{
				if (!dq.empty())
				{
					cout << dq.back() << "\n";
				}
				else
				{
					cout << "-1" << "\n";
				}
			}
			break;
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