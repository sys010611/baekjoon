#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int map[50][50];
bool visited[50][50];
int w, h; //가로, 세로

int dx[] = {1,-1,0,0,1,-1,1,-1};
int dy[] = {0,0,1,-1,1,-1,-1,1};

void dfs(int row, int col)
{
    //cout << row << ", " << col << "방문" << endl;
    if(visited[row][col]) //이미 방문했다면 바로 리턴
        return;
    else
        visited[row][col] = true;

    for (int i = 0; i < 8; i++) //인접 노드들 모두 방문 시도
    {
        //다음 탐색 노드가 범위 안이라면, 방문하지 않았다면, 땅이라면
        if ((row + dy[i] >= 0 && row + dy[i] < h) && (col + dx[i] >= 0 && col + dx[i] < w)
        && !visited[row+dy[i]][col+dx[i]] && map[row + dy[i]][col + dx[i]] == 1)
        {
            dfs(row + dy[i], col + dx[i]);
        }
    }
}

int dfsAll()
{
    int componentCount = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (map[i][j] == 1 && !visited[i][j]) //땅이라면, 방문한적 없다면 탐색 시작
            {
                dfs(i, j);
                //cout << "컴포넌트 탐색 완료" << endl;
                componentCount++;
            }
        }
    }
    return componentCount;
}

int main()
{
    while (true)
    {
        for (int i = 0; i < 50; i++)
            fill(visited[i], visited[i]+50, false); //visited 배열 초기화
        
        cin >> w >> h;

        if(w == 0 && h == 0)
            break;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> map[i][j];
            }
        }

        cout << dfsAll() << endl;
    }
}


