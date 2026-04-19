#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(int i, int j)
{
    return i > j;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    int K;
    
    cin >> N >> K;
    
    vector<int> coin(N);
    
    for( int i = 0; i < N; ++i)
    {
        cin >> coin[i];
    }
    
    sort(coin.begin(),coin.end(),compare);
    
    int cnt = 0;
        for(int i = 0; i < coin.size();++i)
        {
            if(K >= coin[i])
            {
                int coinStack = 0;
                coinStack = K / coin[i];
                K = K - (coin[i]*coinStack);
                cnt += coinStack;
            }
        }
    
    cout << cnt;
    
    return 0;
}