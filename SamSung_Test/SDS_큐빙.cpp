//큐빙!! 큐 --> 선입선출 

#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
int M, P, T;
int C[101] = { 0 };
int origin_cube[12][9] = { 0 };
int cube[12][9] = { 0 };

void IInput();
void makecube();
void PPrint(int num,int N);
void Rotate(int num);

int main()
{
	cin >> T;
	makecube();

	for (int q = 1; q <= T; q++) {

		memset(C, 0, sizeof(C));
		memcpy(cube, origin_cube, sizeof(origin_cube));
		M, P = 0;

		IInput();
		
		for (int i = 0; i < M; i++)
		{
			Rotate(C[i]);
		}

		PPrint(P,q);
	}
	return 0;
}

void makecube()
{
	queue<int>Q;
	for (int i = 1; i < 55; i++)
	{
		Q.push(i);
	}
	//1
	for (int i = 0; i < 3; i++)
	{
		for (int j = 3; j < 6; j++)
		{
			origin_cube[i][j] = Q.front();
			Q.pop();
		}
	}

	//2
	for (int i = 3; i < 6; i++)
	{
		for (int j = 3; j < 6; j++)
		{
			origin_cube[i][j] = Q.front();
			Q.pop();
		}
	}

	//3
	for (int i = 6; i < 9; i++)
	{
		for (int j = 3; j < 6; j++)
		{
			origin_cube[i][j] = Q.front();
			Q.pop();
		}
	}

	//4
	for (int i = 9; i < 12; i++)
	{
		for (int j = 3; j < 6; j++)
		{
			origin_cube[i][j] = Q.front();
			Q.pop();
		}
	}

	//5
	for (int i = 3; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			origin_cube[i][j] = Q.front();
			Q.pop();
		}
	}

	//6
	for (int i = 3; i < 6; i++)
	{
		for (int j = 6; j < 9; j++)
		{
			origin_cube[i][j] = Q.front();
			Q.pop();
		}
	}
}

void IInput()
{
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> C[i];
	}
	cin >> P;
}

void PPrint(int num, int N)
{
	if (num == 1)
	{
		cout << "#" << N << " ";
		for (int i = 0; i < 3; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				cout << cube[i][j]<<" ";
			}
		}
		cout << "\n";
		return;
	}

	if (num == 2)
	{
		cout << "#" << N << " ";
		for (int i = 3; i < 6; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				cout << cube[i][j] << " ";
			}
		}
		cout << "\n";
		return;
	}

	if (num == 3)
	{
		cout << "#" << N << " ";
		for (int i = 6; i < 9; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				cout << cube[i][j] << " ";
			}
		}
		cout << "\n";
		return;
	}

	if (num == 4)
	{
		cout << "#" << N << " ";
		for (int i = 9; i < 12; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				cout << cube[i][j] << " ";
			}
		}
		cout << "\n";
		return;
	}

	if (num == 5)
	{
		cout << "#" << N << " ";
		for (int i = 3; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << cube[i][j] << " ";
			}
		}
		cout << "\n";
		return;
	}

	if (num == 6)
	{
		cout << "#" << N << " ";
		for (int i = 3; i < 6; i++)
		{
			for (int j = 6; j < 9; j++)
			{
				cout << cube[i][j] << " ";
			}
		}
		cout << "\n";
		return;
	}

}

