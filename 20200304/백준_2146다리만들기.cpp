#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

struct info { int x, y, num; };
int N;
int Map[110][110];
bool visit[110][110];
bool visit2[110][110];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int MMin = 987654321;
int check[110][110] = { 0 };
queue<info> Now;

queue<info>Q;

void find_all(info cur);
void DFS(int x, int y, int num);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	int cnt = 1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Map[i][j] == 1 && !visit[i][j]) {
				visit[i][j] = true;
				Map[i][j] = cnt;
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
					if (Map[nx][ny] == 0 && !visit2[i][j])
					{
						visit2[i][j] = true;
						Q.push({ i,j,cnt });
					}
				}
				DFS(i, j, cnt);
				cnt++;
			}
		}
	}


	while (!Q.empty())
	{
		find_all(Q.front());
		Q.pop();
	}

	cout << MMin << endl;

	return 0;
}

void DFS(int x, int y, int num)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
		if (!visit[nx][ny] && Map[nx][ny] == 1)
		{
			Map[nx][ny] = num;
			visit[nx][ny] = true;
			for (int k = 0; k < 4; k++)
			{
				int nnx = nx + dx[k];
				int nny = ny + dy[k];
				if (nnx < 0 || nny < 0 || nnx >= N || nny >= N)continue;
				if (Map[nnx][nny] == 0 && !visit2[nx][ny]) {
					visit2[nx][ny] = true;
					Q.push({ nx,ny,num });
				}
			}
			DFS(nx, ny, num);
		}
	}
}

void find_all(info cur)
{
	memset(check, -1, sizeof(check));

	Now.push(cur);
	check[cur.x][cur.y] = 0;

	while (!Now.empty())
	{
		int curx = Now.front().x;
		int cury = Now.front().y;
		int cnum = Now.front().num;
		Now.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = curx + dx[i];
			int ny = cury + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
			if (Map[nx][ny] == 0 && check[nx][ny] == -1)
			{
				check[nx][ny] = check[curx][cury] + 1;
				Now.push({ nx,ny,cnum });
			}
			if (Map[nx][ny] != 0 && Map[nx][ny] != cnum)
			{
				MMin = min(MMin, check[curx][cury]);
			}
		}
	}

	while (!Now.empty())
	{
		Now.pop();
	}

}
