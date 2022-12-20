#include <iostream>
#include <cmath>
using namespace std;

int Solution(int x1, int y1, int r1, int x2, int y2, int r2)
{
	double distBetween = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
	
	int tmp; // adjusting r1 to bigger, r2 to smaller
	if (r1 < r2)
	{
		tmp = r1;
		r1 = r2;
		r2 = tmp;
	}

	// equal
	if (distBetween == 0 && r1 == r2)
		return -1;

	//meets in one point(inside)
	else if (distBetween + r2 == r1)
		return 1;

	// meets in one point(outside)
	else if (distBetween == r1 + r2)
		return 1;

	// one contains the other && not equal
	else if (distBetween + r2 < r1 && !(distBetween == 0 && r1 == r2))
		return 0;

	// does not meet
	else if (distBetween > r1+r2)
		return 0;

	// meets in two point && no containing && not equal
	else if (distBetween < r1 + r2 && !(distBetween + r2 < r1) && !(distBetween == 0 && r1 == r2))
		return 2;
}

int main()
{
	int problemCount;

	cin >> problemCount;

	int* answer;
	answer = new int[problemCount];

	for (int i = 0; i < problemCount; i++)
	{
		int x1, y1, r1, x2, y2, r2;
		
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		answer[i] =  Solution(x1, y1, r1, x2, y2, r2);
	}

	for (int i = 0; i < problemCount; i++)
	{
		cout << answer[i] << "\n";
	}
}