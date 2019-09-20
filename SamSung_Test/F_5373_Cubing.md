
----------------------------------------------------------------------------------------------------

### 아아아아아아가가가가가갸갸갹 뭐가틀린거야!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
### 진짜 맞추고싶다ㅠㅠ

--------------------------------------------------------------------------------------------------------

## 풀이 1. (틀림)

```c
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>

using namespace std;

int T = 0;
string method;
char cube[20][20] = {"\0",};
char temp[20][20] = { "\0", };

void print();
void init();
void copy();
void cubing(string method);

int main()
{
	cin >> T;
	while(T--)
	{
		int n = 0;
		init();
		cin >> n;

		while(n--)
		{
			cin >> method;
			copy();
			cubing(method);	
		}
		print();
	}
	
	system("pause");
	return 0;
}

void init()
{
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 3; j < 6; j++)
		{
			cube[i][j] = 'o';
		}
	}
	
	for (int i = 3; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cube[i][j] = 'g';
		}
	}
	
	for (int i = 3; i < 6; i++)
	{
		for (int j = 3; j < 6; j++)
		{
			cube[i][j] = 'w';
		}
	}
	
	for (int i = 3; i < 6; i++)
	{
		for (int j = 6; j < 9; j++)
		{
			cube[i][j] = 'b';
		}
	}
	
	for (int i = 6; i < 9; i++)
	{
		for (int j = 3; j < 6; j++)
		{
			cube[i][j] = 'r';
		}
	}

	
	for (int i = 9; i < 12; i++)
	{
		for (int j = 3; j < 6; j++)
		{
			cube[i][j] = 'y';
		}
	}
}

void print()
{
	for (int i = 3; i < 6; i++)
	{
		for (int j = 3; j < 6; j++)
		{
			printf("%c", cube[i][j]);
		}
		cout << endl;
	}
}

void copy()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			temp[i][j] = cube[i][j];
		}
	}

	

}

void cubing(string method)
{
	if (method == "U+")
	{
		cube[3][5] = temp[3][3];
		cube[4][5] = temp[3][4];
		cube[5][5] = temp[3][5];
		cube[3][4] = temp[4][3];
		cube[4][4] = temp[4][4];
		cube[5][4] = temp[4][5];
		cube[3][3] = temp[5][3];
		cube[4][3] = temp[5][4];
		cube[5][3] = temp[5][5];

		cube[3][6] = temp[2][3];
		cube[4][6] = temp[2][4];
		cube[5][6] = temp[2][5];
		cube[6][5] = temp[3][6];
		cube[6][4] = temp[4][6];
		cube[6][3] = temp[5][6];
		cube[5][2] = temp[6][5];
		cube[4][2] = temp[6][4];
		cube[3][2] = temp[6][3];
		cube[2][3] = temp[5][2];
		cube[2][4] = temp[4][2];
		cube[2][5] = temp[3][2];
		
	}
	else if (method == "U-")
	{
		cube[5][3] = temp[3][3];
		cube[4][3] = temp[3][4];
		cube[3][3] = temp[3][5];
		cube[5][4] = temp[4][3];
		cube[4][4] = temp[4][4];
		cube[3][4] = temp[4][5];
		cube[5][5] = temp[5][3];
		cube[4][5] = temp[5][4];
		cube[3][5] = temp[5][5];

		cube[5][2] = temp[2][3];
		cube[4][2] = temp[2][4];
		cube[3][2] = temp[2][5];
		cube[2][3] = temp[3][6];
		cube[2][4] = temp[4][6];
		cube[2][5] = temp[5][6];
		cube[3][6] = temp[6][5];
		cube[4][6] = temp[6][4];
		cube[5][6] = temp[6][3];
		cube[6][5] = temp[5][2];
		cube[6][4] = temp[4][2];
		cube[6][3] = temp[3][2];
		
	}
	else if (method == "D+")
	{
		cube[9][5] = temp[9][3];
		cube[10][5] = temp[9][4];
		cube[11][5] = temp[9][5];
		cube[9][4] = temp[10][3];
		cube[10][4] = temp[10][4];
		cube[11][4] = temp[10][5];
		cube[9][3] = temp[11][3];
		cube[10][3] = temp[11][4];
		cube[11][3] = temp[11][5];

		cube[5][8] = temp[8][3];
		cube[4][8] = temp[8][4];
		cube[3][8] = temp[8][5];
		cube[0][5] = temp[5][8];
		cube[0][4] = temp[4][8];
		cube[0][3] = temp[3][8];
		cube[3][0] = temp[0][5];
		cube[4][0] = temp[0][4];
		cube[5][0] = temp[0][3];
		cube[8][3] = temp[3][0];
		cube[8][4] = temp[4][0];
		cube[8][5] = temp[5][0];

	}
	else if (method == "D-")
	{
		cube[11][3] = temp[9][3];
		cube[10][3] = temp[9][4];
		cube[9][3] = temp[9][5];
		cube[11][4] = temp[10][3];
		cube[10][4] = temp[10][4];
		cube[9][4] = temp[10][5];
		cube[11][5] = temp[11][3];
		cube[10][5] = temp[11][4];
		cube[9][5] = temp[11][5];

		cube[3][0] = temp[8][3];
		cube[4][0] = temp[8][4];
		cube[5][0] = temp[8][5];
		cube[8][3] = temp[5][8];
		cube[8][4] = temp[4][8];
		cube[8][5] = temp[3][8];
		cube[5][8] = temp[0][5];
		cube[4][8] = temp[0][4];
		cube[3][8] = temp[0][3];
		cube[0][5] = temp[3][0];
		cube[0][4] = temp[4][0];
		cube[0][3] = temp[5][0];

	}
	else if (method == "F+")
	{
		cube[6][5] = temp[6][3];
		cube[7][5] = temp[6][4];
		cube[8][5] = temp[6][5];
		cube[6][4] = temp[7][3];
		cube[7][4] = temp[7][4];
		cube[8][4] = temp[7][5];
		cube[6][3] = temp[8][3];
		cube[7][3] = temp[8][4];
		cube[8][3] = temp[8][5];

		cube[5][0] = temp[9][5];
		cube[5][1] = temp[9][4];
		cube[5][2] = temp[9][3];
		cube[9][5] = temp[5][6];
		cube[9][4] = temp[5][7];
		cube[9][3] = temp[5][8];

		for (int i = 0; i < 6; i++)
		{
			cube[5][i+3] = temp[5][i];
		}
		
	}
	else if (method == "F-")
	{
		cube[8][3] = temp[6][3];
		cube[7][3] = temp[6][4];
		cube[6][3] = temp[6][5];
		cube[8][4] = temp[7][3];
		cube[7][4] = temp[7][4];
		cube[6][4] = temp[7][5];
		cube[8][5] = temp[8][3];
		cube[7][5] = temp[8][4];
		cube[6][5] = temp[8][5];

		cube[5][6] = temp[9][5];
		cube[5][7] = temp[9][4];
		cube[5][8] = temp[9][3];
		cube[9][3] = temp[5][0];
		cube[9][4] = temp[5][1];
		cube[9][5] = temp[5][2];

		for (int i = 3; i < 9; i++)
		{
			cube[5][i - 3] = temp[5][i];
		}
	}
	else if (method == "B+")
	{
		cube[2][3] = temp[2][5];
		cube[1][3] = temp[2][4];
		cube[0][3] = temp[2][3];
		cube[2][4] = temp[1][5];
		cube[1][4] = temp[1][4];
		cube[0][4] = temp[1][3];
		cube[2][5] = temp[0][5];
		cube[1][5] = temp[0][4];
		cube[0][5] = temp[0][3];

		cube[11][3] = temp[3][2];
		cube[11][4] = temp[3][1];
		cube[11][5] = temp[3][0];
		cube[3][8] = temp[11][3];
		cube[3][7] = temp[11][4];
		cube[3][6] = temp[11][5];

		for (int i = 8; i >=3; i--)
		{
			cube[3][i - 3] = temp[3][i];
		}
	}
	else if (method == "B-")
	{
		cube[0][5] = temp[2][5];
		cube[1][5] = temp[2][4];
		cube[2][5] = temp[2][3];
		cube[0][4] = temp[1][5];
		cube[1][4] = temp[1][4];
		cube[2][4] = temp[1][3];
		cube[0][3] = temp[0][5];
		cube[1][3] = temp[0][4];
		cube[2][3] = temp[0][3];

		cube[11][5] = temp[3][8];
		cube[11][4] = temp[3][7];
		cube[11][3] = temp[3][6];
		cube[3][2] = temp[11][3];
		cube[3][1] = temp[11][4];
		cube[3][0] = temp[11][5];

		for (int i = 5; i >= 0; i--)
		{
			cube[3][i + 3] = temp[3][i];
		}
	}
	else if (method == "L+")
	{
		cube[5][2] = temp[3][2];
		cube[5][1] = temp[4][2];
		cube[5][0] = temp[5][2];
		cube[4][2] = temp[3][1];
		cube[4][1] = temp[4][1];
		cube[4][0] = temp[5][1];
		cube[3][2] = temp[3][0];
		cube[3][1] = temp[4][0];
		cube[3][0] = temp[5][0];

		cube[0][3] = temp[9][3];
		cube[1][3] = temp[10][3];
		cube[2][3] = temp[11][3];

		for (int i =0; i < 9; i++)
			cube[i+3][3] = temp[i][3];
	}
	else if (method == "L-")
	{
		
		cube[3][0] = temp[3][2];
		cube[3][1] = temp[4][2];
		cube[3][2] = temp[5][2];
		cube[4][0] = temp[3][1];
		cube[4][1] = temp[4][1];
		cube[4][2] = temp[5][1];
		cube[5][0] = temp[3][0];
		cube[5][1] = temp[4][0];
		cube[5][2] = temp[5][0];

		cube[9][3] = temp[0][3];
		cube[10][3] = temp[1][3];
		cube[11][3] = temp[2][3];

		for (int i = 3; i < 12; i++)
			cube[i - 3][3] = temp[i][3];
		
	}
	else if (method == "R+")
	{
		cube[3][6] = temp[5][6];
		cube[3][7] = temp[4][6];
		cube[3][8] = temp[3][6];
		cube[4][6] = temp[5][7];
		cube[4][7] = temp[4][7];
		cube[4][8] = temp[3][7];
		cube[5][6] = temp[5][8];
		cube[5][7] = temp[4][8];
		cube[5][8] = temp[3][8];

		cube[9][5] = temp[0][5];
		cube[10][5] = temp[1][5];
		cube[11][5] = temp[2][5];

		for (int i = 3; i < 12; i++)
			cube[i - 3][5] = temp[i][5];
	}
	else if (method == "R-")
	{
		cube[5][8] = temp[5][6];
		cube[5][7] = temp[4][6];
		cube[5][6] = temp[3][6];
		cube[4][8] = temp[5][7];
		cube[4][7] = temp[4][7];
		cube[4][6] = temp[3][7];
		cube[3][8] = temp[5][8];
		cube[3][7] = temp[4][8];
		cube[3][6] = temp[3][8];

		cube[0][5] = temp[9][5];
		cube[1][5] = temp[10][5];
		cube[2][5] = temp[11][5];

		for (int i = 0; i < 9; i++)
			cube[i + 3][5] = temp[i][5];
	}
}


```
