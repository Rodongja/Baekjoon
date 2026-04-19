#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
	// 삼각형과 세 변

	// 세 변 선언
	int A = 0, B = 0, C = 0;
	
	// 가장 긴 변 선언
	int MAX = 0;

	cin >> A >> B >> C;

	vector<string> v_answer;

	while (true)
	{
		// 세 변의 길이가 모두 0이면
		if (A == 0 && B == 0 && C == 0)
		{
			break;
		}

		// 세 변의 길이가 모두 같은 경우
		if (A == B && B == C)
		{
			v_answer.push_back("Equilateral");
		}
		else
		{
			MAX = max(max(A, B), C);
			// 삼각형의 조건을 만족하지 못하는 경우
			if (MAX == A)
			{
				if (MAX >= B + C)
				{
					v_answer.push_back("Invalid");
					cin >> A >> B >> C;
					continue;
				}
			}
			else if (MAX == B)
			{
				if (MAX >= A + C)
				{
					v_answer.push_back("Invalid");
					cin >> A >> B >> C;
					continue;
				}
			}
			else if (MAX == C)
			{
				if (MAX >= A + B)
				{
					v_answer.push_back("Invalid");
					cin >> A >> B >> C;
					continue;
				}
			}

			// 두 변의 길이가 같은 경우
			if (A == B || B == C || A == C)
			{
				v_answer.push_back("Isosceles");
			}
			// 세 변의 길이가 모두 다른 경우
			else
			{
				v_answer.push_back("Scalene");
			}
		}
		cin >> A >> B >> C;
	}

	for (size_t i = 0; i < v_answer.size(); ++i)
	{
		cout << v_answer[i] << endl;
	}

	return 0;
}