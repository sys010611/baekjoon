#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define MAX 1000000
#define INF 100000000

int n;

int dp[1000001];

int GetDP(int y)
{
    if(y <= 0)
        return INF; 
    
    if(dp[y] != -1)
        return dp[y];
    
    
    int a = INF;
    if(y%2 == 0)
        a = GetDP(y/2);
    int b = INF;
    if(y%3 == 0)
        b = GetDP(y/3);
    int c = INF;
    if(y-n > 0)
        c = GetDP(y-n);
        
    int ret = min({a,b,c}) + 1;
    // printf("dp[%d] : %d\n" ,y, ret);
    return dp[y] = ret;
}

int solution(int x, int y, int _n) 
{
    n=_n;
    memset(dp, -1, sizeof(dp));
    
    dp[x] = 0; // base case
    
    int ret = GetDP(y);
    if(ret >= MAX)
        return -1;
    else
        return ret;
}