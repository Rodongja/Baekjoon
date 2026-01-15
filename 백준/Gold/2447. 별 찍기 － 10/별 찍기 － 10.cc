#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <string>

using namespace std;

int N;

// 별 찍기 - 10
// 재귀적으로 별을 찍는 함수

void stars(int row, int col, int size, vector<vector<char>>& grid)
{
	// size가 1이면 종료
	if(size == 1)
		return;

	// 가운데 부분을 공백으로 채우기
	int newSize = size / 3;

	// 그리드를 9개로 나누어 재귀 호출
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			// 가운데 부분은 공백으로 채우기
			if (i == 1 && j == 1)
			{
				// row + newSize 이상 row + 2*newSize 미만
				
				for (int r = row + newSize; r < row + 2 * newSize; r++)
				{
					// col + newSize 이상 col + 2*newSize 미만
					for(int c = col + newSize; c < col +2 * newSize; c++)
					{
						grid[r][c] = ' ';
					}
				}
			}
			else
			{
				stars(row + i * newSize, col + j * newSize, newSize, grid);
			}

		}
	}
}

void printStars(const vector<vector<char>>& stars)
{
	for (const auto& row : stars)
	{
		for (const auto& ch : row)
		{
			cout << ch;
		}
		cout << '\n';
	}
}


void program()
{
	cin >> N;

	vector<vector<char>> grid(N, vector<char>(N, '*'));

	stars(0, 0, N, grid);

	printStars(grid);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}