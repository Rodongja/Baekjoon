#include <iostream>
#include <vector>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> vecA;
	vector<int> vecB;
	int T;
	int A, B;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> A >> B;
		vecA.push_back(A);
		vecB.push_back(B);
	}
	for (int i = 0; i < T; ++i)
	{
		cout << "Case #" << i+1 << ": " << vecA[i] + vecB[i] << "\n";
	}
} 