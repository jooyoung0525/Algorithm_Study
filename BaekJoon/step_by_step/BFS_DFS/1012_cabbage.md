# DFS 이용 (단지번호와 유사한문제)

### ↓↓↓ 행과 열이 헷갈린다..... ↓↓↓

![kakaotalk_20190207_193018725](https://user-images.githubusercontent.com/29946480/52405622-0763de00-2b0f-11e9-95de-edbc9e61a9a9.jpg)
![kakaotalk_20190207_193018896](https://user-images.githubusercontent.com/29946480/52405623-0763de00-2b0f-11e9-8912-9214947d6fde.jpg)

--------------------------------------------------------------------------------------------------------------

![asdf](https://user-images.githubusercontent.com/29946480/52404797-38dbaa00-2b0d-11e9-888a-22d65876437c.JPG)

-------------------------------------------------------------------------------------------------------------
```c
#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

int bat[100][100];
int visited[100][100];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int num;
int ans[1000];

void DFS(int curx, int cury, int N, int M)
{
	visited[curx][cury] = 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = curx + dx[i];
		int ny = cury + dy[i];

		if (nx <= -1 || nx >= N || ny <= -1 || ny >= M) continue;

		if (visited[nx][ny] == 0 && bat[nx][ny] == 1)
			DFS(nx, ny, N, M);

	}

}

int main()
{
	int T, N, M, K;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		
		cin >> N >> M >> K;
		num = 0;

		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				bat[j][k] = 0;
				visited[j][k] = 0;
			}
		}

		

		for (int t = 0; t < K; t++)
		{
			int a, b;
			scanf("%d %d", &a, &b);

			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < M; k++)
				{
					bat[a][b] = 1;
				}
			}

		}

		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (bat[j][k] == 1 && visited[j][k] == 0)
				{
					
					DFS(j, k, N, M);
					num++;
					ans[i] = num;
				}
			}
		}

		


	}

	for (int i = 0; i < T; i++)
	{
		printf("%d\n", ans[i]);
	}


	return 0;
}
```
