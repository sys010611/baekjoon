#include <iostream>
#include <algorithm>
using namespace std;

int k;
int arr[13];
int result[13];

void backtrack(int pos, int idx)
{
	//cout << "pos: " << pos << " idx: " << idx << endl;
	if (pos == 6) //꽉채웠을시 출력, 이전 단계로
	{
		for (int i = 0; i < 6; i++)
		{
			cout << result[i] <<  " ";
		}
		cout << endl;
		return;
	}
	
	for (int i = idx; i < k; i++)
	{
		result[pos] = arr[i];
		backtrack(pos + 1, i+1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	while (true)
	{
		cin >> k;
		if(k==0) return 0;

		for (int i = 0; i < k; i++)
		{
			cin >> arr[i];
		}

		backtrack(0, 0);
		cout << endl;
	}
	
}