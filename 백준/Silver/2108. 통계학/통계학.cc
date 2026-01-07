#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

// 통계학

void average(int N , vector<int>& num)
{
	// 산술평균
	double sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += num[i];
	}
	cout << (int)round(sum / N) << "\n";
}

void median(int N, vector<int>& num)
{
	// 중앙값
	cout << num[N / 2] << "\n";
}

void mode(int N, vector<int>& num)
{
	int cur = num[0];
	int cur_count = 1;

	int max_count = 0;
	vector<int> modes;
	
	// 최빈값
	for (int i = 1; i <= N; i++)
	{
		// 현재 숫자와 같은지 확인
		// 이미 정렬되어 있으므로 같은 숫자가 연속으로 나옴
		// i가 1부터 시작하기 때문에 i < N 조건 추가하지 않으면 범위 초과
		if (i < N && num[i] == cur)
		{
			cur_count++;
		}
		// 다른 숫자일 경우
		else
		{
			// 최대 빈도수 갱신
			if (cur_count > max_count)
			{
				// 새로운 최대 빈도수 발견
				max_count = cur_count;
				// 최빈값 갱신
				modes.clear();
				modes.push_back(cur);
			}

			// 최대 빈도수와 같은 경우
			else if (cur_count == max_count)
			{
				modes.push_back(cur);
			}

			if (i < N)
			{
				// 현재 숫자 갱신
				cur = num[i];
				cur_count = 1;
			}
		}
	}

	// 최빈값이 여러개일 경우 두번째로 작은 값 출력
	if (modes.size() > 1)
	{
		cout << modes[1] << "\n";
	}
	// 최빈값이 하나일 경우
	else
	{
		cout << modes[0] << "\n";
	}
}

void range(int N, vector<int>& num)
{
	// 범위출력
	int max;
	int min;

	max = *max_element(num.begin(), num.end());
	min = *min_element(num.begin(), num.end());

	cout << max - min << "\n";
}

void program()
{
	int N;
	cin >> N;

	vector<int> num;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		num.push_back(temp);
	}

	sort(num.begin(), num.end());

	average(N, num);

	median(N, num);

	mode(N, num);

	range(N, num);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}