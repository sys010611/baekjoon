#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

bool visited[20001];
char prevCommand[20001];
int prevNode[20001];

int D(int num)
{
	num *= 2;
	return num % 10000;
}
int S(int num)
{
	if(num == 0)
		return 9999;
	else
		return num-1;
}
int L(int num)
{
	/*string str = to_string(num);
	while (str.length() != 4)
	{
		str.insert(0, 1, '0');
	}

	string newStr;
	
	for (int i = 1; i < str.length(); i++)
	{
		newStr.push_back(str[i]);
	}
	newStr.push_back(str[0]);

	return stoi(newStr);*/
	return (num * 10) % 10000 + num/1000;
}
int R(int num)
{
	/*string str = to_string(num);
	while (str.length() != 4)
	{
		str.insert(0, 1, '0');
	}

	string newStr;
	newStr.push_back(str[str.length()-1]);
	for (int i = 0; i < str.length() - 1; i++)
	{
		newStr.push_back(str[i]);
	}

	return stoi(newStr);*/
	return (num/10) + (num%10 * 1000) % 10000;
}

void bfs(int startNum, int destNum)
{
	queue<int> Q;
	Q.push(startNum);
	visited[startNum] = true;
	while (!Q.empty())
	{
		int curr = Q.front(); Q.pop();
		
		if (curr == destNum)
		{
			// 명령어 쭉 정리해서 거꾸로 출력
			string result;

			while (prevNode[curr] != -1)
			{
				result.push_back(prevCommand[curr]);
				curr = prevNode[curr];
			}

			for (int i = result.length()-1; i >= 0; i--)
			{
				cout << result[i];
			}
			cout << endl;
		}

		int d = D(curr);
		int s = S(curr);
		int l = L(curr);
		int r = R(curr);


		if (!visited[d])
		{
			visited[d] = true;
			prevCommand[d] = 'D';
			prevNode[d] = curr;
			Q.push(d);
		}
		if (!visited[s])
		{
			visited[s] = true;
			prevCommand[s] = 'S';
			prevNode[s] = curr;
			Q.push(s);
		}
		if (!visited[l])
		{
			visited[l] = true;
			prevCommand[l] = 'L';
			prevNode[l] = curr;
			Q.push(l);
		}
		if (!visited[r])
		{
			visited[r] = true;
			prevCommand[r] = 'R';
			prevNode[r] = curr;
			Q.push(r);
		}
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
		fill(visited,visited+20001, false);
		fill(prevCommand, prevCommand + 20001, 0);
		fill(prevNode, prevNode + 20001, -1);

		int startNum, destNum;
		cin >> startNum >> destNum;

		bfs(startNum, destNum);
	}
}
