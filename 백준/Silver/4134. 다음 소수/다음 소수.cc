#include <iostream>
#include <vector>
using namespace std;

// 다음 소수
// 밀러-라빈 소수 판별 알고리즘 사용
// 100%는 아니지만 long long에서도 거의 정확하게 소수 판별 가능

// long long끼리 곱하면 오버플로우가 발생하므로 a와 b를 mod로 나눈 나머지끼리 곱하는 방식을 사용
long long mod_mul(long long a, long long b, long long mod)
{
	// a * b를 직접 계산하지 않고, 빠른 덧셈 방식을 사용
    long long result = 0;
	// a를 mod로 나눈 나머지로 초기화
    a %= mod;

	// b가 0이 될 때까지 반복
    while (b > 0)
    {
		// b의 마지막 비트가 1이면 결과에 a를 더함
		if (b & 1)
            result = (result + a) % mod;

		// a를 두 배로 늘리고 mod로 나눈 나머지로 갱신
        a = (a + a) % mod;
        b >>= 1;
    }
    return result;
}

// 빠른 거듭제곱 알고리즘을 사용하여 (base^exp) % mod 계산
long long mod_pow(long long base, long long exp, long long mod)
{
	// 결과를 1로 초기화
    long long result = 1;

	// exp가 0이 될 때까지 반복
    while (exp > 0)
    {
		// exp의 마지막 비트가 1이면 결과에 base를 곱함
        if (exp & 1)
            result = mod_mul(result, base, mod);

		// base를 제곱하고 mod로 나눈 나머지로 갱신
        base = mod_mul(base, base, mod);
        
		// exp를 오른쪽으로 한 비트 시프트(2로 나누기)
        exp >>= 1;
    }
    return result;
}

// Miller-Rabin 소수 판별
// 끝까지 n-1이 나오지 않으면 합성수로 판별
bool miller_rabin(long long n, long long a)
{
    long long d = n - 1;
    int r = 0;

	// n-1을 d가 홀수가 될 때까지 2로 나눈다
	// 즉, n-1 = d * 2^r 형태가 된다
	// r은 n-1에서 2의 지수 부분
    while ((d & 1) == 0)
    {
        d >>= 1;
        r++;
    }

	// a^d % n 계산
    long long x = mod_pow(a, d, n);
    // x == 1 페르마 소정리 만족
	// x == n-1 카르마이클리트 조건 만족
    if (x == 1 || x == n - 1)
        return true;

	// r-1번 반복하며 x를 제곱
    for (int i = 0; i < r - 1; i++)
    {  
        x = mod_mul(x, x, n);
        if (x == n - 1)            
            return true;
    }

	// 끝까지 n-1이 나오지 않으면 합성수로 판별
    return false;
}

// 전체 소수 판별 함수
bool isPrime(long long n)
{
    // 0,1은 소수가 아님
    if (n < 2) return false;
	// 작은 소수들은 속도를 위해 직접 판별
	// LL은 long long 리터럴 접미사
    for (long long p : {2LL, 3LL, 5LL, 7LL, 11LL, 13LL})
        if (n == p) return true;    
        else if (n % p == 0) return false;

	// Miller-Rabin 테스트에 사용할 밑들 
	// https://miller-rabin.appspot.com/에 따르면 2^64 이하의 수에 대해 이 밑들로 테스트하면 정확함
    long long bases[] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };

	// 각 밑에 대해 Miller-Rabin 테스트 수행
    for (long long a : bases)
    {
		// n이 a로 나누어 떨어지면 0(mod n)이므로 건너뜀
        if (a % n == 0) continue;
        
		// Miller-Rabin 테스트에서 합성수로 판별되면 false 반환
        if (!miller_rabin(n, a))
            return false;
    }
    return true;
}

// n보다 크거나 같은 가장 작은 소수 찾기
long long nextPrime(long long n)
{
	// 2보다 작거나 같으면 2 반환
    if (n <= 2) return 2;

	// 짝수면 다음 홀수로 만듦
    if (n % 2 == 0) n++;

	// 소수가 나올 때까지 2씩 증가시키며 검사
    while (!isPrime(n))
        n += 2;

    return n;
}

int main()
{
	// 테스트 케이스 횟수
    int cases;
    cin >> cases;

    // 테스트 케이스 저장 벡터
    vector<long long> num;

    // 테스트 케이스 입력
    while (cases--)
    {
        long long n;
        cin >> n;

        num.push_back(n);
    }

	// 각 테스트 케이스에 대해 다음 소수 출력
    for (int i = 0; i < num.size(); i++)
    {
        cout << nextPrime(num[i]) << "\n";
    }

    return 0;
}