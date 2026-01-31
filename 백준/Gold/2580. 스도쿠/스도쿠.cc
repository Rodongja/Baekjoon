#include <iostream>
#include <vector>
using namespace std;

// 스도쿠

bool checkNum(vector<vector<int>>& board, int row, int col, int num)
{
	// 1. 같은 횡에 같은 숫자가 있는지 확인	
	for (int j = 0; j < 9; j++)
	{
		if (board[row][j] == num)
		{
			return false;
		}
	}
	// 2. 같은 열에 같은 숫자가 있는지 확인
	for (int i = 0; i < 9; i++)
	{
		if(board[i][col] == num)
		{
			return false;
		}
	}

	// 3. 같은 3x3 박스에 같은 숫자가 있는지 확인
	int startRow = (row / 3) * 3;
	int startCol = (col / 3) * 3;

	for(int i = startRow; i < startRow + 3; i++)
	{
		for(int j = startCol; j < startCol + 3; j++)
		{
			if(board[i][j] == num)
			{
				return false;
			}
		}
	}

	return true;
}

bool sudoku(vector<vector<int>>& board)
{
	// 횡 체크
	for(int i = 0; i < 9; i++)
	{
		// 열 체크
		for(int j = 0; j < 9; j++)
		{
			// 빈칸이면
			if (board[i][j] == 0)
			{
				// 1~9까지 숫자 넣어보기
				for (int num = 1; num <= 9; num++)
				{
					// 해당 숫자가 가능한지 체크
					// true면 가능
					if (checkNum(board,i,j,num))
					{
						board[i][j] = num;
						if (sudoku(board))
						{
							// 성공하면 끝
							return true;
						}
						// 백트래킹
						board[i][j] = 0;
					}
				}
				// 1~9까지 다 안되면 false 반환
				return false;
			}
		}
	}

	// 빈칸이 없으면 완성
	return true;
}

void program()
{
	// 스도쿠 판 생성
	vector<vector<int>> board(9,vector<int>(9));

	// 스도쿠 입력
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> board[i][j];
		}
	}

	sudoku(board);

	// 스도쿠 출력
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}