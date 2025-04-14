#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstring>

using namespace std;

int dRow[4] = {0, -1, 0, 1};
int dCol[4] = {1, 0, -1, 0};

int n, m;
bool visited[101][101];
int grid[101][101];

int DFS(int row, int col)
{
    if(visited[row][col]) // error
    {
        assert(0); 
    }
    
    visited[row][col] = true;
    
    int ret = grid[row][col];
    
    for(int i=0;i<4;i++)
    {
        int nRow = row + dRow[i];
        int nCol = col + dCol[i];
        
        if(nRow < 0 || nCol < 0 || nRow >= n || nCol >= m)
            continue;
        if(grid[nRow][nCol] == -1 || visited[nRow][nCol])
            continue;
        
        ret += DFS(nRow, nCol);
    }
    
    // cout << "DFS RET : " << ret << endl;
    return ret;
}

vector<int> solution(vector<string> maps) 
{
    n = maps.size();
    m = maps[0].length();
    memset(visited, 0, sizeof(visited));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char curr = maps[i][j];
            if(curr == 'X')
            {
                grid[i][j] = -1;
            }
            else
            {
                grid[i][j] = curr - '0';
            }
        }
    }
    
    vector<int> answer;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            // printf("grid[%d][%d] : %d\n", i, j, grid[i][j]);
            if(grid[i][j] != -1 && !visited[i][j])
            {
                // cout << "DFS START" << endl;
                answer.push_back(DFS(i, j));
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    if(answer.size() == 0)
        answer.push_back(-1);
    
    return answer;
}