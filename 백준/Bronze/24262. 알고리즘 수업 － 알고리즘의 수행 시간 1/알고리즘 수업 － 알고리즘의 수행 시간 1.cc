#include <iostream>

using namespace std;


int MenOfPassion(int A[], int n) {
	int i = n / 2;
	return A[i]; // 코드 1
}

int main()
{
	// 알고리즘 수업 - 알고리즘의 수행 시간 1

	// 이 함수에서 코드 1은 n의 개수와 상관없이 항상 한번만 실행됨
	// 그러므로 빅오 표기법으로는 O(1)의 시간복잡도를 가짐

	int n = 0;

	cin >> n;

	cout << "1" << endl << "0";
	


	return 0;
}