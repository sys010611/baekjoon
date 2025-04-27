#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define int long long

vector<int> numbers;

void GetNum(int totalLength, string currNum)
{
    //cout << "currNum : " << currNum << endl;
    if (currNum.length() == totalLength)
    {
        //cout << "added : " << currNum << endl;

        numbers.push_back(stoll(currNum));
        return;
    }

    int currLastNo;
    if (currNum.length() >= 1)
        currLastNo = *(currNum.end() - 1) - '0';
    else
        currLastNo = 10; // 뒤에 붙이는 수는 제한 없음

    for (int i = 9; i >= 0; i--) // i: 뒤에 붙일 수
    {
        if (currLastNo <= i) // 뒤에 붙이는 수가 더 커서는 안됨
            continue;

        currNum.push_back(i + '0');
        GetNum(totalLength, currNum);
        currNum.pop_back();
        //cout << "returned to " << currNum << endl;

    }

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= 10; i++)
    {
        //cout << "totalLength:  " << i << endl;
        GetNum(i, "");
        //cout << "DONE" << endl;
    }

    //for (auto item : numbers)
        //cout << item << " ";

    sort(numbers.begin(), numbers.end());

    if (n - 1 >= numbers.size())
        cout << -1;
    else
        cout << numbers[n - 1];
}
