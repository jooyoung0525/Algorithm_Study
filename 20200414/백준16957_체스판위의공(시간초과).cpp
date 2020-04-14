#include<iostream>
#include<queue>

using namespace std;

struct info { int x, y, num; };
int R, C;
int Map[550][550];
int Result[550][550];
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };
bool Stop[550][550];

bool check();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> Map[i][j];
			Result[i][j] = 1;
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			int cnt = 0;

			for (int k = 0; k < 8; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 0 || ny < 0 || nx >= R || ny >= C)continue;

				if (Map[i][j] > Map[nx][ny])
				{
					cnt++;
				}
			}
			if (cnt == 0) Stop[i][j] = true;
		}
	}

	while (1) {

		if (check())break;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (Result[i][j] > 0 && !Stop[i][j]) {

					int MMin = 555555;
					int Mx = i; int My = j;
					for (int k = 0; k < 8; k++)
					{
						int nx = i + dx[k];
						int ny = j + dy[k];

						if (nx < 0 || ny < 0 || nx >= R || ny >= C)continue;

						if (Map[i][j] > Map[nx][ny])
						{
							if (MMin > Map[nx][ny]) {
								MMin = Map[nx][ny];
								Mx = nx; My = ny;
							}
						}
					}
					Result[Mx][My] += Result[i][j];
					Result[i][j] =0;
				}
			}
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << Result[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}


bool check()
{
	int result = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (Stop[i][j])
				result += Result[i][j];
		}
	}

	if (result == R * C) return true;
	return false;
}
