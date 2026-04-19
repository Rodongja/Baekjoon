#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
	// 행렬 덧셈
	int cnt = 2;
	int N, M;
	cin >> N >> M;

	vector<vector<vector<int>>> vec(2,vector<vector<int>>(N,vector<int>(M)));

	for (int k = 0; k < cnt; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				cin >> vec[k][i][j];
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << vec[0][i][j] + vec[1][i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}