#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    answer.resize(prices.size());
    fill(answer.begin(), answer.end(), -1);
    
    stack<int> S;
    
    for(int i=0;i<prices.size();i++)
    {
        int curr = prices[i];
        if(!S.empty() && S.top() > curr)
        {
            int popCount = 0;
            while(!S.empty() && S.top() > curr)
            {
                S.pop();
                popCount++;
                if(answer[S.size()] == -1)
                    answer[S.size()] = popCount;
            }
            while(popCount--)
                S.push(curr);
        }
        S.push(curr);
    }
    
    int popCount = 0;
    while(!S.empty())
    {
        S.pop();
        if(answer[S.size()] == -1)
        {
            answer[S.size()] = popCount;
        }
        popCount++;
    }
    
    return answer;
}