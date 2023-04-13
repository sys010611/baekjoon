#include <iostream> 
#include <string>
#include <list>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		list<char> L;
		list<char>::iterator it;
		list<char>::iterator it2;

		string input;
		cin >> input;

		it = L.begin();

		for (int i = 0; i < input.length(); i++)
		{
			switch (input[i])
			{
				case '<':
					//cout << "커서 뒤로" << endl;
					if (it == L.begin())
						break;
					it--;
					break;
				case '>':
					//cout << "커서 앞으로" << endl;
					if(it == L.end())
						break;
					it++;
					break;
				case '-':
					//cout << "백스페이스" << endl;
					
					if (L.empty())
						break;

					//커서가 맨 앞으로 온 상황에서 -인 상황
					if (it == L.begin())
					{
						break;
					}
					it--;
					it = L.erase(it);
					break;
				default:
					//cout << "대/소문자" << endl;
					L.insert(it, input[i]);
					break;
			}
		}

		for (it2 = L.begin(); it2 != L.end(); it2++)
		{
			cout << *it2;
		}
		cout << endl;
	}

	return 0;
}

