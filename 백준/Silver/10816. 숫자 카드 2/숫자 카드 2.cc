#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// vector에 Card를 넣고 정렬
// lower_bound, upper_bound로 개수 세기

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

	for (int i = 0; i < M; i++)
	{
		int count = ((upper_bound(Card.begin(), Card.end(), Number[i])) - (lower_bound(Card.begin(), Card.end(), Number[i])));
		cout << count << " ";
	}

	return 0;
}
