#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Work
{
    Work(int sm, int d, string n)
    {
        startMin = sm;
        duration = d;
        name = n;
    }
    int startMin;
    int duration;
    string name;
};

stack<string> S;
vector<Work> works;
unordered_map<string, int> timeLeft;

bool compare(Work& a, Work& b)
{
    return a.startMin < b.startMin;
}

vector<string> solution(vector<vector<string>> plans) 
{
    vector<string> answer;
    
    for(auto plan : plans)
    {
        string name = plan[0];
        string startTime = plan[1];
        string playTime = plan[2];
        
        int h = stoi(startTime.substr(0, 2));
        int m = stoi(startTime.substr(3, 5));
        int d = stoi(playTime);
        
        works.push_back(Work(h*60 + m, d, name));
        timeLeft[name] = d;
    }
    
    sort(works.begin(), works.end(), compare);
    
    // for(auto work : works)
        // cout << work.startHour << " " << work.startMin << " " << work.duration << " " << work.name << endl;
    
    stack<string> S;
    int lastMin = works[0].startMin;
    for(auto curr : works)
    {
        int sm = curr.startMin;
        
        int deltaMin = sm - lastMin;
        
        while (!S.empty())
        {
            string lastWork = S.top();
    
            if(deltaMin >=  timeLeft[lastWork])
            {
                deltaMin -= timeLeft[lastWork];
                timeLeft[lastWork] = 0;
                answer.push_back(lastWork);
                S.pop();
                continue;
            }
            else
            {
                timeLeft[lastWork] -= deltaMin;
                break;
            }
        }
        
        S.push(curr.name);
        lastMin = sm;
    }
    while(!S.empty())
    {
        answer.push_back(S.top());
        S.pop();
    }
    
    return answer;
}