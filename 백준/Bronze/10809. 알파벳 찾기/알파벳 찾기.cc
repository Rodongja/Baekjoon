#include <iostream>
#include <cstring>
#include <string>
#include <array>


using namespace std;
int main()
{
	string S;
	getline(cin,S);
	array<int,26> sArray = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

	for (int i = 0; i < S.length(); ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			// 이미 중복된 글자가 있는경우 스킵
			if (-1 != sArray[S[i] - 97])
			{
				break;
			}

			// 알파벳 비교해서 찾으면
			if (S[i]-97 == j)
			{
				sArray[j] = i;
				break;
			}
		}
	}

	// 출력
	for (int i = 0; i < 26; ++i)
	{
		cout << sArray[i] << " ";
	}

	return 0;
}