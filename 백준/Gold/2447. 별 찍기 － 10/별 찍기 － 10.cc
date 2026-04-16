#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <string>

using namespace std;

int N;

void stars(vector<vector<char>>& grid, int x, int y, int size)
{
	int newSize = size / 3;

	// 사이즈가 1인 경우
	if (size == 1)
		return;

	// 9등분으로 나누기
	for(int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			// 가운데 칸은 공백으로 채우기
			if (i == 1 && j == 1)
			{
				for (int r = x + newSize; r < x + newSize * 2; r++)
				{
					for (int c = y + newSize; c < y + newSize * 2; c++)
					{
						grid[r][c] = ' ';
					}
				}
			}
			// 재귀 호출
			else
			{
				stars(grid,x + i * newSize, y + j * newSize, newSize);
			}
		}
	}
}

// 출력 함수
void printStars(vector<vector<char>>& grid)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << grid[i][j];
		}
		cout << "\n";
	}
}

void program()
{
	cin >> N;

	vector<vector<char>> grid(N,vector<char>(N,'*'));

	// 첫 그리드의 좌표는 0,0이고 크기는 N
	stars(grid, 0, 0, N);
	printStars(grid);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}