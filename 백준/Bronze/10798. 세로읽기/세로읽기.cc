#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	// 최댓값

	int cnt = 5;
	int len = 15;

	string str;
	vector<string> vec(cnt);

	string ans;
	vector<int> vec_len(cnt);

	for (int i = 0; i < cnt; ++i)
	{
		cin >> vec[i];
		vec_len[i] = vec[i].length();
	}

	for (int j = 0; j < len; ++j)
	{
		for (int i = 0; i < cnt; ++i)
		{
			if (j >= vec_len[i])
				continue;
			else
				ans.push_back(vec[i][j]);
		}
	}

	cout << ans;
	return 0;
}