#include <iostream>
#include <deque>

using namespace std;

// 풍선 터뜨리기

void program()
{
	int N;
	cin >> N;

	deque<pair<int,int>> dq;
	
	// 덱에 풍선 번호와 값을 넣기
	for (int i = 1; i <= N; i++)
	{
		int num = 0;
		cin >> num;
		dq.push_back({ i, num });
	}

	// 덱이 빌 때까지 반복
	while (!dq.empty())
	{
		pair<int, int> cur = dq.front();

		// 풍선 터뜨리기
		cout << cur.first << " ";
		dq.pop_front();

		// 덱이 비었으면 종료
		if (dq.empty())
			break;

		// 이동
		int move = cur.second;
		if (move > 0)
		{
			// 앞으로 이동할 때는 이미 한 칸 삭제 했기 떄문에 move - 1 만큼 이동
			for (int i = 0; i < move - 1; i++)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else
		{
			// 뒤로 이동할 때는 -move 만큼 이동 (음수이므로 -를 곱해서 양수(횟수)로 전환)
			for (int i = 0; i < -move; i++)
			{
				dq.push_front(dq.back());
				dq.pop_back();
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