void Rotate(int num)
{
	queue<int>side,body;

	if (num == 1)
	{
		//queue에 값넣기
		for (int i = 0; i < 12; i++)
		{
			side.push(cube[i][3]);
		}
		for (int i = 3; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				body.push(cube[i][j]);
			}
		}

		//회전
		for (int i = 9; i < 12; i++)
		{
			cube[i][3] = side.front();
			side.pop();
		}
		for (int i = 0; i < 9; i++)
		{
			cube[i][3] = side.front();
			side.pop();
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 5; j >= 3; j--)
			{
				cube[j][i] = body.front();
				body.pop();
			}
		}
		return;
	}

	if (num == 2)
	{
		//queue에 값 넣기
		for (int i = 0; i < 12; i++)
		{
			side.push(cube[i][4]);
		}

		//회전
		for (int i = 9; i < 12; i++)
		{
			cube[i][4] = side.front();
			side.pop();
		}
		for (int i = 0; i < 9; i++)
		{
			cube[i][4] = side.front();
			side.pop();
		}
		return;
	}

	if (num == 3)
	{
		//queue에 값넣기
		for (int i = 0; i < 12; i++)
		{
			side.push(cube[i][5]);
		}
		for (int i = 3; i < 6; i++)
		{
			for (int j = 6; j < 9; j++)
			{
				body.push(cube[i][j]);
			}
		}

		//회전
		for (int i = 9; i < 12; i++)
		{
			cube[i][5] = side.front();
			side.pop();
		}
		for (int i = 0; i < 9; i++)
		{
			cube[i][5] = side.front();
			side.pop();
		}

		for (int i = 8; i >= 6; i--)
		{
			for (int j = 3; j < 6; j++)
			{
				cube[j][i] = body.front();
				body.pop();
			}
		}
		return;
	}

	if (num == 4)
	{
		//queue에 값넣기
		for (int i = 0; i < 12; i++)
		{
			side.push(cube[i][3]);
		}
		for (int i = 3; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				body.push(cube[i][j]);
			}
		}

		//회전
		for (int i = 3; i < 12; i++)
		{
			cube[i][3] = side.front();
			side.pop();
		}
		for (int i = 0; i < 3; i++)
		{
			cube[i][3] = side.front();
			side.pop();
		}

		for (int i = 2; i >= 0; i--)
		{
			for (int j = 3; j < 6; j++)
			{
				cube[j][i] = body.front();
				body.pop();
			}
		}
		return;
	}

	if (num == 5)
	{
		//queue에 값 넣기
		for (int i = 0; i < 12; i++)
		{
			side.push(cube[i][4]);
		}

		//회전
		for (int i = 3; i < 12; i++)
		{
			cube[i][4] = side.front();
			side.pop();
		}
		for (int i = 0; i < 3; i++)
		{
			cube[i][4] = side.front();
			side.pop();
		}
		return;
	}

	if (num == 6)
	{
		//queue에 값넣기
		for (int i = 0; i < 12; i++)
		{
			side.push(cube[i][5]);
		}
		for (int i = 3; i < 6; i++)
		{
			for (int j = 6; j < 9; j++)
			{
				body.push(cube[i][j]);
			}
		}

		//회전
		for (int i = 3; i < 12; i++)
		{
			cube[i][5] = side.front();
			side.pop();
		}
		for (int i = 0; i < 3; i++)
		{
			cube[i][5] = side.front();
			side.pop();
		}

		for (int i = 6; i < 9; i++)
		{
			for (int j = 5; j >= 3; j--)
			{
				cube[j][i] = body.front();
				body.pop();
			}
		}
		return;
	}

	if (num == 7)
	{
		//값넣기
		for (int i = 0; i < 9; i++)
		{
			side.push(cube[3][i]);
		}
		for (int i = 5; i >= 3; i--)
		{
			side.push(cube[11][i]);
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				body.push(cube[i][j]);
			}
		}

		//회전
		for (int i = 5; i >= 3; i--)
		{
			cube[11][i] = side.front();
			side.pop();
		}
		for (int i = 0; i < 9; i++)
		{
			cube[3][i] = side.front();
			side.pop();
		}

		for (int i = 5; i >= 3; i--)
		{
			for (int j = 0; j < 3; j++)
			{
				cube[j][i] = body.front();
				body.pop();
			}
		}
		return;
	}

	if (num == 8)
	{
		//값 넣기
		for (int i = 0; i < 9; i++)
		{
			side.push(cube[4][i]);
		}
		for (int i = 5; i >= 3; i--)
		{
			side.push(cube[10][i]);
		}

		//회전
		for (int i = 5; i >= 3; i--)
		{
			cube[10][i] = side.front();
			side.pop();
		}
		for (int i = 0; i < 9; i++)
		{
			cube[4][i] = side.front();
			side.pop();
		}
		return;
	}

	if (num == 9)
	{
		//값넣기
		for (int i = 0; i < 9; i++)
		{
			side.push(cube[5][i]);
		}
		for (int i = 5; i >= 3; i--)
		{
			side.push(cube[9][i]);
		}

		for (int i = 6; i < 9; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				body.push(cube[i][j]);
			}
		}

		//회전
		for (int i = 5; i >= 3; i--)
		{
			cube[9][i] = side.front();
			side.pop();
		}
		for (int i = 0; i < 9; i++)
		{
			cube[5][i] = side.front();
			side.pop();
		}

		for (int i = 3; i < 6; i++)
		{
			for (int j = 8; j >= 6; j--)
			{
				cube[j][i] = body.front();
				body.pop();
			}
		}
		return;
	}


	if (num == 10)
	{
		//값넣기
		for (int i = 0; i < 9; i++)
		{
			side.push(cube[3][i]);
		}
		for (int i = 5; i >= 3; i--)
		{
			side.push(cube[11][i]);
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				body.push(cube[i][j]);
			}
		}

		//회전
		for (int i = 3; i < 9; i++)
		{
			cube[3][i] = side.front();
			side.pop();
		}
		for (int i = 5; i >= 3; i--)
		{
			cube[11][i] = side.front();
			side.pop();
		}
		for (int i = 0; i < 3; i++)
		{
			cube[3][i] = side.front();
			side.pop();
		}

		for (int i = 3; i < 6; i++)
		{
			for (int j = 2; j >= 0; j--)
			{
				cube[j][i] = body.front();
				body.pop();
			}
		}
		return;
	}

	if(num == 11)
	{ //값 넣기
		for (int i = 0; i < 9; i++)
		{
			side.push(cube[4][i]);
		}
		for (int i = 5; i >= 3; i--)
		{
			side.push(cube[10][i]);
		}

		//회전
		for (int i = 3; i < 9; i++)
		{
			cube[4][i] = side.front();
			side.pop();
		}
		for (int i = 5; i >= 3; i--)
		{
			cube[10][i] = side.front();
			side.pop();
		}
		for (int i = 0; i < 3; i++)
		{
			cube[4][i] = side.front();
			side.pop();
		}
		return;
	}


	if (num == 12)
	{
		//값넣기
		for (int i = 0; i < 9; i++)
		{
			side.push(cube[5][i]);
		}
		for (int i = 5; i >= 3; i--)
		{
			side.push(cube[9][i]);
		}

		for (int i = 6; i < 9; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				body.push(cube[i][j]);
			}
		}

		//회전
		for (int i = 3; i < 9; i++)
		{
			cube[5][i] = side.front();
			side.pop();
		}
		for (int i = 5; i >= 3; i--)
		{
			cube[9][i] = side.front();
			side.pop();
		}
		for (int i = 0; i < 3; i++)
		{
			cube[5][i] = side.front();
			side.pop();
		}

		for (int i = 5; i >= 3; i--)
		{
			for (int j = 6; j <9; j++)
			{
				cube[j][i] = body.front();
				body.pop();
			}
		}
		return;
	}

}
