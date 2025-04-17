#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct mineralBatch
{
    mineralBatch(int d, int i, int s)
    {
        this->d = d;
        this->i = i;
        this->s = s;
    }
    int d, i, s;
};

bool compare(mineralBatch& a, mineralBatch& b)
{
    if(a.d != b.d)
    {
        return a.d > b.d;
    }
    else if(a.i != b.i)
    {
        return a.i > b.i;
    }
    else
    {
        return a.s > b.s;
    }
}

vector<mineralBatch> mineralBatches;

int solution(vector<int> picks, vector<string> minerals) 
{
    int pickCount = picks[0] + picks[1] + picks[2];
    
    // minerals를 5개씩 묶어 별도의 구조체로
    for(int i=0;i<minerals.size();i+= 5)
    {
        int d=0;
        int iron=0;
        int s = 0;
        
        for(int j=0;j<5;j++)
        {
            if(i + j >= minerals.size())
                break;
            
            string curr = minerals[i+j];
            if(curr == "diamond")
                d++;
            else if (curr == "iron")
                iron++;
            else if (curr == "stone")
                s++;
        }        
        mineralBatches.push_back(mineralBatch(d, iron, s));
        if(mineralBatches.size() >= pickCount)
            break;
    }
    
    sort(mineralBatches.begin(), mineralBatches.end(), compare);
    
    int answer = 0;

    for(auto batch: mineralBatches)
    {
        // cout << batch.d << " " << batch.i << " " << batch.s<<endl;
        if(picks[0] > 0) // 다이아 곡괭이 사용
        {
            answer += batch.d * 1;
            answer += batch.i * 1;
            answer += batch.s * 1;
            picks[0]--;
        }
        else if(picks[1] > 0) // 철 곡괭이 사용
        {
            answer += batch.d * 5;
            answer += batch.i * 1;
            answer += batch.s * 1;
            picks[1]--;
        }
        else if(picks[2] > 0) // 돌 곡괭이 사용
        {
            answer += batch.d * 25;
            answer += batch.i * 5;
            answer += batch.s * 1;
            picks[2]--;
        }
    }
    
    return answer;
}