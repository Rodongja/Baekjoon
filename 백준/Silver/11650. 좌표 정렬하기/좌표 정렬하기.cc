#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)
{
   if(a.first == b.first)
      return a.second < b.second;
   else
      return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N = 0;
    cin >> N;
    
    vector<pair<int,int>> vec;
    
    int x = 0;
    int y = 0;
    
    for(int i = 0; i < N; ++i)
    {
        cin >> x >> y;
        vec.push_back(pair<int,int>(x,y));
    }
    
    sort(vec.begin(),vec.end(),compare);
        
    for(int i = 0; i < N; ++i)
    {
        cout << vec[i].first << " " << vec[i].second << "\n";    
    }
    
    return 0;
}