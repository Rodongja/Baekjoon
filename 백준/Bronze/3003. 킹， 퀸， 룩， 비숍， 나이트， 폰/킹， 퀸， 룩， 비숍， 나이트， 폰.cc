#include <iostream>
using namespace std;
int main()
{
	// 체스
	int white[6] { 0 };
	
	// 순서
	// 킹 퀸 룩 비숍 나이트 폰
	// 1  1  2  2    2     8
	
	for (int i = 0; i < 6; ++i)
	{
		cin >> white[i];
	}


	for (int i = 0; i < 6; ++i)
	{
		switch (i)
		{
		case 0:
		case 1:
			white[i] = 1 - white[i];
			break;
		case 2:
		case 3:
		case 4:
			white[i] = 2 - white[i];
			break;
		case 5:
			white[i] = 8 - white[i];
			break;
		}
		cout << white[i] << " ";
	}


	return 0;
}