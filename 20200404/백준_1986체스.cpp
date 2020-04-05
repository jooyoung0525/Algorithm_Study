#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

struct info { int x, y; };

int map[1100][1100];
int n, m;
int Q, K, P;
int Qdx[] = { -1,0,1,0,-1,1,1,-1 };
int Qdy[] = {0,1,0,-1,1,1,-1,-1};
int dx[] = { -2,-1,1,2,2,1,-1,-2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };

vector<info>Que;
vector<info>Kn;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int x = 0; int y = 0;
		cin >> x >> y;
		Que.push_back({ x,y });
		map[x][y] = 2;
	}

	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int x = 0; int y = 0;
		cin >> x >> y;
		Kn.push_back({ x,y });
		map[x][y] = 2;
	}

	cin >> P;
	for (int i = 0; i < P; i++)
	{
		int x = 0; int y = 0;
		cin >> x >> y;
		map[x][y] = 2;
	}

	for (int i = 0; i < Kn.size(); i++)
	{
		int x = Kn[i].x;
		int y = Kn[i].y;

		int dx[] = { -2,-1,1,2,2,1,-1,-2 };
		int dy[] = { 1,2,2,1,-1,-2,-2,-1 };

		for (int a = 0; a < 8; a++)
		{
			int nx = x + dx[a];
			int ny = y + dy[a];

			if (nx<1 || ny<1 || nx>n || ny>m)continue;
			if (map[nx][ny] == 2)continue;
			map[nx][ny] = 1;
		}
	}
	
	for (int i = 0; i < Que.size(); i++)
	{
		int cx = Que[i].x;
		int cy = Que[i].y;

		for (int a = 0; a < 8; a++) {

			int nx = cx+Qdx[a];
			int ny = cy+Qdy[a];

			while (map[nx][ny] == 0 || map[nx][ny] == 1)
			{
				if (nx<1 || ny<1 || nx>n || ny>m)break;
				map[nx][ny] = 1;
				nx += Qdx[a];
				ny += Qdy[a];
			}
		}
	}
	
	int result = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] == 0) result++;
		}
	}
	
	cout << result << endl;

	


	return 0;
}
