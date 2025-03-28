#include <string>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int,int> P;

int dRow[4] = {0, -1, 0, 1};
int dCol[4] = {1, 0, -1, 0};

int N, M;
bool visited[100][100];
char board[100][100];
P startPos;
P goalPos;

int bfs(int sRow, int sCol)
{
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            visited[i][j] = false;
    
    queue<P> Q;
    visited[sRow][sCol] = true;
    Q.push(P(sRow, sCol));
    
    int level = 0;
    while(!Q.empty())
    {
        int qSize = Q.size();
        while(qSize--)
        {
            int cRow = Q.front().first;
            int cCol = Q.front().second;
            // printf("%d, %d\n", cRow, cCol);
            Q.pop();
            
            if (board[cRow][cCol] == 'G')
                return level;
            
            for(int dir=0;dir<4;dir++)
            {
                for(int dist=1;;dist++)
                {
                    int nRow = cRow + dRow[dir] * dist;
                    int nCol = cCol + dCol[dir] * dist;
                    
                    if(nRow < 0 || nCol < 0 || nRow >= N || nCol >= M                       || board[nRow][nCol] == 'D')
                    {
                        // stop
                        int moveRow = nRow - dRow[dir];
                        int moveCol = nCol - dCol[dir];
                        
                        if(!visited[moveRow][moveCol])
                        {
                            visited[moveRow][moveCol] = true;
                            Q.push(P(moveRow, moveCol));
                        }
                        break;
                    }
                }
            }
        }
        level++;
    }
    return -1;
}

int solution(vector<string> m_board) 
{
    N=m_board.size();
    M=m_board[0].length();
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            char c = m_board[i][j];
            board[i][j] = c;
            if(c == 'R')
                startPos = P(i, j);
            if(c == 'G')
                goalPos = P(i, j);
        }
    }
              
    return bfs(startPos.first, startPos.second);
}