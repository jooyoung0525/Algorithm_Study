# 맞았쥬~>_<

![tomato3](https://user-images.githubusercontent.com/29946480/52342257-3f5c1a00-2a58-11e9-87f2-ffeea3754ee7.JPG)

---------------------------------------------------------------------------------------------------------------------


```c
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<iostream>
#include<algorithm>

using namespace std;

int tomato_box[110][110][110];
int visited[110][110][110];
int dx[] = { -1,1,0,0,0,0 };
int dy[] = { 0,0,-1,1,0,0 };
int dz[] = { 0,0,0,0,-1,1 };

queue<pair<pair<int,int>,int>> q;

int cMAX(int N, int M, int H)
{
	int MAX[100][100];
	int MAX1[100];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			MAX[i][j] = *max_element(visited[i][j], visited[i][j] + H);
		}
	}

	for (int i = 0; i < N; i++)
	{
		MAX1[i] = *max_element(MAX[i], MAX[i] + M);
	}

	int MAX2 = *max_element(MAX1, MAX1 + N);

	return MAX2-1;
}

int calculate(int N,int M,int H)
{
	
	int count = 0;
	

	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (tomato_box[i][j][k] == 0)
					count++;
				if (visited[i][j][k] == 0)
					return -1;

			}
		}
	}

	if (count == 0)
		return 0;
	else
		return cMAX(N, M, H);

}


void BFS(int N,int M, int H)
{
	

	while (!q.empty())
	{
		int curx = q.front().first.first;
		int cury = q.front().first.second;
		int curz = q.front().second;
		q.pop();

		for (int i = 0; i < 6; i++)   //※3차원이니까 6이어야함!!
		{
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			int nz = curz + dz[i];

			
			if (nx <= -1 || nx >= N || ny <= -1 || ny >= M || nz <= -1 || nz >= H) continue;

			if (tomato_box[nx][ny][nz] == 0 && visited[nx][ny][nz] == 0)
			{
				q.push(make_pair(make_pair(nx, ny), nz));
				visited[nx][ny][nz] = 1;
				visited[nx][ny][nz] = visited[curx][cury][curz] + 1;
			}


		}

	}


}

int main()
{

	int N,M,H;
	cin >> M >> N >> H; //행,열 헷갈리지않기!!!!!

	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> tomato_box[i][j][k];
			}
		}
	}

	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (tomato_box[i][j][k] == 1 && visited[i][j][k] == 0)
				{
					q.push(make_pair(make_pair(i, j), k));
					visited[i][j][k] = 1;
					
				}
				else if (tomato_box[i][j][k] == -1 && visited[i][j][k] == 0)
					visited[i][j][k] = -1;
			}
		}
	}

	BFS(N,M,H);
	
	/* 검증
	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				printf("%d",visited[i][j][k]);
			}
			printf("\n");
		}
	}

	printf("\n");
	*/
	
	printf("%d", calculate(N, M, H));


	return 0;
}

```
