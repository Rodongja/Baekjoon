#include <iostream>
#include <vector>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> vecA;
	vector<int> vecB;
	int A, B;
	int i = 0;
	while (cin >> A)
	{
		cin >> B;
		vecA.push_back(A);
		vecB.push_back(B);
		if (cin.eof()) {
			break;
		}
		cout << vecA[i] + vecB[i] << "\n";
		++i;
	}
} 