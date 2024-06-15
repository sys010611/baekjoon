#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

#define int long long

struct line
{
	int start, end, number;
	line(int start, int end, int number)
	{
		this->start = start;
		this->end = end;
		this->number = number;
	}
};

int N, M;
vector<line> lines;

bool compare(line a, line b)
{
	if (a.start == b.start)
	{
		return a.end > b.end;
	}

	return a.start < b.start;
}

signed main()
{
	cin >> N;
	cin >> M;
	for (int i = 1; i <= M; i++)
	{
		int start, end;
		cin >> start >> end;

		// 한바퀴 도는 경우
		if (start > end)
		{
			end += N;
		}

		lines.push_back(line(start, end, i));
	}

	sort(lines.begin(), lines.end(), compare);

	//lines를 2개 이어붙이기
	int currLinesSize = lines.size();
	for (int i = 0; i < currLinesSize; i++)
	{
		lines.push_back(line(lines[i].start+N, lines[i].end+N, lines[i].number));
	}

	//cout << "노선 목록 : " << endl;
	//for (auto line : lines)
	//{
	//	cout << line.number << " : " <<  line.start << " - > " << line.end << endl;
	//}

	set<int> includingLines;
	includingLines.insert(lines[0].number);

	line prev = lines[0];

	int i;
	for (i = 1; i < lines.size()/2; i++)
	{
		line curr = lines[i];

		if (curr.end <= prev.end)
		{
		}
		else
		{
			includingLines.insert(curr.number);
			prev = curr;

		}

	}
	for (; i < lines.size(); i++)
	{
		line curr = lines[i];

		if (curr.end <= prev.end)
		{
			// prev가 curr을 포함한다면 curr은 버림
			includingLines.erase(curr.number);
		}
		else
		{
			prev = curr;

		}

	}

	for (auto item : includingLines)
	{
		cout << item << " ";
	}
}