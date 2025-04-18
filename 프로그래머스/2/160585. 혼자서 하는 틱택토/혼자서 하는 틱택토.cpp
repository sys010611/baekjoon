#include <string>
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;
char board[3][3];

bool oWinned =false;
bool xWinned =false;

bool CheckCount()
{
    int oCount = 0;
    int xCount = 0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j] == 'O')
                oCount++;
            if(board[i][j] == 'X')
                xCount++;
        }
    }
    cout << "O: " << oCount << endl;
    cout << "X: " << xCount << endl;
        
    if(!oWinned && !xWinned)
    {
        if(oCount == xCount || oCount == xCount + 1)
            return true;
        else
            return false;        
    }
    else if(oWinned)
    {
        if(oCount == xCount + 1)
            return true;
        else
            return false;        
    }
    else if (xWinned)
    {
        if(oCount == xCount)
            return true;
        else
            return false;        
    }
    else 
    {
        assert(0);
        return false;
    }

}

bool CheckThree()
{
    int threeCount= 0;
    
    // check row
    for(int i=0;i<3;i++)
    {
        bool allSame = true;
        char first = board[i][0];
        for(int j=1;j<3;j++)
        {
            char curr = board[i][j];
            if(curr == '.')
                allSame = false;
            if(first != curr)
            {
                allSame = false;
            }
        }
        if(allSame)
        {
            threeCount++;
            if(first == 'O')
                oWinned = true;
            else if (first == 'X')
                xWinned = true;
            cout << i << " row" << endl;
        }
    }
    // check col
    for(int i=0;i<3;i++)
    {
        bool allSame = true;
        char first = board[0][i];
        for(int j=1;j<3;j++)
        {
            char curr = board[j][i];
            if(curr == '.')
                allSame = false;
            if(first != curr)
                allSame = false;
        }
        if(allSame)
        {
            if(first == 'O')
                oWinned = true;
            else if (first == 'X')
                xWinned = true;
            cout << i << " col" << endl;
            threeCount++;
        }
    }
    // check diagonal
    int r=0;
    int c=0;
    char first = board[r][c];
    bool allSame = true;
    for(int i=1;i<3;i++)
    {
        r++;
        c++;
        char curr= board[r][c];
        if(curr == '.')
            allSame = false;
        if (first != curr)
        {
            allSame = false;
        }
    }
    if(allSame)
    {
        if(first == 'O')
            oWinned = true;
        else if (first == 'X')
            xWinned = true;
        threeCount++;
        cout << "\\ diagonal" << endl;
    }
        
    
    r=0; c=2;
    first = board[r][c];
    allSame = true;
    for(int i=1;i<3;i++)
    {
        r++;c--;
        char curr = board[r][c];
        if(curr == '.')
                allSame = false;
        if(first != curr)
            allSame = false;
    }
    if(allSame)
    {
        if(first == 'O')
            oWinned = true;
        else if (first == 'X')
            xWinned = true;
        cout << "/ diagonal" << endl;
        threeCount++;
    }
        
    // cout << "threeCount : " << threeCount << endl;
    // cout << "Winner : " << winner << endl;
    
    if(oWinned && xWinned)
        return false;
    else
        return true;
}

int solution(vector<string> _board) 
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            board[i][j] = _board[i][j];
        }
    }
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    

    if(!CheckThree())
    {
        cout << "Duplicate End" << endl;
        return 0;
    }
    if(!CheckCount())
    {
        cout << "Count ERROR" << endl;
        return 0;
    }
    
    return 1;
}