#include <iostream>

using namespace std;
int main()
{
	int N = 0;
	int M = 0;
	cin >> N >> M;

	int* array = new int[N];

	// 배열을 번호로 초기화
	for(int i = 0; i < N; ++i)
	{
		array[i] = i+1;
	}

	int first = 0;
	int second = 0;
	
	for (int j = 0; j < M; ++j)
	{
		// 공 넣기 숫자 입력
		cin >> first >> second;

		// 공 넣기
		int temp = array[first - 1];
		array[first - 1] = array[second - 1];
		array[second - 1] = temp;
	}

	// 출력하기
	for (int k = 0; k < N; ++k)
	{
		cout << array[k] << " ";
	}
	
	return 0;
}