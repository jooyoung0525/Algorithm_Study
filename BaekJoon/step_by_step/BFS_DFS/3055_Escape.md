![탈출](https://user-images.githubusercontent.com/29946480/62696149-1cdf9500-b9d8-11e9-97ca-f1f63d434ad3.PNG)
-----------------------------------------------------------------------------------------------------------------
### 고려해야 할 상황들

- 물이 먼저 다음칸에 도착했는지 고슴도치가 먼저 도착했는지 (다음칸에 물이 채워지면 고슴도치 이동불가)
- 시작할 때, map에 물이 여러군데 차있을 수도 있음.
- 물이 없는경우도 고려
-----------------------------------------------------------------------------------------------------------------
```c
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<iostream>

using namespace std;

int R, C;
char map[55][55];
int wx, wy, curx, cury, rx, ry;
int water[55][55] = { -1, };
int visit[55][55] = { -1, };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

queue<pair<int, int>>wQ,Q;

void w_BFS()
{
	
	while (!wQ.empty())
	{
		int cwx = wQ.front().first;
		int cwy = wQ.front().second;
		wQ.pop();

		for(int i = 0; i < 4; i++)
		{
			int nwx = cwx + dx[i];
			int nwy = cwy + dy[i];

			if (nwx < 0 || nwx >= C || nwy < 0 || nwy >= R)continue;
			if (map[nwx][nwy] == '.' && water[nwx][nwy] == -1)
			{
				water[nwx][nwy] = water[cwx][cwy] + 1;
				wQ.push({ nwx,nwy });
			}
		}
	}
}

void BFS()
{
	
	while (!Q.empty())
	{
		int cx = Q.front().first;
		int cy = Q.front().second;
		
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= C || ny < 0 || ny >= R)continue;

			
			if (map[nx][ny] == '.' && visit[nx][ny] == -1 && (visit[cx][cy] + 1 < water[nx][ny] || water[nx][ny] == -1))
			{

				visit[nx][ny] = visit[cx][cy] + 1;
				Q.push({ nx,ny });
				
			}
			
		}
	}
}

int main()
{
	cin >> C >> R;
	for (int i = 0; i < C; i++)
	{
		for (int j = 0; j < R; j++)
			cin >> map[i][j];
	}

	for (int i = 0; i < C; i++)
	{
		for (int j = 0; j < R; j++)
		{
			water[i][j] = -1;
			visit[i][j] = -1;
			if (map[i][j] == '*')
			{
				wx = i;
				wy = j;
				wQ.push({ wx,wy }); // *가 여러 개일 때
				water[wx][wy] = 0;
			}
			if (map[i][j] == 'S')
			{
				curx = i;
				cury = j;
				map[i][j] = '.';
				Q.push({ curx,cury });
				visit[curx][cury] = 0;
			}
			if (map[i][j] == 'D')
			{
				rx = i;
				ry = j;
				map[i][j] = '.';
				water[i][j] = 3000;
			}

		}
	}

	w_BFS();

	BFS();
	/*
	for (int i = 0; i < C; i++)
	{
		for (int j = 0; j < R; j++)
		{
			printf("%5d", water [i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < C; i++)
	{
		for (int j = 0; j < R; j++)
		{
			printf("%5d", visit[i][j]);
		}
		printf("\n");
	}
	*/
	if (visit[rx][ry] != -1)
		printf("%d", visit[rx][ry]);
	else
		printf("KAKTUS");

	system("pause");
	return 0;
}
```
