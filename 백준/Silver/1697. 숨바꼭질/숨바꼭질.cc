#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
using namespace std;

// 숨바꼭질

const int dx[3] = { -1, 1, 2 };

int BFS(int N, int K)
{
	// 거리 벡터
	vector<int> visited(100001,-1);
	// 수빈이의 위치
	visited[N] = 0;

	// 큐
	queue<int> q;
	q.push(N);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int dir = 0; dir < 3; dir++)
		{

			if (dir == 2)
			{
				// 2배
				int nx = cur * 2;

				// 거리 범위 체크
				if (nx < 0 || nx > 100000)
					continue;

				// 이미 방문한적이 있으면 패스
				if (visited[nx] != -1)
					continue;

				// 방문 횟수 = 이전 단계의 방문 횟수 + 1
				visited[nx] = visited[cur] + 1;

				// 동생을 찾으면 return
				if (nx == K)
					return visited[nx];

				// 큐에서 제거
				q.push(nx);
			}
			else
			{
				// -1, +1
				int nx = cur + dx[dir];

				// 거리 범위 체크
				if (nx < 0 || nx > 100000)
					continue;

				// 이미 방문한적이 있으면 패스
				if (visited[nx] != -1)
					continue;

				// 방문 횟수 = 이전 단계의 방문 횟수 + 1
				visited[nx] = visited[cur] + 1;

				// 동생을 찾으면 return
				if (nx == K)
					return visited[nx];

				// 큐에서 제거
				q.push(nx);
			}
		}
	}
	// 동생이 없는경우
	return -1;
}

void program()
{
	int N, K;
	cin >> N >> K;

	// 수빈이와 동생의 위치가 같으면 0
	if (N == K)
	{
		cout << "0" << "\n";
		return;
	}

	cout << BFS(N, K) << "\n";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}