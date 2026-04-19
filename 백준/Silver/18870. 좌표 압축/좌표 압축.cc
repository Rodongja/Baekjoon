#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> process(vector<int> vec)
{
    vector<int> ans(vec.size());
    vector<int> sorted = vec;
    sort(sorted.begin(),sorted.end());
    sorted.erase(unique(sorted.begin(),sorted.end()),sorted.end());
    for(size_t i = 0; i < vec.size(); ++i)
    {
        ans[i] = lower_bound(sorted.begin(),sorted.end(),vec[i])- sorted.begin();
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<int> vec(N);
    
    for(int i = 0; i < N; ++i)
    {
        cin >> vec[i];
    }
    
    vec = process(vec);
    
    for(int i = 0; i < N; ++i)
    {
        cout << vec[i] << " ";
    }
    
    return 0;
}