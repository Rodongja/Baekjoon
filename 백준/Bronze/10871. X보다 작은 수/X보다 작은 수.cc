#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void program()
{
	int N , X;
	cin >> N >> X;

	vector<int> vec(N);

	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}

	for(int i = 0; i < N; i++)
	{
		if (vec[i] < X)
		{
			cout << vec[i] << " ";
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}