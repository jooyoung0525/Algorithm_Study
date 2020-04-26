#include<iostream>
#include<cstring>

using namespace std;

int N;
int House[50][50];
long long memo[50][50][5];
int dx[] = {0,1,1};
int dy[] = { 1,1,0 }; //0:가로 1:대각선 2:세로

long long DFS(int x, int y, int dir);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> House[i][j];
		}
	}

	memset(memo, -1, sizeof(memo));

	long long result = DFS(1, 2, 0);

	cout << result;
	return 0;
}


long long DFS(int x, int y, int dir)
{
	if (memo[x][y][dir] != -1)return memo[x][y][dir];
	if (x == N  && y == N )return 1;


	memo[x][y][dir] = 0;

	if (dir == 0)
	{
		int nx = x + dx[0];
		int ny = y + dy[0];
		if (nx >= 1 && ny >= 1 && nx <= N && ny <= N && House[nx][ny] ==0)
		{
			memo[x][y][dir] += DFS(nx, ny, dir);
		}


		nx = x + dx[1];
		ny = y + dy[1];
		if (nx >= 1 && ny >= 1 && nx <= N && ny <= N && House[nx][ny] == 0 && House[x+dx[0]][y+dy[0]] == 0 && House[x+dx[2]][y+dy[2]] == 0)
		{
			memo[x][y][dir] += DFS(nx, ny, 1);
		}
	}

	else if (dir == 1)
	{
		int nx = x + dx[0];
		int ny = y + dy[0];
		if (nx >= 1 && ny >= 1 && nx <= N && ny <= N && House[nx][ny] == 0)
		{
			memo[x][y][dir] += DFS(nx, ny, 0);
		}

		nx = x + dx[1];
		ny = y + dy[1];
		if (nx >= 1 && ny >= 1 && nx <= N && ny <= N && House[nx][ny] == 0 && House[x + dx[0]][y + dy[0]] == 0 && House[x + dx[2]][y + dy[2]] == 0)
		{
			memo[x][y][dir] += DFS(nx, ny, 1);
		}

		nx = x + dx[2];
		ny = y + dy[2];
		if (nx >= 1 && ny >= 1 && nx <= N && ny <= N && House[nx][ny] == 0)
		{
			memo[x][y][dir] += DFS(nx, ny, 2);
		}
	}

	else if (dir == 2)
	{
		int nx = x + dx[1];
		int ny = y + dy[1];
		if (nx >= 1 && ny >= 1 && nx <= N && ny <= N && House[nx][ny] == 0 && House[x + dx[0]][y + dy[0]] == 0 && House[x + dx[2]][y + dy[2]] == 0)
		{
			memo[x][y][dir] += DFS(nx, ny, 1);
		}


		nx = x + dx[2];
		ny = y + dy[2];
		if (nx >= 1 && ny >= 1 && nx <= N && ny <= N && House[nx][ny] == 0)
		{
			memo[x][y][dir] += DFS(nx, ny, 2);
		}


	}

	return memo[x][y][dir];

}
