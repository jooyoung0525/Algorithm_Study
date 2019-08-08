-----------------------------------------------------------------------------------------------------
```c
#include<cstdio>
#include<cstdlib>
#include<deque>
using namespace std;

int map[101][101] = { 0 };
int visit[101][101] = { 0 };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

deque<pair<pair<int, int>,int>> Q;

int BFS(int N, int M)
{
	int min = 100000;
	visit[0][0] = 1;
	Q.push_back({ {0,0},0 });

	while (!Q.empty())
	{
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int wall = Q.front().second;
				
		if (x == N - 1 && y == M - 1)
		{
			return wall;
		}
			

		Q.pop_front();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
			if (visit[nx][ny] == 0) {
				if (map[nx][ny] == 0) {
					visit[nx][ny] = 1;
					Q.push_front({ {nx,ny},wall });
				}
				else {
					Q.push_back({ {nx,ny},wall+1 });
					visit[nx][ny] =  1;
				}
			}
		}

	}

}

int main()
{
	int N, M;

	scanf("%d %d", &M, &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	
	printf("%d", BFS(N, M));

	return 0;
}
```
