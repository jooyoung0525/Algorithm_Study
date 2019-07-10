![큐빙](https://user-images.githubusercontent.com/29946480/60976613-5025fa00-a32e-11e9-913a-7e7597f3d3c1.PNG)
--------------------------------------------------------------------------------------------------------------
↓↓↓다시 손봐야함!(인덱스 번호)
--------------------------------------------------------------------------------------------------------------
```c
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>

using namespace std;
int T;
char cube[12][9];

void init_cube() //큐브 초기화
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 3; j < 6; j++)
			cube[i][j] = 'o';
	}
	for (int i = 3; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
			cube[i][j] = 'g';
	}
	for (int i = 3; i < 6; i++)
	{
		for (int j = 3; j < 6; j++)
			cube[i][j] = 'w';
	}
	for (int i = 3; i < 6; i++)
	{
		for (int j = 6; j < 9; j++)
			cube[i][j] = 'b';
	}
	for (int i = 6; i < 9; i++)
	{
		for (int j = 3; j < 6; j++)
			cube[i][j] = 'r';
	}
	for (int i = 9; i < 12; i++)
	{
		for (int j = 3; j < 6; j++)
			cube[i][j] = 'y';
	}

}

void standard_plane(string order) //기준면 회전 ※큐브를 돌리면 기준면도 같이 회전함※
{
	char temp[9];

	if (order == "U+" || order == "U-")
	{
		temp[0] = cube[3][3];
		temp[1] = cube[3][4];
		temp[2] = cube[3][5];
		temp[3] = cube[4][3];
		temp[4] = cube[4][4];
		temp[5] = cube[4][5];
		temp[6] = cube[5][3];
		temp[7] = cube[5][4];
		temp[8] = cube[5][5];
		
		if (order == "U+")
		{
			cube[3][3] = temp[6];
			cube[3][4] = temp[3];
			cube[3][5] = temp[0];
			cube[4][3] = temp[7];
			cube[4][4] = temp[4];
			cube[4][5] = temp[1];
			cube[5][3] = temp[8];
			cube[5][4] = temp[5];
			cube[5][5] = temp[2];
			
		}
		else if (order == "U-")
		{
			cube[3][3] = temp[2];
			cube[3][4] = temp[5];
			cube[3][5] = temp[8];
			cube[4][3] = temp[1];
			cube[4][4] = temp[4];
			cube[4][5] = temp[7];
			cube[5][3] = temp[0];
			cube[5][4] = temp[3];
			cube[5][5] = temp[6];
		}
	}

	if (order == "D+" || order == "D-")
	{
		temp[0] = cube[9][3];
		temp[1] = cube[9][4];
		temp[2] = cube[9][5];
		temp[3] = cube[10][3];
		temp[4] = cube[10][4];
		temp[5] = cube[10][5];
		temp[6] = cube[11][3];
		temp[7] = cube[11][4];
		temp[8] = cube[11][5];

		if (order == "D+")
		{
			cube[9][3] = temp[6];
			cube[9][4] = temp[3];
			cube[9][5] = temp[0];
			cube[10][3] = temp[7];
			cube[10][4] = temp[4];
			cube[10][5] = temp[1];
			cube[11][3] = temp[8];
			cube[11][4] = temp[5];
			cube[11][5] = temp[2];

		}
		else if (order == "D-")
		{
			cube[9][3] = temp[2];
			cube[9][4] = temp[5];
			cube[9][5] = temp[8];
			cube[10][3] = temp[1];
			cube[10][4] = temp[4];
			cube[10][5] = temp[7];
			cube[11][3] = temp[0];
			cube[11][4] = temp[3];
			cube[11][5] = temp[6];
		}
	}
	if (order == "F+" || order == "F-")
	{
		temp[0] = cube[6][3];
		temp[1] = cube[6][4];
		temp[2] = cube[6][5];
		temp[3] = cube[7][3];
		temp[4] = cube[7][4];
		temp[5] = cube[7][5];
		temp[6] = cube[8][3];
		temp[7] = cube[8][4];
		temp[8] = cube[8][5];

		if (order == "F+")
		{
			cube[6][3] = temp[6];
			cube[6][4] = temp[3];
			cube[6][5] = temp[0];
			cube[7][3] = temp[7];
			cube[7][4] = temp[4];
			cube[7][5] = temp[1];
			cube[8][3] = temp[8];
			cube[8][4] = temp[5];
			cube[8][5] = temp[2];

		}
		else if (order == "F-")
		{
			cube[6][3] = temp[2];
			cube[6][4] = temp[5];
			cube[6][5] = temp[8];
			cube[7][3] = temp[1];
			cube[7][4] = temp[4];
			cube[7][5] = temp[7];
			cube[8][3] = temp[0];
			cube[8][4] = temp[3];
			cube[8][5] = temp[6];
		}
	}
	if (order == "B+" || order == "B-")
	{
		temp[0] = cube[2][5];
		temp[1] = cube[2][4];
		temp[2] = cube[2][3];
		temp[3] = cube[1][5];
		temp[4] = cube[1][4];
		temp[5] = cube[1][3];
		temp[6] = cube[0][5];
		temp[7] = cube[0][4];
		temp[8] = cube[0][3];

		if (order == "B+")
		{
			cube[2][5] = temp[6];
			cube[2][4] = temp[3];
			cube[2][3] = temp[0];
			cube[1][5] = temp[7];
			cube[1][4] = temp[4];
			cube[1][3] = temp[1];
			cube[0][5] = temp[8];
			cube[0][4] = temp[5];
			cube[0][3] = temp[2];

		}
		else if (order == "B-")
		{
			cube[2][5] = temp[2];
			cube[2][4] = temp[5];
			cube[2][3] = temp[8];
			cube[1][5] = temp[1];
			cube[1][4] = temp[4];
			cube[1][3] = temp[7];
			cube[0][5] = temp[0];
			cube[0][4] = temp[3];
			cube[8][3] = temp[6];
		}
	}

	if (order == "L+" || order == "L-")
	{
		temp[0] = cube[3][2];
		temp[1] = cube[4][2];
		temp[2] = cube[5][2];
		temp[3] = cube[3][1];
		temp[4] = cube[4][1];
		temp[5] = cube[5][1];
		temp[6] = cube[3][0];
		temp[7] = cube[4][0];
		temp[8] = cube[5][0];

		if (order == "L+")
		{
			cube[3][2] = temp[6];
			cube[4][2] = temp[3];
			cube[5][2] = temp[0];
			cube[3][1] = temp[7];
			cube[4][1] = temp[4];
			cube[5][1] = temp[1];
			cube[3][0] = temp[8];
			cube[4][0] = temp[5];
			cube[5][0] = temp[2];

		}
		else if (order == "L-")
		{
			cube[3][2] = temp[2];
			cube[4][2] = temp[5];
			cube[5][2] = temp[8];
			cube[3][1] = temp[1];
			cube[4][1] = temp[4];
			cube[5][1] = temp[7];
			cube[3][0] = temp[0];
			cube[4][0] = temp[3];
			cube[5][0] = temp[6];
		}
	}

	if (order == "R+" || order == "R-")
	{
		temp[0] = cube[5][6];
		temp[1] = cube[4][6];
		temp[2] = cube[3][6];
		temp[3] = cube[5][7];
		temp[4] = cube[4][7];
		temp[5] = cube[3][7];
		temp[6] = cube[5][8];
		temp[7] = cube[4][8];
		temp[8] = cube[3][8];

		if (order == "R+")
		{
			cube[5][6] = temp[6];
			cube[4][6] = temp[3];
			cube[3][6] = temp[0];
			cube[5][7] = temp[7];
			cube[4][7] = temp[4];
			cube[3][7] = temp[1];
			cube[5][8] = temp[8];
			cube[4][8] = temp[5];
			cube[3][8] = temp[2];

		}
		else if (order == "R-")
		{
			cube[5][6] = temp[2];
			cube[4][6] = temp[5];
			cube[3][6] = temp[8];
			cube[5][7] = temp[1];
			cube[4][7] = temp[4];
			cube[3][7] = temp[7];
			cube[5][8] = temp[0];
			cube[4][8] = temp[3];
			cube[3][8] = temp[6];
		}
	}
}

void result() //큐브 윗면 ==> 결과 출력
{
	for (int i = 3; i < 6; i++)
	{
		for (int j = 3; j < 6; j++)
			printf("%c", cube[i][j]);
		printf("\n");
	}
}

void rolling_cube(string order) //큐브를 돌릴 때, 기준면 주위 돌아가는 큐브 구현 ☆★인덱스번호 다시 수정하기!!!!!!!!
{
	char temp[12];
	standard_plane(order);

	if (order == "U+" || order == "U-")
	{
		temp[0] = cube[2][3];
		temp[1] = cube[2][4];
		temp[2] = cube[2][5];
		temp[3] = cube[3][6];
		temp[4] = cube[4][6];
		temp[5] = cube[5][6];
		temp[6] = cube[6][5];
		temp[7] = cube[6][4];
		temp[8] = cube[6][3];
		temp[9] = cube[5][2];
		temp[10] = cube[4][2];
		temp[11] = cube[3][2];

		if (order == "U+")
		{
			cube[2][3] = temp[9];
			cube[2][4] = temp[10];
			cube[2][5] = temp[11];
			cube[3][6] = temp[0];
			cube[4][6] = temp[1];
			cube[5][6] = temp[2];
			cube[6][5] = temp[3];
			cube[6][4] = temp[4];
			cube[6][3] = temp[5];
			cube[5][2] = temp[6];
			cube[4][2] = temp[7];
			cube[3][2] = temp[8];
			
		}
		else if (order == "U-")
		{
			cube[2][3] = temp[3];
			cube[2][4] = temp[4];
			cube[2][5] = temp[5];
			cube[3][6] = temp[6];
			cube[4][6] = temp[7];
			cube[5][6] = temp[8];
			cube[6][5] = temp[9];
			cube[6][4] = temp[10];
			cube[6][3] = temp[11];
			cube[5][2] = temp[0];
			cube[4][2] = temp[1];
			cube[3][2] = temp[2];
			
		}
	}

	if (order == "D+" || order == "D-")
	{
		temp[0] = cube[8][3];
		temp[1] = cube[8][4];
		temp[2] = cube[8][5];
		temp[3] = cube[5][8];
		temp[4] = cube[4][8];
		temp[5] = cube[3][8];
		temp[6] = cube[0][5];
		temp[7] = cube[0][4];
		temp[8] = cube[0][3];
		temp[9] = cube[5][0];
		temp[10] = cube[4][0];
		temp[11] = cube[3][0];

		if (order == "D-")
		{
			cube[8][3] = temp[3];
			cube[8][4] = temp[4];
			cube[8][5] = temp[5];
			cube[5][8] = temp[6];
			cube[4][8] = temp[7];
			cube[3][8] = temp[8];
			cube[0][5] = temp[9];
			cube[0][4] = temp[10];
			cube[0][3] = temp[11];
			cube[5][0] = temp[0];
			cube[4][0] = temp[1];
			cube[3][0] = temp[2];
			
		}
		else if (order == "D+")
		{
			cube[0][3] = temp[3];
			cube[0][4] = temp[4];
			cube[0][5] = temp[5];
			cube[3][8] = temp[6];
			cube[4][8] = temp[7];
			cube[5][8] = temp[8];
			cube[0][5] = temp[9];
			cube[0][4] = temp[10];
			cube[0][3] = temp[11];
			cube[5][8] = temp[0];
			cube[4][8] = temp[1];
			cube[3][8] = temp[2];
			
		}
	}

	else if (order == "F+" || order == "F-")
	{
		temp[0] = cube[5][0];
		temp[1] = cube[5][1];
		temp[2] = cube[5][2];
		temp[3] = cube[5][3];
		temp[4] = cube[5][4];
		temp[5] = cube[5][5];
		temp[6] = cube[5][6];
		temp[7] = cube[5][7];
		temp[8] = cube[5][8];
		temp[9] = cube[9][5];
		temp[10] = cube[9][4];
		temp[11] = cube[9][3];

		if (order == "F+")
		{
			cube[5][0] = temp[9];
			cube[5][1] = temp[10];
			cube[5][2] = temp[11];
			cube[5][3] = temp[0];
			cube[5][4] = temp[1];
			cube[5][5] = temp[2];
			cube[5][6] = temp[3];
			cube[5][7] = temp[4];
			cube[5][8] = temp[5];
			cube[9][5] = temp[6];
			cube[9][4] = temp[7];
			cube[9][3] = temp[8];
			
		}
		else if (order == "F-")
		{
			cube[5][0] = temp[3];
			cube[5][1] = temp[4];
			cube[5][2] = temp[5];
			cube[5][3] = temp[6];
			cube[5][4] = temp[7];
			cube[5][5] = temp[8];
			cube[5][6] = temp[9];
			cube[5][7] = temp[10];
			cube[5][8] = temp[11];
			cube[9][5] = temp[0];
			cube[9][4] = temp[1];
			cube[9][3] = temp[2];
			
		}
	}

	else if (order == "B+" || order == "B-")
	{
		temp[0] = cube[3][0];
		temp[1] = cube[3][1];
		temp[2] = cube[3][2];
		temp[3] = cube[3][3];
		temp[4] = cube[3][4];
		temp[5] = cube[3][5];
		temp[6] = cube[3][6];
		temp[7] = cube[3][7];
		temp[8] = cube[3][8];
		temp[9] = cube[11][5];
		temp[10] = cube[11][4];
		temp[11] = cube[11][3];

		if (order == "B-")
		{
			cube[3][0] = temp[9];
			cube[3][1] = temp[10];
			cube[3][2] = temp[11];
			cube[3][3] = temp[0];
			cube[3][4] = temp[1];
			cube[3][5] = temp[2];
			cube[3][6] = temp[3];
			cube[3][7] = temp[4];
			cube[3][8] = temp[5];
			cube[11][5] = temp[6];
			cube[11][4] = temp[7];
			cube[11][3] = temp[8];
			
		}
		else if (order == "B+")
		{
			cube[3][0] = temp[3];
			cube[3][1] = temp[4];
			cube[3][2] = temp[5];
			cube[3][3] = temp[6];
			cube[3][4] = temp[7];
			cube[3][5] = temp[8];
			cube[3][6] = temp[9];
			cube[3][7] = temp[10];
			cube[3][8] = temp[11];
			cube[11][5] = temp[0];
			cube[11][4] = temp[1];
			cube[11][3] = temp[2];
			
		}
	}

	else if (order == "L+" || order == "L-")
	{
		temp[0] = cube[0][3];
		temp[1] = cube[1][3];
		temp[2] = cube[2][3];
		temp[3] = cube[3][3];
		temp[4] = cube[4][3];
		temp[5] = cube[5][3];
		temp[6] = cube[6][3];
		temp[7] = cube[7][3];
		temp[8] = cube[8][3];
		temp[9] = cube[9][3];
		temp[10] = cube[10][3];
		temp[11] = cube[11][3];

		if (order == "L+")
		{
			cube[0][3] = temp[9];
			cube[1][3] = temp[10];
			cube[2][3] = temp[11];
			cube[3][3] = temp[0];
			cube[4][3] = temp[1];
			cube[5][3] = temp[2];
			cube[6][3] = temp[3];
			cube[7][3] = temp[4];
			cube[8][3] = temp[5];
			cube[9][3] = temp[6];
			cube[10][3] = temp[7];
			cube[11][3] = temp[8];
			
		}

		else if (order == "L-")
		{
			cube[0][3] = temp[3];
			cube[1][3] = temp[4];
			cube[2][3] = temp[5];
			cube[3][3] = temp[6];
			cube[4][3] = temp[7];
			cube[5][3] = temp[8];
			cube[6][3] = temp[9];
			cube[7][3] = temp[10];
			cube[8][3] = temp[11];
			cube[9][3] = temp[0];
			cube[10][3] = temp[1];
			cube[11][3] = temp[2];
			
		}
	}
	else if (order == "R+" || order == "R-")
	{
		temp[0] = cube[0][5];
		temp[1] = cube[1][5];
		temp[2] = cube[2][5];
		temp[3] = cube[3][5];
		temp[4] = cube[4][5];
		temp[5] = cube[5][5];
		temp[6] = cube[6][5];
		temp[7] = cube[7][5];
		temp[8] = cube[8][5];
		temp[9] = cube[9][5];
		temp[10] = cube[10][5];
		temp[11] = cube[11][5];

		if (order == "R-")
		{
			cube[0][5] = temp[9];
			cube[1][5] = temp[10];
			cube[2][5] = temp[11];
			cube[3][5] = temp[0];
			cube[4][5] = temp[1];
			cube[5][5] = temp[2];
			cube[6][5] = temp[3];
			cube[7][5] = temp[4];
			cube[8][5] = temp[5];
			cube[9][5] = temp[6];
			cube[10][5] = temp[7];
			cube[11][5] = temp[8];
			
		}

		else if (order == "R+")
		{
			cube[0][5] = temp[3];
			cube[1][5] = temp[4];
			cube[2][5] = temp[5];
			cube[3][5] = temp[6];
			cube[4][5] = temp[7];
			cube[5][5] = temp[8];
			cube[6][5] = temp[9];
			cube[7][5] = temp[10];
			cube[8][5] = temp[11];
			cube[9][5] = temp[0];
			cube[10][5] = temp[1];
			cube[11][5] = temp[2];
			
		}
	}

}

int main()
{
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		int n;
		scanf("%d", &n);
		init_cube(); //테스트케이스 시작마다 큐브 초기화

		for (int j = 0; j < n; j++)
		{
			string order; //string을 이용해야한다. char은 문자 1개밖에 입력못받음 ==> 'R-' 두개의 문자이기 때문
			cin >> order;

			rolling_cube(order);
		}
		result(); //n만큼 회전 후에 결과 출력
	}
	return 0;
}
```
      
