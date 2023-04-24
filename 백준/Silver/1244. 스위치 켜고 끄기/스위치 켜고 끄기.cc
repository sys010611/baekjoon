#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n; //스위치의 개수
	cin >> n;
	
	int* swtch = new int[n+1]; //각 스위치의 상태
	swtch[0] = -1;

	for (int i = 1; i <= n; i++)
	{
		cin >> swtch[i];
	}

	int m; //학생 수
	cin >> m;
	int gender, num; //성별, 받은 수
	while (m--)
	{
		cin >> gender >> num;

		if (gender == 1) //남학생 (배수)
		{
			for (int i = num; i <= n; i += num)
			{
				if(swtch[i] == 0)
					swtch[i] = 1;
				else
					swtch[i] = 0;
			}
		}
		else if (gender == 2) //여학생 (대칭)
		{
			int i;
			for (i = 1; num-i >= 1 && num+i <= n; i++)
			{
				if (swtch[num - i] == swtch[num + i])
					continue;
				else
					break;
			}
			i--;

			for (int k = num - i; k <= num + i; k++)
			{
				if (swtch[k] == 0)
					swtch[k] = 1;
				else
					swtch[k] = 0;
			}
		}
	}

	int count = 1;
	for (int i = 1; i < n+1; i++)
	{
		if (count > 20)
		{
			cout << endl;
			count = 1;
		}
		cout << swtch[i] << " ";
		count++;
	}
}