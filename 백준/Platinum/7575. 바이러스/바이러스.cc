#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <deque>
using namespace std;

int N, K;
vector<int> program[100];

void MakeFailArr(const deque<int>& W, int* fail)
{
	fill(fail, fail+1000, 0);

	for (int i = 1, j = 0; i < W.size(); i++)
	{
		while (j > 0 && W[i] != W[j])
		{
			j = fail[j-1];
		}

		if (W[i] == W[j])
		{
			fail[i] = ++j;
		}
	}

	//for (int i = 0; i < W.size(); i++)
	//{
	//	printf("fail[%d] = %d\n", i, fail[i]);
	//}
}

bool KMP(const vector<int>& S, const deque<int>& W)
{
	int fail[1000];
	MakeFailArr(W, fail);

	//cout << "S : ";
	//for(auto i : S) cout << i << " ";
	//cout << endl;
	//cout << "W : ";
	//for (auto i : W) cout << i << " ";
	//cout << endl;

	for (int i = 0, j = 0; i < S.size(); i++)
	{
		//cout << "i : " << i << ", j: " << j << endl;
		while (j > 0 && S[i] != W[j])
		{
			j = fail[j-1];
		}

		if (S[i] == W[j])
		{
			if (j == W.size() - 1) // 단어가 발견된 순간 바로 true 리턴
			{
				return true;
			}
			j++;
		}
	}

	return false;
}

void PrintPrograms()
{
	for (int i = 0; i < N; i++)
	{
		cout << "program " << i << " : ";
		for (int j = 0; j < program[i].size(); j++)
		{
			cout << program[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int length;
		cin >> length;
		for (int j = 0; j < length; j++)
		{
			int input;
			cin >> input;
			program[i].push_back(input);
		}
	}

	//PrintPrograms();

	if (program[0].size() < K) // 0번에서 부분문자열을 뽑아내기에 길이가 부족한 경우 바로 NO
	{
		cout << "NO";
		return 0;
	}

	// 문자열 0에서 길이 k인 부분문자열을 뽑아내기
	for (int i = 0; i <= program[0].size() - K; i++)
	{
		bool result = true; //이번 시행의 성공 여부

		deque<int> W;
		deque<int> W_reversed;
		for (int j = i; j < i+K; j++)
		{
			W.push_back(program[0][j]);
			W_reversed.push_front(program[0][j]);
		}

		//cout << "현재 문자열 : ";
		//for(auto num :W)	
		//	cout << num << " ";
		//cout << " / ";
		//for (auto num : W_reversed)
		//	cout << num << " ";
		//cout << endl;

		//뽑아낸 부분 문자열이 다른 문자열들에 포함되어있는지 확인, 모두 포함되어있다면 YES 출력
		for (int p = 1; p < N; p++)
		{
			if (program[p].size() < K) // 다른 문자열의 길이가 K보다 작은 경우 바로 NO 출력
			{
				cout << "NO";
				return 0;
			}

			if (KMP(program[p], W) || KMP(program[p], W_reversed))
			{
				//cout << p << " 번 프로그램에 포함 확인" << endl;
			}
			else
			{
				//cout << p << " 번 프로그램에 미포함" << endl;
				result = false;
				break;
			}
		}

		if (result == true)
		{
			cout << "YES";
			return 0;
		}
	}
	
	//여기까지 왔으면 실패
	cout << "NO";
}