#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int GetNext(int num)
{
	int result = num;
	while (num > 0)
	{
		result += num%10;
		num/=10;
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	bool isSelfNum[10001];
	fill(isSelfNum, isSelfNum+10001, true);

	for (int i = 1; i <= 10000; i++)
	{
		int next = GetNext(i);
		if (next >= 10001)
		{
			continue;
		}
		isSelfNum[next] = false;
		//cout << next << " : " << "셀프넘버 아님" << endl;
	}

	for (int i = 1; i <= 10000; i++)
	{
		if (isSelfNum[i])
		{
			cout << i << endl;
		}
	}
}