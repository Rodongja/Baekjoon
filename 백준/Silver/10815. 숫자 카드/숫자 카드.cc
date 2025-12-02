#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

	sort(Card.begin(), Card.end());

	vector<int> Number(M);

	for (int i = 0; i < M; i++)
	{
		cin >> Number[i];
	}

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
