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
-------------------------------------------------------------------------------------------------------------------
# 두번째 시도
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
int hap;

queue<pair<int,int>> Q;

void BFS(int curx, int cury, int M, int N )
{
	int nx, ny;
	
	Q.push(make_pair(curx, cury));
	visited[curx][cury] = 1;
	hap = 1;

	while (!Q.empty()) {
		
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		
		for (int i = 0; i < 4; i++)
		{
				nx = x + dx[i];
				ny = y + dy[i];

			if (nx <= -1 || nx > M || ny <= -1 || ny > N)
				continue;


			if (visited[nx][ny] == 0) //방문하지 않았을때
			{
				Q.push(make_pair(nx, ny));
				visited[nx][ny] = 1;
				hap += visited[nx][ny];

				if (box[x][y] = 1) //익은토마토발견하면
				{
					box[nx][ny] = 1; //동서남북 토마토 익음
					cnt++; //주변토마토익을때마다 카운트
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

	while (hap != (N*M)) {
		BFS(0, 0, M, N); // 전체다방문했을때..?토마토가 다익을때까지 반복.....(원래의도)
	}

	printf("%d", cnt);

	system("pause");
	return 0;
}
```
