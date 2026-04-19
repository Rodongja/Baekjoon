#include <iostream>

using namespace std;

int main()
{
	// 벌집
	// 1 7 19 37 61
	//  6 12 18 24
	int N;
	cin >> N;

	int cnt = 1;

	while(N > 1)
	{
		N -= (cnt * 6);
		cnt++;
	}
	
	cout << cnt;

	return 0;
}