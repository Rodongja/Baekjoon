#include <iostream>
#include <vector>

using namespace std;


int MenOfPassion(const std::vector<int>& A) {
	int sum = 0;
	for (size_t i = 0; i < A.size(); i++) 
	{
		for (size_t j = 0; j < A.size(); j++)
		{
			for (size_t k = 0; k < A.size(); k++)
			{
				sum += A[i] * A[j] * A[k]; // 코드 1
			}
		}
	}
	return sum;
}

int main()
{
	// 알고리즘 수업 - 알고리즘의 수행 시간 5

	long long n = 0;

	cin >> n;

	vector<int> A(n);

	// 코드1은 n^3번 실행
	// for문이 3번이기 때문에 빅오표기법으로 표현하면 O(n^3) 상수는 중요하지 않음
	// 그러므로 두번째 줄은 3
	
	cout << n*n*n << endl << "3";
	return 0;
}