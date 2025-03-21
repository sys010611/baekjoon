#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) 
{
    vector<int> prefixSum;
    prefixSum.push_back(0);
    int currSum = 0;
    for(int i=0; i<sequence.size() ;i++)
    {
        currSum += sequence[i];
        prefixSum.push_back(currSum);
    }
    
    // for(auto item : prefixSum)
    //     cout << item << " ";
    
    int minLength = 2000000;
    int retS = -1;
    int retE = -1;
    
    int s=0;
    int e = 1;
    while(s <= e && e < prefixSum.size())
    {
        int curr = prefixSum[e] - prefixSum[s];
        if(curr == k)
        {
            int currLen = e - s;
            if(currLen  < minLength)
            {
                minLength = currLen;
                retE = e-1;
                retS = s;
            }
            
            e++;
        }
        else if (curr < k) // e를 옮긴다
        {
            e++;
        }
        else // curr > k // s를 옮긴다
        {
            s++;
        }
    }
    
    vector<int> ret;
    ret.push_back(retS);
    ret.push_back(retE);
    return ret;
}