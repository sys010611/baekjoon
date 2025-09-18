#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> order;
vector<vector<int>> dungeons;
int k;

int Test()
{
    int ret = 0;
    int currHp = k;
    for(auto idx : order)
    {
        vector<int> dungeon = dungeons[idx];
        int minimum = dungeon[0];
        int usage = dungeon[1];
        
        if(currHp >= minimum)
        {
            currHp -= usage;
            ret++;
            continue;
        }
        else
        {
            break;
        }
    }
    
    return ret;
}

int solution(int _k, vector<vector<int>> _dungeons) 
{
    k = _k;
    dungeons = _dungeons;
    int result = 0;
    for(int i=0;i<dungeons.size();i++)
    {
        order.push_back(i);
    }
    
    do
    {
        // for(auto item : order)
        //     cout << item << " ";
        // cout << endl;
        int dungeonCnt = Test();
        result = max(result, dungeonCnt);
    }
    while(next_permutation(order.begin(), order.end()));
    
    
    return result;
}