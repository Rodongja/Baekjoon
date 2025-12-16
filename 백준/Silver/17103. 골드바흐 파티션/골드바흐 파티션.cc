#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std; 
// 골드바흐 파티션 
// 짝수 N을 두 소수의 합으로 나타내는 표현을 골드바흐 파티션이라고 한다 
// 짝수 N이 주어졌을 때, 골드바흐 파티션의 개수를 구해보자 
// 에라토스테네스의 체 알고리즘 구현 
vector<bool> sieveOfEratosthenes(int maxNum) 
{ 
	// true이면 소수, false이면 소수가 아님 
	vector<bool> isPrime(maxNum + 1, true); isPrime[0] = false; isPrime[1] = false;
	// 0과 1은 소수가 아님 
	// 에라토스테네스의 체 알고리즘 적용 
	// 2부터 maxNum의 제곱근까지 반복 
	for (int i = 2; i * i <= maxNum; ++i) 
	{ 
		// i가 소수인 경우
		if (isPrime[i]) 
		{ 
			// i의 배수들을 모두 소수가 아니라고 표시 
			for (int j = i * i; j <= maxNum; j += i) 
			{ 
				isPrime[j] = false; 
			}
		}
	}

	// 소수 여부를 담은 벡터 반환
	return isPrime; 
} 

// 골드바흐 파티션 함수 구현 
// 총 파티션의 개수를 반환
// p와 N-p가 모두 소수이면 둘 다 소수이면서 둘을 더하면 N이 되는 쌍이므로 카운트 증가 
int goldbachPartitions(int N, const vector<bool>& primes) 
{ 
	int count = 0;
	// N = p + (N - p) 형태이므로 p가 N/2를 넘으면 중복 계산이 발생하므로 N/2까지만 반복 
	for(int p = 2; p <= N / 2; p++) 
	{ 
		// p와 N - p가 모두 소수인 경우 카운트 증가 (p + (N - p) = N) 
		if (primes[p] && primes[N - p]) count++; 
	} 
	return count; 
} 

int main() 
{
	// 테스트 케이스 개수 
	int N; cin >> N; 
	// 테스트 케이스 저장 벡터 
	vector<int> numbers; 
	// 테스트 케이스 저장 
	for(int i = 0; i < N; i++) 
	{ 
		int num; cin >> num; numbers.push_back(num); 
	} 
	
	// 소수 판별 벡터
	vector<bool> primes; 
	// 결과 저장 벡터
	vector<int> counts; 
	// 입력된 수들 중 최댓값으로 에라토스테네스의 체 실행
	// 한번만 실행하면 되므로 미리 계산하여 최적화
	int maxNum = *max_element(numbers.begin(), numbers.end()); 
	primes = sieveOfEratosthenes(maxNum); 
	
	// 각 테스트 케이스에 대해 골드바흐 파티션 개수 계산
	for (int i = 0; i < N; i++) 
	{ 
		int count = 0; 
		// 골드바흐 파티션 개수 계산 함수 호출
		count = goldbachPartitions(numbers[i], primes); 
		// 결과 저장
		counts.push_back(count); 
	} 
	
	// 결과 출력
	for(int i = 0; i < N; i++) 
	{ 
		cout << counts[i] << "\n"; 
	}

	return 0; 
}