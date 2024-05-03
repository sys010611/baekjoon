#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <deque>
using namespace std;

int fail[50000];

void MakeFailArr(const string& W)
{
	memset(fail, 0, sizeof(fail));

	int N = W.length();

	for (int i = 1, j = 0; i < N; i++)
	{
		while (j > 0 && W[i] != W[j])
		{
			j = fail[j - 1];
		}

		if (W[i] == W[j])
		{
			fail[i] = ++j;
		}
	}
}

int KMP(const string& S, const string& W)
{
	//cout << S << "에서 " << W << "가 몇번 나오는지 " << endl;

	int count = 0;

	int N = S.length();

	for (int i = 0, j = 0; i < N; i++)
	{
		//cout << "i : " << i << ", j : " << j << endl;
		while (j > 0 && S[i] != W[j])
		{
			j = fail[j-1];
		}

		if (S[i] == W[j])
		{
			if (j == W.length() - 1) // 단어를 찾았다면
			{
				count++;
			}
			j++;
		}
	}

	return count;
}

void PrintFailArr(std::string& word)
{
	for (int i = 0; i < word.length(); i++)
	{
		printf("fail[%d] : %d\n", i, fail[i]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while (t--)
	{
		vector<int> successShifts;

		string A, W, S;
		cin >> A >> W >> S;

		deque<char> alphabetOrder;
		for (int i = 0; i < A.length(); i++)
		{
			alphabetOrder.push_back(A[i]);
		}

		vector<int> wordIdx;
		for (int i = 0; i < W.length(); i++)
		{
			for (int j = 0; j < alphabetOrder.size(); j++)
			{
				if (W[i] == alphabetOrder[j])
				{
					wordIdx.push_back(j);
				}
			}
		}
		
		for (int i = 0; i < A.length(); i++) // shift 양을 1 씩 늘리면서 원문에서 word를 뽑아내기
		{
			//cout << "현재 shift : " << i << endl;
			string word;
			word.resize(W.length());

			for (int i = 0; i < wordIdx.size(); i++)
			{
				word[i] = alphabetOrder[wordIdx[i]];
			}

			MakeFailArr(word);

			//PrintFailArr(word);

			int count = KMP(S, word); // 암호문 S에서 word가 몇번 나오는지 찾는다.
			//cout << "word가 " << count << "번 발견됨" << endl;
			if(count == 1)
				successShifts.push_back(i);

			// KMP 완료 후, 한칸 shift 시킨다.
			int first = alphabetOrder.front();
			alphabetOrder.pop_front();
			alphabetOrder.push_back(first);
		}

		if (successShifts.size() == 0)
		{
			cout << "no solution" << endl;
		}
		else if (successShifts.size() == 1)
		{
			cout << "unique: " << successShifts[0] << endl;
		}
		else
		{
			cout << "ambiguous:";
			for (auto shift : successShifts)
			{
				cout << " " << shift;
			}
			cout << endl;
		}
	}
}