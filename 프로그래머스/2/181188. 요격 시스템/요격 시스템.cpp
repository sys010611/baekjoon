#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int,int> P;


int solution(vector<vector<int>> targets) 
{
    vector<P> pairs;
    for(auto v : targets)
    {
        pairs.push_back(P(v[0], v[1]));
    }
    
    sort(pairs.begin(), pairs.end());
    
    // 꼬다리를 저장하는 PQ (min heap)
    priority_queue<int, vector<int>, greater<int>> PQ;
    
    int ret = 0;
    
    for(auto pair : pairs)
    {
        int s = pair.first;
        int e = pair.second;
        
        if(PQ.empty() || 
           (!PQ.empty() && s >= PQ.top())) // 요격미사일을 새로 발사해야 함
        {
            ret++;
            PQ = priority_queue<int, vector<int>, greater<int>>();
        }
        
        PQ.push(e);
    }
    
    return ret;
}