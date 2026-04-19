#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1. 단순 vector로 for문으로 찾으면 시간초과
// 2. unordered_set으로 찾아도 시간초과
// 3. 정렬 후 이분탐색으로 찾기

int main()
{

	int N;
	int M;
	
	cin >> N;

	vector<int> Card(N);
	Card.reserve(N);

	for (int i = 0; i < N; i++)
	{
		cin >> Card[i];
	}

	cin >> M;

	// Card 정렬
	sort(Card.begin(), Card.end());

	vector<int> Number(M);

	for (int i = 0; i < M; i++)
	{
		cin >> Number[i];
	}

	// Number는 정렬할 필요 없음

	// 이분탐색으로 찾기
	for (int i = 0; i < M; i++)
	{
		if(binary_search(Card.begin(), Card.end(), Number[i]))
		{
			cout << "1 ";
		}
		else
		{
			cout << "0 ";
		}
	}

	return 0;
}
