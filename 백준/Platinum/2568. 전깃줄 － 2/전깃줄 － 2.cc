#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int,int> P;
const int INF = 10000000;

vector<P> arr; // A 전봇대 번호, B 전봇대 번호
vector<int> lastNumOnLength;
int arrToLIS[100001]; //Arr에서 i번째에 있는 수의 LIS에서의 인덱스
int N;
int LIS_length = 0;
bool isToCut[500001];


void PrintArr()
{
	cout << "-------- 전봇대 현황 --------------" << endl;
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i].first << " -> " << arr[i].second << endl;
	}
	cout << "-------------------------------" << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(isToCut, 0, sizeof(isToCut));

	cin >> N;

	lastNumOnLength.resize(N+1);
	fill(lastNumOnLength.begin(), lastNumOnLength.end(), INF);
	lastNumOnLength[0] = 0; // 길이가 0인 수열의 마지막 숫자 = 0;

	int a,b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;

		arr.push_back(P(a, b));
		isToCut[a] = true; // 일단 전깃줄들은 다 잘라야한다고 지정.
	}
	sort(arr.begin(), arr.end());

	//PrintArr();

	// LIS 길이 찾기, ArrToLis 배열 채우기
	for (int i = 0; i < arr.size(); i++)
	{
		int currNum = arr[i].second;
		int idx = lower_bound(lastNumOnLength.begin(), lastNumOnLength.end(), currNum) - lastNumOnLength.begin();

		lastNumOnLength[idx] = currNum;

		arrToLIS[i] = idx;

		if (idx > LIS_length)
		{
			LIS_length = idx;
		}
	}

	// 실제 LIS 구하기
	vector<P> LIS;

	int currLisLength = LIS_length;
	for (int i = arr.size()-1; i >= 0 && currLisLength >= 1; i--)
	{
		if (arrToLIS[i] == currLisLength)
		{
			LIS.push_back(arr[i]);
			isToCut[arr[i].first] = false; //실제 LIS에 들어가는 전깃줄은 자를 필요 없음.
			currLisLength--;
		}
	}

	//cout << "유지할 전깃줄 목록: " << endl;
	//for (auto it = LIS.begin(); it != LIS.end(); it++)
	//{
	//	cout << it->first << "->" << it->second << endl;
	//}

	//cout << "자를 전깃줄 개수 : " << arr.size() - LIS.size() << endl;
	cout << arr.size() - LIS.size() << "\n";

	//cout << "잘라야할 것들: " << endl;
	for (auto it = arr.begin(); it != arr.end(); it++)
	{
		if (isToCut[it->first] == true)
		{
			//cout << it->first << "->" << it->second << endl;
			cout << it->first << "\n";
		}
	}
}