#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 전깃줄
// B의 LIS(최장 증가 부분 수열)의 길이 구하기

int LIS(const vector<pair<int, int>> A)
{
	// lower_bound 이용
	// O(N log N) 시간 복잡도
	
	// LIS의 원소들을 저장하는 벡터
	vector<int> vec_lis;

	// A의 원소들을 순회하면서 B의 원소들을 vec_lis에 저장
	for (int i = 0; i < A.size(); i++)
	{
		// B의 원소
		int num = A[i].second;

		vector<int>::iterator it = lower_bound(vec_lis.begin(), vec_lis.end(), num);

		// num이 vec_lis의 모든 원소보다 큰 경우 it는 end를 반환하므로 뒤에서 추가
		if (it == vec_lis.end())
		{
			vec_lis.push_back(num);
		}
		// num이 vec_lis의 원소보다 작은 경우
		// 해당 원소를 num으로 대체 (num이 vec_lis의 원소보다 큰 경우는 이미 vec_lis에 존재하기 때문에 대체하지 않음)
		else
		{
			*it = num;
		}
	}

	return vec_lis.size();
}

void program()
{
	int N;
	cin >> N;

	// 0의 경우 연결이 없음
	vector<pair<int, int>> A;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;

		pair<int, int> p = { a, b };
		p.first = a;
		p.second = b;

		A.push_back(p);
	}

	// a를 기준으로 오름차순 정렬
	sort(A.begin(), A.end());

	// 뺴야하는 전깃줄의 개수 = N - LIS(A)의 길이
	cout << N - LIS(A) << "\n";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}