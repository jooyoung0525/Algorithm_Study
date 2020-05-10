// 1. cx+Min할때 R의범위를 넘어갈 경우 생각해야함


// 1. cx+Min할때 R의범위를 넘어갈 경우 생각해야함


#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

struct info { int x, y; };
int R, C, N;
int Throw[110];
char Map[110][110];
bool check[110][110];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<info>IDX;



void Left(int floor);
void Right(int floor);
void Down();
bool Can_down();
void gravity();
void DFS(int x, int y);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> Map[i][j];
		}
	}
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> Throw[i];
	}

	for (int i = 1; i <= N; i++)
	{
		

		if (i % 2 != 0)
		{
			Left(R-Throw[i]+1);
		}
		else
		{
			Right(R-Throw[i]+1);
		}
		
		Down();
	}

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cout << Map[i][j];
		}
		cout << "\n";
	}

	return 0;
}


void Left(int floor)
{
	for (int i = 1; i <= C; i++)
	{
		if (Map[floor][i] == 'x')
		{
			Map[floor][i] = '.';
			break;
		}
	}
}

void Right(int floor)
{
	for (int i = C; i >= 1; i--)
	{
		if (Map[floor][i] == 'x')
		{
			Map[floor][i] = '.';
			break;
		}
	}
}

void Down()
{
	if (Can_down())
	{
		gravity();
	}
	return;
}

bool Can_down()
{
	memset(check, false, sizeof(check));

	for (int i = 1; i <= C; i++)
	{
		if (Map[R][i] == 'x' && !check[R][i])
		{
			check[R][i] = true;
			DFS(R, i);
		}
	}

	IDX.clear();
	bool flag = false;

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (Map[i][j] == 'x' && !check[i][j])
			{
				Map[i][j] = '.';
				flag = true;
				IDX.push_back({ i,j });
			}
		}
	}

	return flag;
}


void gravity()
{
	int Min = 987654321;

	for (int i = 0; i < IDX.size(); i++)
	{
		int cx = IDX[i].x;
		int cy = IDX[i].y;
		
		int cnt = 0;
		while (Map[cx+1][cy] == '.' && cx <= R)
		{
			cnt++;
			cx += 1;
		}
		Min = min(Min, cnt);
	}
	
	for (int i = 0; i < IDX.size(); i++)
	{
		if (IDX[i].x + Min > R)return;	//다음위치가 범위를 넘어갈경우 리턴
	}

	for (int i = 0; i < IDX.size(); i++)
	{
		
		int cx = IDX[i].x;
		int cy = IDX[i].y;
		
		Map[cx + Min][cy] = 'x';
	}

}

void DFS(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<1 || ny<1 || nx>R || ny>C)continue;
		if (Map[nx][ny] == 'x' && !check[nx][ny])
		{
			check[nx][ny] = true;
			DFS(nx, ny);
		}
	}
}
