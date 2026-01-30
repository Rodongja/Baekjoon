#include <iostream>
#include <vector>
using namespace std;

// N-Queen

// 위험 판단 함수
int isDanger(vector<int>& col, int newRow)
{
	int curRow = 0;
	int threat = 0;

	// 이전 행들과 비교
	while (curRow < newRow)
	{
		// 같은 열 or 대각선에 위치하는지 확인
		if (col[newRow] == col[curRow] || abs(col[newRow] - col[curRow]) == abs(newRow - curRow))
		{
			// 위험 발견
			threat = 1;
			break;
		}
		// 다음 행으로 이동
		curRow++;
	}
	// 위험 여부 반환
	return threat;
}

int nQueen(int row, int N, vector<int>& board)
{
	// 퀸 놓기
	// board[col] = row;
	
	// 모든 행에 퀸을 놓았으면 1 반환
	if (row == N)
		return 1;

	// 놓을 수 있는 경우의 수 계산
	int cnt = 0;

	// 각 열에 퀸 놓기 시도
	for (int i = 0; i < N; i++)
	{
		// 퀸 놓기
		board[row] = i;

		// 위험한지 판단
		if (!isDanger(board, row))
		{
			// 다음 행으로 이동
			cnt += nQueen(row + 1, N, board);
		}
	}

	return cnt;
}

void program()
{
	int N;
	cin >> N;

	// 체스판 생성
	vector<int> board(N);

	cout << nQueen(0,N,board);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}