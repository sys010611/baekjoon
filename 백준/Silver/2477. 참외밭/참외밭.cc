#include <iostream>

using namespace std;

int main()
{
	int k; //1제곱미터당 참외 수
	cin >> k;

	int matrix[12][2]; //방향, 길이 저장 배열 
	int horizontalMax = 0;
	int verticalMax = 0;

	int entireSquare = 0;
	int trimmedSquare = 0;

	for (int i = 0; i < 6; i++)
	{
		int direction, length; //방향, 길이
		cin >> direction >> length;

		matrix[i][0] = direction;
		matrix[i][1] = length; // 배열에 저장

		//가로, 세로 최댓값 저장
		if ((direction == 1 || direction == 2) && length > horizontalMax) //동서 방향이고 현재 최대 길이보다 클 때
			horizontalMax = length;

		if ((direction == 3 || direction == 4) && length > verticalMax) //남북 방향이고 현재 최대 길이보다 클 때
			verticalMax = length;
	}
	entireSquare = horizontalMax * verticalMax;

	//배열의 나머지 반에 앞의 내용 복사
	for (int i = 0; i < 6; i++)
	{
		matrix[i + 6][0] = matrix[i][0];
		matrix[i + 6][1] = matrix[i][1];
	}

	/*for (int i = 0; i < 12; i++)
	{
		cout << "배열 확인" << endl;
		cout << matrix[i][0] << ", " << matrix[i][1] << endl;
	}*/


	for (int i = 0; i < 9; i++)
	{
		if (matrix[i][0] == matrix[i + 2][0] && matrix[i + 1][0] == matrix[i + 3][0])
		{
			trimmedSquare = matrix[i+1][1] * matrix[i+2][1];
			//cout << "작은 사각형: " << trimmedSquare << endl;
		}
	}

	cout << (entireSquare - trimmedSquare) * k;
}