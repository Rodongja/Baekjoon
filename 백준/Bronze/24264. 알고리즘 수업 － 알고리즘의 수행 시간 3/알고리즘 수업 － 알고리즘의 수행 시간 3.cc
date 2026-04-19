#include <iostream>
#include <vector>

using namespace std;


int MenOfPassion(const std::vector<int>& A) {
	int sum = 0;
	for (size_t i = 0; i < A.size(); i++) {
		for (size_t j = 0; j < A.size(); j++)
		{
			sum += A[i]; // 코드 1
		}
	}
	return sum;
}

int main()
{
	// 알고리즘 수업 - 알고리즘의 수행 시간 3

	long long n = 0;

	cin >> n;

	vector<int> A(n);

	// for문은 n^2번 실행되니까 코드1은 n^2번 실행
	// 빅오표기법으로 표현하면 O(n^2)
	// 그러므로 두번째 줄은 2
	
	cout << n*n << endl << "2";
	return 0;
}