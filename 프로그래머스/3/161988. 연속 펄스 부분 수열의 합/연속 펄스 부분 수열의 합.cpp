#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> secA;
vector<long long> secB;
vector<long long> prefixSumA;
vector<long long> prefixSumB;

long long solution(vector<int> sequence) 
{
    long long a = 1;
    long long b = -1;
    for(auto item:sequence)
    {
        secA.push_back(item * a);
        secB.push_back(item * b);
        
        a *= -1;
        b *= -1;
    }
    
    long long sum = 0;
    for(auto item : secA)
    {
        sum += item;
        prefixSumA.push_back(sum);
    }
    sum = 0;
    for(auto item : secB)
    {
        sum+=item;
        prefixSumB.push_back(sum);
    }
    
//     for(auto item : prefixSumA)
//         cout << item << " " ;
//     cout << endl;
//     for(auto item : prefixSumB)
//         cout << item << " " ;
//     cout << endl;
    
    long long answer = 0;
    long long currMin = 0;
    for(auto item : prefixSumA)
    {
        answer = max(answer, item - currMin);
        if(currMin > item)
            currMin = item;
    }
    
    currMin = 0;
    for(auto item : prefixSumB)
    {
        answer = max(answer, item - currMin);
        if(currMin > item)
            currMin = item;
    }
    
    
    
    return answer;
}