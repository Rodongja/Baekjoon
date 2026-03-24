#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
using namespace std;

// 미로 탐색

// dx,dy로 방향 정하기 (dx[0],dy[0]) = (1,0)
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };

void BFS(vector<vector<int>>& maze, vector<vector<int>>& fire, queue<pair<int, int>>& fireq, vector<vector<int>>& jihoon, queue<pair<int, int>>& jihoonq)
{
	// 불 탐색 시작
	while (!fireq.empty())
	{
		// cur 초기화
		pair<int, int> cur = fireq.front();
		fireq.pop();

		// 4방향 검사
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			// 미로 범위 체크
			if (nx < 0 || nx >= maze.size() || ny < 0 || ny >= maze[0].size())
			{
				continue;
			}

			// 이미 방문했거나 미로의 벽인경우 패스
			if (fire[nx][ny] != -1 || maze[nx][ny] == -1)
			{
				continue;
			}

			// 벽이 아닌 경우 이전 칸의 길이에 1을 더한다
			if (maze[nx][ny] != -1)
			{
				fire[nx][ny] = fire[cur.first][cur.second] + 1;
				fireq.push({ nx,ny });
			}
		}
	}

	// 지훈 탐색 시작
	while (!jihoonq.empty())
	{
		// cur 초기화
		pair<int, int> cur = jihoonq.front();
		jihoonq.pop();

		// 4방향 검사
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			// 미로 범위 체크
			if (nx < 0 || nx >= maze.size() || ny < 0 || ny >= maze[0].size())
			{
				continue;
			}

			// 이미 방문했거나 미로의 벽인경우 패스
			if (jihoon[nx][ny] != -1 || maze[nx][ny] == -1)
			{
				continue;
			}

			// 벽이 아닌 경우 이전 칸의 길이에 1을 더한다
			if (maze[nx][ny] != -1)
			{
				jihoon[nx][ny] = jihoon[cur.first][cur.second] + 1;
				jihoonq.push({ nx,ny });
			}
		}
	}

	// 탈출 가능한지 검사
	// min으로 갱신하기 위해 INT_MAX로 초기화
	int isPossible = INT_MAX;

	for(int i = 0; i < maze.size(); i++)
	{
		for (int j = 0; j < maze[0].size(); j++)
		{
			// 탈출 가능한 경우는 지훈이가 불보다 먼저 도착하는 경우이다
			// 벽이 아니고 지훈과 불의 배열이 -1이 아니고 지훈이 불보다 빠르고 미로의 가장자리인 경우 탈출 가능
			if (maze[i][j] != -1 && jihoon[i][j] != -1 && (fire[i][j] == -1 || jihoon[i][j] < fire[i][j]) 
				&& (i == 0 || i == maze.size() - 1 || j == 0 || j == maze[0].size() - 1))
			{
				// isPossible 갱신
				// 미로를 탈출하려면 +1초가 필요함
				// 가장 짧은 시간을 구해야하므로 min으로 갱신한다
				isPossible = min(isPossible, jihoon[i][j] + 1);
			}
		}
	}

	// 출력
	if (isPossible != INT_MAX)
		cout << isPossible << "\n";
	else
		cout << "IMPOSSIBLE" << "\n";
}

void program()
{
	// 미로의 가로 세로 크기
	int n, m;
	cin >> n >> m;

	// 미로
	vector<vector<int>> maze(n, vector<int>(m, -1)); // -1이면 벽 0이면 길 1이면 불 2이면 지훈이

	// 불 배열
	vector<vector<int>> fire(n, vector<int>(m, -1)); // -1이면 방문하지 않음

	// 지훈 배열
	vector<vector<int>> jihoon(n, vector<int>(m, -1)); // -1이면 방문하지 않음

	// BFS 탐색을 위한 큐
	queue<pair<int, int>> fireq;

	// BFS 탐색을 위한 큐
	queue<pair<int, int>> jihoonq;

	// 입력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			
			if (c == '#')
				continue;
			else if(c== '.')
				maze[i][j] = 0;
			else if (c == 'F')
			{
				maze[i][j] = 1;
				fire[i][j] = 0; // 불의 시작점은 0초
				fireq.push({ i,j });
			}
			else if (c == 'J')
			{
				maze[i][j] = 2;
				jihoon[i][j] = 0; // 지훈이의 시작점은 0초
				jihoonq.push({ i,j });
			}
		}
	}

	BFS(maze, fire, fireq, jihoon, jihoonq);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}