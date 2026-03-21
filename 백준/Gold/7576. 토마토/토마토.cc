#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 토마토

// dx,dy로 방향 정하기 (dx[0],dy[0]) = (1,0)
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };

int BFS(vector<vector<int>>& tomato, vector<vector<int>>& date, queue<pair<int,int>>& q)
{
	// 익은 토마토 초기화
	for (int i = 0; i < tomato.size(); i++)
	{
		for (int j = 0; j < tomato[0].size(); j++)
		{
			if (tomato[i][j] == 1)
			{
				q.push({ i,j });
				date[i][j] = 0;
			}
		}
	}

	// 탐색 시작
	while (!q.empty())
	{
		// cur 초기화
		pair<int, int> cur = q.front();
		q.pop();

		// 4방향 검사
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			// 미로 범위 체크
			if (nx < 0 || nx >= tomato.size() || ny < 0 || ny >= tomato[0].size())
			{
				continue;
			}

			// 토마토가 없거나 이미 방문했으면 패스
			if (tomato[nx][ny] == -1 || date[nx][ny] != -1)
			{
				continue;
			}

			// 토마토가 익는다
			tomato[nx][ny] = 1;

			// 방문하지 않은 토마토의 경우 이전 칸의 길이에 1을 더한다
			date[nx][ny] = date[cur.first][cur.second] + 1;
			q.push({ nx,ny });
		}
	}

	// 최대 날짜
	int maxDate = 0;

	// tomato에 0이 있으면 -1 표시, 없으면 최대 날짜 표시
	for (int i = 0; i < date.size(); i++)
	{
		for (int j = 0; j < date[0].size(); j++)
		{
			// 최대 날짜 갱신
			maxDate = max(maxDate, date[i][j]);

			// 안익은 토마토가 있으면 -1 반환하고 종료
			if (tomato[i][j] == 0)
			{
				return -1;
			}
		}
	}
	// 반환
	return maxDate;
}

void program()
{
	// 미로의 가로 세로 크기
	int m, n;
	cin >> m >> n;

	// 토마토
	vector<vector<int>> tomato(n, vector<int>(m,0)); // 1이면 익은 토마토, 0이면 익지 않은 토마토, -1이면 토마토가 안들어있음

	// 날짜
	vector<vector<int>> date(n, vector<int>(m, -1)); // -1이면 방문하지 않음

	// BFS 탐색을 위한 큐
	queue<pair<int, int>> q;

	// 입력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> tomato[i][j];
		}
	}

	// 탐색후 출력
	cout << BFS(tomato, date, q);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}