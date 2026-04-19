#include <iostream>
#include <deque>

using namespace std;

// 카드2

void program()
{
	int N;
	cin >> N;

	deque<int> card;

	for(int i = 1; i <= N; i++)
		card.push_back(i);

	while (card.size() > 1)
	{
		// 맨 위 카드 버리기
		card.pop_front();
		// 맨 위 카드 아래로 넣기
		int top = card.front();
		card.push_back(top);
		card.pop_front();
	}

	// 마지막 남은 카드 출력
	cout << card.front() << "\n";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}