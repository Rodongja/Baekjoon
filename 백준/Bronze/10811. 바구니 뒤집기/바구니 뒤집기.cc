#include <iostream>

using namespace std;
int main()
{
	int N, M, i, j;

	// 바구니 개수와 교환 횟수 입력
	cin >> N >> M;

	// 바구니 배열 생성
	int* basket = new int[N];

	// 바구니 초기화
	for (int l = 0; l < N; ++l)
	{
		basket[l] = l + 1;
	}
	
	// 바구니 교환
	for (int k = 0; k < M; ++k)
	{
		// 교환할 바구니 입력
		cin >> i >> j;
		int* temp = new int[N];

		// temp 초기화
		for (int l = 0; l < N; ++l)
		{
			temp[l] = basket[l];
			//cout << temp[l] << " ";
		}

		//cout << endl;

		// 뒤집기
		int l;
		int m = j - i + 1;
		for (l = 0;l < m; ++l)
		{
			basket[j - 1] = temp[i - 1];
			++i, --j;
		}

		//// 출력 테스트
		//for (l = 0; l < N; ++l)
		//{
		//	cout << basket[l] << " ";
		//}

		//cout << endl;
	}

	for (int l = 0; l < N; ++l)
	{
		cout << basket[l] << " ";
	}

	return 0;
}