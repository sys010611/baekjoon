#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int n;
int S[20][20];
bool aTeam[20]; //true: A팀 false : B팀
int result = 100000;

int Calculate()
{
	int aTeamS=0;
	int bTeamS=0;

	/*for (int i = 0; i < n; i++)
	{
		if (aTeam[i])
		{
			cout << "A";
		}
		else
		{
			cout << "B";
		}
	}
	cout << endl;*/

	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (aTeam[i] && aTeam[j])
			{
				aTeamS += S[i][j];
				aTeamS += S[j][i];
			}
			else if (!aTeam[i] && !aTeam[j])
			{
				bTeamS += S[i][j];
				bTeamS += S[j][i];
			}
		}
	}

	//cout << "ateam: " << aTeamS << endl;
	//cout << "bteam: " << bTeamS << endl;
	//cout << "능력치차: " << abs(aTeamS - bTeamS) << endl;

	if (abs(aTeamS - bTeamS) < result)
	{
		return abs(aTeamS - bTeamS);
	}
	else
	{
		return result;
	}
}

void MakeTeam(int count, int idx) //count : A팀의 멤버 수   idx: 이번에 a팀에 넣을 사람의 번호
{
	if (count == n / 2)
	{
		result = Calculate();
		if (result == 0)
		{
			cout << 0;
			exit(0);
		}
		return;
	}

	for (int i = idx; i < n; i++)
	{
		aTeam[i] = true;
		MakeTeam(count+1, i+1);
		aTeam[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> S[i][j];
		}
	}

	MakeTeam(0,0);

	cout << result;
}