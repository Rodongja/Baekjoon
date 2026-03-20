#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 그림

// dx,dy로 방향 정하기 (dx[0],dy[0]) = (1,0)
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };

void BFS(vector<vector<int>>& paper, vector<vector<bool>>& isVisited, queue<pair<int,int>>& q, int& maxPaint, int& cntPaint)
{


	// 모든 좌표를 탐색할 때까지 반복하기
	for(int i = 0 ; i < paper.size(); i++)
	{
		for (int j = 0; j < paper[0].size(); j++)
		{
			// 첫 탐색하는 좌표가 방문한 적이 있거나, 빈칸이면 패스하기
			if(paper[i][j] == 0 || isVisited[i][j] == 1)
			{
				continue;
			}

			// 첫 값을 큐에 넣고 방문처리
			q.push({ i,j });
			isVisited[i][j] = 1;

			// 현재 그림 크기
			int curPaint = 1;

			// 그림 하나를 찾으면 종료
			while (!q.empty())
			{
				// 큐에서 하나 꺼내기
				pair<int, int> cur = q.front();
				// 큐에서 꺼낸 좌표를 기준으로 BFS 탐색하기
				q.pop();

				// 4방향 검사
				for (int dir = 0; dir < 4; dir++)
				{
					// 다음 좌표 구하기
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					// 범위를 벗어나면 패스하기
					if (nx < 0 || nx >= paper.size() || ny < 0 || ny >= paper[0].size())
					{
						continue;
					}
					
					// 검사한 좌표가 방문한 적이 있거나, 빈칸이면 패스하기
					if (paper[nx][ny] == 0 || isVisited[nx][ny] == 1)
					{
						continue;
					}

					// 방문 처리하기
					isVisited[nx][ny] = 1;

					// 그림의 크기 증가시키기
					curPaint++;

					// 다음 좌표가 그림이면 queue에 넣기	
					q.push({ nx, ny });
				}
			}

			// 그림의 최대 크기 갱신
			if (curPaint > maxPaint)
			{
				maxPaint = max(maxPaint, curPaint);
			}

			// 그림의 개수 증가시키기
			if (curPaint > 0)
			{
				cntPaint++;
			}
		}
	}
}

void program()
{
	// 도화지의 가로 세로 크기
	int n, m;
	cin >> n >> m;

	// 도화지
	vector<vector<int>> paper(n, vector<int>(m,0)); // 1이면 그림, 0이면 빈칸
	// 방문 여부
	vector<vector<bool>> isVisited(n, vector<bool>(m)); // 1이면 방문한 적 있음, 0이면 방문한 적 없음
	// BFS 탐색을 위한 큐
	queue<pair<int, int>> q;

	// 최대 그림 크기
	int maxPaint = 0;
	//그림의 개수
	int cntPaint = 0;

	// 입력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> paper[i][j];
		}
	}

	// 탐색
	BFS(paper, isVisited, q, maxPaint, cntPaint);

	// 출력
	cout << cntPaint << "\n" << maxPaint << "\n";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}