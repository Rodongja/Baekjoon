#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

// unordered_set 사용

// 합집합 탬플릿 함수
template <typename T>
unordered_set<T> uni(const unordered_set<T>& A, const unordered_set<T>& B) {
	unordered_set<T> C = A;
	for (const int& x : B)
		C.insert(x);
	return C;
}

// 교집합 탬플릿 함수
template <typename T>
unordered_set<T> inter(const unordered_set<T>& A, const unordered_set<T>& B) {
	unordered_set<T> C;
	for (const int& x : A)
		if (B.find(x) != B.end())
			C.insert(x);
	return C;
}

// 차집합 탬플릿 함수
template <typename T>
unordered_set<T> diff(const unordered_set<T>& A, const unordered_set<T>& B) {
	unordered_set<T> C;
	for (const int& x : A)
		if (B.find(x) == B.end())
			C.insert(x);
	return C;
}

int main()
{

	int N;
	int M;
	// 입력
	cin >> N;
	cin >> M;

	// 자료구조 선언
	unordered_set<int> A;
	unordered_set<int> B;
	unordered_set<int> C;
	unordered_set<int> D;
	unordered_set<int> ANS;


	// 입력
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		A.insert(num);
	}

	// 입력
	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		B.insert(num);
	}

	// 합집합 만들기
	C = uni(A, B);

	// 교집합 만들기
	D = inter(A, B);

	// 차집합 만들기
	ANS = diff(C, D);

	// 출력
	cout << ANS.size();

	return 0;
}
