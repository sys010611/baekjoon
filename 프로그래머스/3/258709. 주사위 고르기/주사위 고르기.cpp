#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

int n;
vector<int> aDice;
vector<int> bDice;
vector<vector<int>> dice;
vector<int> aNums, bNums;

vector<int> aBestDice;
int bestScore = 0;


void GetANumbers(int i, int currSum)
{
    if(i >= n/2)
    {
        aNums.push_back(currSum);
        return;
    }
    
    int diceNo = aDice[i];
    
    for(int j=0;j<6;j++)
    {
        currSum += dice[diceNo][j];
        GetANumbers(i+1, currSum);
        currSum -= dice[diceNo][j];
    }
}
void GetBNumbers(int i, int currSum)
{
    if(i >= n/2)
    {
        bNums.push_back(currSum);
        return;
    }
    
    int diceNo = bDice[i];
    
    for(int j=0;j<6;j++)
    {
        currSum += dice[diceNo][j];
        GetBNumbers(i+1, currSum);
        currSum -= dice[diceNo][j];
    }
}

// 각자 가진 주사위로 시뮬레이션
void Test()
{    
    cout << "주사위 분배 현황 : " << endl;
    cout << "A: ";
    for(auto item : aDice) cout << item << " ";
    cout << endl;
    cout << "B: ";
    for(auto item : bDice) cout << item << " ";
    cout << endl;
    
    // A가 얻을 수 있는 모든 숫자 구해보기
    aNums.clear();
    bNums.clear();
    GetANumbers(0,0);
    GetBNumbers(0,0);
    sort(aNums.begin(), aNums.end());
    sort(bNums.begin(), bNums.end());
    
    // cout << "A: ";
    // for(auto item : aNums)
    // {
    //     cout << item << " ";
    // }
    // cout << endl;
    // cout << "B: ";
    // for(auto item : bNums)
    // {
    //     cout << item << " ";
    // }
    // cout << endl;
    
    int aWinningCount = 0;
    for(auto a : aNums)
    {
        auto lb = lower_bound(bNums.begin(), bNums.end(), a);
        aWinningCount += lb - bNums.begin();
    }
    
    cout << "승리 하는 경우의 수 : " << aWinningCount << endl;
    
    if(aWinningCount > bestScore)
    {
        bestScore = aWinningCount;
        aBestDice = aDice;
    }
    
    return;
}

// 주사위 가져가기
void PickDice(int idx)
{
    if(idx >= n)
    {
        if(aDice.size() == bDice.size())
            Test();
        return;
    }
    
    aDice.push_back(idx);
    PickDice(idx+1);
    aDice.erase(find(aDice.begin(), aDice.end(), idx));
    
    bDice.push_back(idx);
    PickDice(idx+1);
    bDice.erase(find(bDice.begin(), bDice.end(), idx));
    
    return;
}

vector<int> solution(vector<vector<int>> m_dice) 
{    
    dice = m_dice;
    n = dice.size();
    cout << "n : " << n << endl;
    
    PickDice(0);
    
    vector<int> ret;
    for(auto item : aBestDice)
        ret.push_back(item+1);
    
    return ret;
}