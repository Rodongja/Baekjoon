#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 알파벳 개수


void program()
{
	string str;
	cin >> str;

	vector<int> alpha(26, 0);

	for (int i = 0; i < str.size(); i++)
	{
		alpha[str[i] - 'a']++;
	}

	for (int i = 0; i < alpha.size(); i++)
	{
		cout << alpha[i] << " ";
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}