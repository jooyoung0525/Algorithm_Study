#include<iostream>
#include<cstring>

using namespace std;


int N, M, hap;
int Map[550][550];
int check[550][550];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int DFS(int x, int y, int n);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			char a;
			cin >> a;
			if (a == 'U') Map[i][j] = 0;
			else if (a == 'R') Map[i][j] = 1;
			else if (a == 'D') Map[i][j] = 2;
			else if (a == 'L') Map[i][j] = 3;
		}
	}

	memset(check, -1, sizeof(check));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			hap += DFS(i, j, Map[i][j]);
		}
	}

	cout << hap << endl;

	return 0;
}


int DFS(int x, int y, int n)
{
	if (check[x][y]!= -1) return check[x][y];
	if (x == 0 || y == 0 || x == N + 1 || y == M + 1) return 1;

	check[x][y]= 0;

	if (n == 0)
	{
		int nx = x + dx[0];
		int ny = y + dy[0];
		if (nx >= 0 && ny >= 0 && nx <= N + 1 && ny <= M + 1)
		{
			check[x][y] += DFS(nx, ny, Map[nx][ny]);
		}
	}
	else if (n == 1)
	{
		int nx = x + dx[1];
		int ny = y + dy[1];
		if (nx >= 0 && ny >= 0 && nx <= N + 1 && ny <= M + 1)
		{
			check[x][y]+= DFS(nx, ny, Map[nx][ny]);
		}
	}
	else if (n == 2)
	{
		int nx = x + dx[2];
		int ny = y + dy[2];
		if (nx >= 0 && ny >= 0 && nx <= N + 1 && ny <= M + 1)
		{
			check[x][y]+= DFS(nx, ny, Map[nx][ny]);
		}
	}
	else if (n == 3)
	{
		int nx = x + dx[3];
		int ny = y + dy[3];
		if (nx >= 0 && ny >= 0 && nx <= N + 1 && ny <= M + 1)
		{
			check[x][y]+= DFS(nx, ny, Map[nx][ny]);
		}
	}
	return check[x][y];
}
