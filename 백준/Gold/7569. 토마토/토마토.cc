#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 토마토
// 3차원으로 구현

// dx,dy로 방향 정하기 (dx[0],dy[0]) = (1,0)
const int dx[6] = { 1,0,-1,0 ,0 ,0 };
const int dy[6] = { 0,1,0,-1 ,0 ,0 };
const int dz[6] = { 0,0,0,0,-1,1 };

int BFS(vector<vector<vector<int>>>& tomato, vector<vector<vector<int>>>& date, queue<pair<int, pair<int,int>>>& q)
{
	// 익은 토마토 초기화
	for (int k = 0; k < tomato.size(); k++)
	{
		for (int i = 0; i < tomato[0].size(); i++)
		{
			for(int j = 0; j < tomato[0][0].size(); j++)
			{
				// 익은 토마토인 경우 큐에 넣고 날짜는 0으로 초기화

				if (tomato[k][i][j] == 1)
				{
					q.push({ k,{i,j }});
					date[k][i][j] = 0;
				}
			}
		}
	}

	// 탐색 시작
	while (!q.empty())
	{
		// cur 초기화
		pair<int,pair<int, int>> cur = q.front();
		q.pop();

		// 4방향 검사
		for (int dir = 0; dir < 6; dir++)
		{
			int nz = cur.first + dz[dir];
			int nx = cur.second.first + dx[dir];
			int ny = cur.second.second + dy[dir];


			// 토마토 범위 체크
			if (nx < 0 || nx >= tomato[0].size() || ny < 0 || ny >= tomato[0][0].size() || nz < 0 || nz >= tomato.size())
			{
				continue;
			}

			// 토마토가 없거나 이미 방문했으면 패스
			if (tomato[nz][nx][ny] == -1 || date[nz][nx][ny] != -1)
			{
				continue;
			}

			// 토마토가 익는다
			tomato[nz][nx][ny] = 1;

			// 방문하지 않은 토마토의 경우 이전 칸의 길이에 1을 더한다
			date[nz][nx][ny] = date[cur.first][cur.second.first][cur.second.second] + 1;
			q.push({ nz,{nx,ny} });
		}
	}

	// 최대 날짜
	int maxDate = 0;

	// tomato에 0이 있으면 -1 표시, 없으면 최대 날짜 표시
	for (int i = 0; i < date.size(); i++)
	{
		for (int j = 0; j < date[0].size(); j++)
		{
			for (int k = 0; k < date[0][0].size(); k++)
			{
				// 최대 날짜 갱신
				maxDate = max(maxDate, date[i][j][k]);

				// 안익은 토마토가 있으면 -1 반환하고 종료
				if (tomato[i][j][k] == 0)
				{
					return -1;
				}
			}
		}
	}
	// 반환
	return maxDate;
}

void program()
{
	// 미로의 가로 세로 크기
	int m, n, h;
	cin >> m >> n >> h;

	// 토마토
	vector<vector<vector<int>>> tomato(h, vector<vector<int>>(n, vector<int>(m, 0))); // 1이면 익은 토마토, 0이면 익지 않은 토마토, -1이면 토마토가 안들어있음

	// 날짜
	vector<vector<vector<int>>> date(h, vector<vector<int>>(n, vector<int>(m, - 1))); // -1이면 방문하지 않음

	// BFS 탐색을 위한 큐
	queue<pair<int,pair<int, int>>> q;

	// 입력
	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> tomato[k][i][j];
			}
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