#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
vector<vector<int>> adjList;
int indegree[1000001];
int outdegree[1000001];
bool visited[1000001];
bool used[1000001];
int N;

int donutCnt = 0;
int barCnt = 0;
int eightCnt = 0;

void DFS(int curr)
{
    visited[curr] = true;
    // cout << curr << " is in bar" << endl;
    for(auto next:adjList[curr])
    {
        if(!visited[next])
            DFS(next);
    }
}

bool CheckIfDonut(int curr)
{
    // cout << "curr : " << curr << endl;
    visited[curr] = true;
    bool result = true;
    
    if(outdegree[curr]>=2)
        result= false; // 8자 그래프임
    else
        result= true;

    for(auto next:adjList[curr])
    {
        if(!visited[next])
        {
            result = (CheckIfDonut(next) && result);
        }
    }    
    return result;
}

vector<int> solution(vector<vector<int>> edges) {
    memset(indegree, 0, sizeof(indegree));
    memset(outdegree, 0, sizeof(outdegree));
    memset(visited, 0, sizeof(visited));
    memset(used, 0, sizeof(used));
    N = 0;
    for(auto edge:edges)
        for(auto num:edge)
        {
            N = max(N, num);
            used[num] = true;
        }
    
    vector<int> result;
    adjList.resize(N+1);
    
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v=  edges[i][1];
        
        adjList[u].push_back(v);
        outdegree[u]++;
        indegree[v]++;
    }
    
    for(int i=1;i<=N;i++)
    {
        if(outdegree[i] >= 2 && indegree[i] == 0) // 노드 삭제
        {
            // removedNode = i;
            visited[i] = true; 
            result.push_back(i);
            // cout << "삭제 노드 : " << i << endl;
            
            for(auto edge : edges)
            {
                if(edge[0] == i) // 시작점이 삭제노드
                {
                    indegree[edge[1]]--;
                }
                else if (edge[1] == i) // 끝점이 삭제노드
                {
                    outdegree[edge[0]]--;
                    // adjList[edge[0]].erase(i);
                    adjList[edge[0]].erase(
                        std::remove(adjList[edge[0]].begin(), 
                                    adjList[edge[0]].end(), i), 
                                    adjList[edge[0]].end());

                }
            }
        }
    }
    
    // indegree가 하나도 없는 노드에서 DFS, 막대그래프 추출
    for(int i=1;i<=N;i++)
    {
        if(used[i] && !visited[i] && indegree[i] == 0)
        {            
            DFS(i);
            barCnt++;
        }
    }
    // cout << "barCnt: " << barCnt << endl;
    
    // 나머지 노드들에서 DFS, 중간에 outdegree가 2 이상인 노드가 있다면 8자
    // 그렇지 않다면 도넛
    for(int i=1;i<=N;i++)
    {
        if(used[i] && !visited[i])
        {            
            // cout << i << "에서 시작" << endl;
            bool ret = CheckIfDonut(i);
            if(ret == true)
            {
                donutCnt++;
                // cout << "donut " << endl;
            }
            else
            {
                eightCnt++;
                // cout << "eight " << endl;
            }
        }
    }
    
    // cout << "donutCnt : " << donutCnt << endl;
    // cout << "eightCnt : " << eightCnt << endl;
    
    result.push_back(donutCnt);
    result.push_back(barCnt);
    result.push_back(eightCnt);
    
    return result;
}