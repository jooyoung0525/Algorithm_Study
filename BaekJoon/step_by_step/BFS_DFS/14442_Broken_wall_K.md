
---------------------------------------------------------------------------------------
### ↓↓↓ 시간초과... 아무래도 구조체 사용법을 배워서 이용해야할듯!
--------------------------------------------------------------------------------------

```c
#include<cstdio>
#include<cstdlib>
#include<queue>

using namespace std;

queue <pair<pair<int, int>,int>> Q;

int map[1000][1000];
int visit[1000][1000][9];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int N, M;

int BFS(int K) {

	visit[0][0][K] = 1;
	Q.push(make_pair(make_pair(0, 0), K));

	while (!Q.empty())
	{
		int X = Q.front().first.first;
		int Y = Q.front().first.second;
		int canbroken = Q.front().second;
		Q.pop();

		if (X == N - 1 && Y == M - 1)
			return visit[N-1][M-1][canbroken];

		for (int i = 0; i < 4; i++)
		{
			int nx = X + dx[i];
			int ny = Y + dy[i];

			if (nx<0 || ny<0 || nx > N - 1 || ny > M - 1)continue;
			if (map[nx][ny] == 0 && visit[nx][ny][canbroken] == 0)
			{
				Q.push(make_pair(make_pair(nx, ny),canbroken));
				visit[nx][ny][canbroken] = visit[X][Y][canbroken] + 1;
			}
			if (map[nx][ny] == 1 && canbroken > 0)
			{
				
				Q.push(make_pair(make_pair(nx, ny), canbroken-1));
				visit[nx][ny][canbroken-1] = visit[X][Y][canbroken] + 1;
			}
		}

	}
	return -1;
}

int main()
{
	int i, j, K;

	scanf("%d %d %d", &N, &M, &K);
	

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	

	int result = BFS(K);

	
	printf("%d",result);

	system("pause");
	return 0;
}
```
