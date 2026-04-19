#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int main()
{
	// 그룹 단어 체커

	// 단어의 개수
	int N;
	cin >> N;

	int cnt = 0; // 그룹 단어 카운터

	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		vector<char> vec;
		vec.push_back(str[0]);
		bool isGroup = true;

		for (int j = 1; j < str.length(); ++j)
		{
			// 1 글자인 단어인 경우
			if (str[j] == '\0')
			{
				break;
				++cnt;
			}


			if (str[j - 1] != str[j])
			{
				if (find(vec.begin(), vec.end(), str[j]) != vec.end())
				{
					isGroup = false;
					break;
				}
				else
				{
					vec.push_back(str[j]);
				}
			}
		}

		if (isGroup)
		{
			++cnt; 
		}
		else
		{
			isGroup = true;
		}
	}



	cout << cnt;

	return 0;
}

