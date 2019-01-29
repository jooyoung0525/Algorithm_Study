```c
#include<cstdio>
#include<cstdlib>
#include<queue>

using namespace std;

int box[1000][1000];
int visited[1000][1000];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int cnt = 0;

queue<pair<int,int>> Q;

void BFS(int curx, int cury, int M, int N )
{
	int nx, ny;
	//int cnt;

	Q.push(make_pair(curx, cury));
	visited[curx][cury] = 1;

	while (!Q.empty()) {
		
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		if (box[x][y] == 1) {
			for (int i = 0; i < 4; i++)
			{
				nx = curx + dx[i];
				ny = cury + dy[i];

				if (nx > -1 || nx < M || ny > -1 || ny < N)
				{
					if (box[nx][ny] == 0 && visited[nx][ny] == 0)
					{
						Q.push(make_pair(nx,ny));
						box[nx][ny] = 1;
						cnt++;
					}

					else
						continue;
				}


			}
		}

	}

	return;

}

int main()
{
	int M, N;
	scanf("%d %d", &M, &N);

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			scanf("%d ", &box[i][j]);

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] != 1)
				BFS(0, 0, M, N);
		}
	}

	printf("%d", cnt);

	system("pause");
	return 0;
}
```
