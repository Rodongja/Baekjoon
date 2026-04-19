#include <iostream>

using namespace std;
int main()
{
	char* S = new char[1001];
	int i = 0;

	cin >> S;
	cin >> i;

	cout << S[i - 1];

	return 0;
}