#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void program()
{
	int N , X;
	cin >> N >> X;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		if( num < X )
			cout << num << " ";
	}

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}